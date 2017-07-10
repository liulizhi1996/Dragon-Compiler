%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include "compiler.h"

extern int LineNo; /*当前lookahead所指向的字符所在的行号，即当前编译到的行号*/

extern int CompileFailed;

void yyerror( char * ErrStr )
{
    CompileFailed = 1; /*编译失败标志*/
    printf("错误信息：%s，行号：%d\n", ErrStr, LineNo);
}

extern SymbolList TopSymbolList; /*全局变量，存放当前的符号表（即当前处于最顶层的符号表），对应为书上的top*/

extern struct ConstList ConstList;  /*常量表，全局变量，注意整个程序只需要一个常量表*/

extern struct QuadTable quadTable; /*只需要一个四元式表*/

extern int nextinstr;	/*下一条四元式的标号*/

%}
/**************************** 上面：定义句法分析栈中元素的信息，即终结符和非终结符的综合属性 ****************************/

%union {
	union {
		struct idNode *id; /*标识符:终结符ID的综合属性*/
	
		struct constvalNode *constval; /*终结符const的综合属性*/
	
		struct basicNode *basic; /*基本数据类型：终结符BASIC的综合属性*/
	
		struct nonterminalNode *factor, *unary, *term, *expr, *rel, *equality, *join, *bool; /*非终结符factor, unary, term, expr, rel, equality, join, bool的综合属性*/
		struct declarationNode *stmts, *stmt, *block, *BoolN; /*非终结符stmts, stmt, block, BoolN的综合属性*/
		struct boolMNode *BoolM; /*非终结符BoolM的综合属性*/
	} a;
}

%token <a> BASIC
%token <a> CONST
%token <a> ID

%type <a> type factor unary term expr rel equality join bool stmts stmt block BoolN BoolM

%token IF
%token DO
%token WHILE

%right ASSIGN					/* = */
%left OR						/* || */
%left AND						/* && */
%left EQ NE						/* == != */
%left LESS LE GREAT GE			/* < <= > >= */
%left ADD SUB					/* + - */
%left MUL DIV					/* * / */
%left NOT						/* ! */
%nonassoc UMINUS				/* - */
%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE

%%
program: block BoolM		{ printf("program -> block\n"); 
							  backpatch($1.block->nextlist, $2.BoolM->instr);
							  Gen(OHalt, 0, 0, 0, "", "", "");
							}
;

block: '{' blockM1 decls stmts blockM2 '}'
							{ printf("block -> { decl stmts }\n"); 
							  $$.block = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  $$.block->nextlist = $4.stmts->nextlist;
							}
;

blockM1: /* epsilon */		{ TopSymbolList = CreateSymbolList( TopSymbolList, TopSymbolList->endaddr ); }
;

blockM2: /* epsilon */		{ SymbolList env;
							  PrintSymbolList( TopSymbolList); 
							  env = TopSymbolList->prev;
							  DestroySymbolList( TopSymbolList ); 
							  TopSymbolList = env;                 
							}
;

decls: decls decl			{ printf("decls -> decls decl\n"); }
	 | /* epsilon */		{ printf("decls -> ε\n"); }
;

decl: type ID ';'			{ int width;
							  printf("decl -> type id ;\n"); 
							  switch( $1.basic->type )
							  {
								  case CHAR  : width = CHAR_WIDTH;  break;
								  case INT   : width = INT_WIDTH;   break;
								  case FLOAT : width = FLOAT_WIDTH; break;
								  case BOOL  : width = BOOL_WIDTH;  break;
								  default    : width = -1; break;
							  }
							  AddToSymbolList( TopSymbolList, $2.id->name, $1.basic->type, width );
							}
;

type: BASIC					{ $$.basic = (struct basicNode *)malloc(sizeof(struct basicNode)); 
							  printf("type -> basic\n");
							  $$.basic->type = $1.basic->type;
							}
;

stmts: stmts BoolM stmt		{ printf("stmts -> stmts stmt\n"); 
							  $$.stmts = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  backpatch($1.stmts->nextlist, $2.BoolM->instr);
							  $$.stmts->nextlist = $3.stmt->nextlist;
							}
	 | stmt					{ printf("stmts -> stmt\n"); 
	 						  $$.stmts = (struct declarationNode *)malloc(sizeof(struct declarationNode));
	 						  $$.stmts->nextlist = $1.stmt->nextlist;
	 						}
;

stmt: ID ASSIGN expr ';'	{ printf("stmt -> id = expr ;\n");
							  $$.stmt = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  $$.stmt->nextlist = NULL;
							  struct SymbolElem * p;
							  p = LookUpAllSymbolList( TopSymbolList, $1.id->name );
							  if( p != NULL )
							  {
							  	  if (p->type == $3.expr->type)
								  {
								  	  switch (p->type)
								  	  {
								  	  	  case BOOL	: Gen(OBoolEvaluation , $3.expr->addr, 0, p->addr, $3.expr->str, "",  p->name); break;
								  	  	  case CHAR	: Gen(OCharEvaluation , $3.expr->addr, 0, p->addr, $3.expr->str, "",  p->name); break;
								  	  	  case INT	: Gen(OIntEvaluation , $3.expr->addr, 0, p->addr, $3.expr->str, "",  p->name); break;
								  	  	  case FLOAT: Gen(OFloatEvaluation , $3.expr->addr, 0, p->addr, $3.expr->str, "",  p->name); break;
								  	  	  default: yyerror("非法类型");
								  	  }
								  }
								  else
								  {
								  	  struct nonterminalNode Temp;
								  	  if (p->type == BOOL)
								  	  {
								  	  	  Temp.type = BOOL;
								  	  	  Temp.width = BOOL_WIDTH;
								  	  	  Temp.addr = NewTemp(TopSymbolList, Temp.str, Temp.width);
								  	  	  switch ($3.expr->type)
								  	  	  {
								  	  	  	  case CHAR	: Gen(OCharToBool, $3.expr->addr, 0, Temp.addr, $3.expr->str, "", Temp.str); break;
								  	  	  	  case INT	: Gen(OIntToBool, $3.expr->addr, 0, Temp.addr, $3.expr->str, "", Temp.str); break;
								  	  	  	  case FLOAT: Gen(OFloatToBool, $3.expr->addr, 0, Temp.addr, $3.expr->str, "", Temp.str); break;
								  	  	  	  default: yyerror("非法类型");
								  	  	  }
								  	  }
								  	  else if (p->type == CHAR)
								  	  {
								  	  	  Temp.type = CHAR;
								  	  	  Temp.width = CHAR_WIDTH;
								  	  	  Temp.addr = NewTemp(TopSymbolList, Temp.str, Temp.width);
								  	  	  switch ($3.expr->type)
								  	  	  {
								  	  	  	  case BOOL	: Gen(OBoolToChar, $3.expr->addr, 0, Temp.addr, $3.expr->str, "", Temp.str); break;
								  	  	  	  case INT	: Gen(OIntToChar, $3.expr->addr, 0, Temp.addr, $3.expr->str, "", Temp.str); break;
								  	  	  	  case FLOAT: Gen(OFloatToChar, $3.expr->addr, 0, Temp.addr, $3.expr->str, "", Temp.str); break;
								  	  	  	  default: yyerror("非法类型");
								  	  	  }
								  	  }
								  	  else if (p->type == INT)
								  	  {
								  	  	  Temp.type = INT;
								  	  	  Temp.width = INT_WIDTH;
								  	  	  Temp.addr = NewTemp(TopSymbolList, Temp.str, Temp.width);
								  	  	  switch ($3.expr->type)
								  	  	  {
								  	  	  	  case BOOL	: Gen(OBoolToInt, $3.expr->addr, 0, Temp.addr, $3.expr->str, "", Temp.str); break;
								  	  	  	  case CHAR	: Gen(OCharToInt, $3.expr->addr, 0, Temp.addr, $3.expr->str, "", Temp.str); break;
								  	  	  	  case FLOAT: Gen(OFloatToInt, $3.expr->addr, 0, Temp.addr, $3.expr->str, "", Temp.str); break;
								  	  	  	  default: yyerror("非法类型");
								  	  	  }
								  	  }
								  	  else if (p->type == FLOAT)
								  	  {
								  	  	  Temp.type = FLOAT;
								  	  	  Temp.width = FLOAT_WIDTH;
								  	  	  Temp.addr = NewTemp(TopSymbolList, Temp.str, Temp.width);
								  	  	  switch ($3.expr->type)
								  	  	  {
								  	  	  	  case BOOL	: Gen(OBoolToFloat, $3.expr->addr, 0, Temp.addr, $3.expr->str, "", Temp.str); break;
								  	  	  	  case CHAR	: Gen(OCharToFloat, $3.expr->addr, 0, Temp.addr, $3.expr->str, "", Temp.str); break;
								  	  	  	  case INT	: Gen(OIntToFloat, $3.expr->addr, 0, Temp.addr, $3.expr->str, "", Temp.str); break;
								  	  	  	  default: yyerror("非法类型");
								  	  	  }
								  	  }
								  	  else
								  	  	  yyerror("非法类型");
									  switch (p->type)
									  {
									  	  case BOOL	: Gen(OBoolEvaluation , Temp.addr, 0, p->addr, Temp.str, "",  p->name); break;
									  	  case CHAR	: Gen(OCharEvaluation , Temp.addr, 0, p->addr, Temp.str, "",  p->name); break;
									  	  case INT	: Gen(OIntEvaluation , Temp.addr, 0, p->addr, Temp.str, "",  p->name); break;
									  	  case FLOAT: Gen(OFloatEvaluation , Temp.addr, 0, p->addr, Temp.str, "",  p->name); break;
									  	  default: yyerror("非法类型");
									  }
								  }
							  }							    
							  else
							  {
								  yyerror( "变量名没有定义" );														    
							  } 
							}
	| IF '(' bool ')' BoolM stmt %prec LOWER_THEN_ELSE
							{ printf("stmt -> if ( bool ) stmt\n");
							  $$.stmt = (struct declarationNode *)malloc(sizeof(struct declarationNode)); 
							  backpatch($3.bool->truelist, $5.BoolM->instr);
							  $$.stmt->nextlist = merge($3.bool->falselist, $6.stmt->nextlist);
							}
	| IF '(' bool ')' BoolM stmt ELSE BoolN BoolM stmt
							{ printf("stmt -> if ( bool ) stmt else stmt\n"); 
							  $$.stmt = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  backpatch($3.bool->truelist, $5.BoolM->instr);
							  backpatch($3.bool->falselist, $9.BoolM->instr);
							  struct BoolList *temp;
							  temp = merge($6.stmt->nextlist, $8.BoolN->nextlist);
							  $$.stmt->nextlist = merge(temp, $10.stmt->nextlist);
							  
							}
	| WHILE BoolM '(' bool ')' BoolM stmt
							{ printf("stmt -> while ( bool ) stmt\n"); 
							  $$.stmt = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  backpatch($7.stmt->nextlist, $2.BoolM->instr);
							  backpatch($4.bool->truelist, $6.BoolM->instr);
							  $$.stmt->nextlist = $4.bool->falselist;
							  Gen(OGoto, 0, 0, $2.BoolM->instr, "", "", "");
							}
	| DO BoolM stmt WHILE BoolM '(' bool ')' ';'
							{ printf("stmt -> do stmt while ( bool ) ;\n"); 
							  $$.stmt = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  backpatch($3.stmt->nextlist, $5.BoolM->instr);
							  backpatch($7.bool->truelist, $2.BoolM->instr);
							  $$.stmt->nextlist = $7.bool->falselist;
							}
	| block					{ printf("stmt -> block\n"); 
							  $$.stmt = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  $$.stmt->nextlist = $1.block->nextlist;
							}
;

BoolN: /* epsilon */		{ $$.BoolN = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  $$.BoolN->nextlist = makelist(nextinstr);
							  Gen(OGoto, 0, 0, 0, "", "", "");
							}
;

bool: bool OR BoolM join	{ printf("bool -> bool || join\n"); 
							  $$.bool = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( $$.bool->str, "");
							  $$.bool->type = 0;
							  $$.bool->addr = 0;
							  $$.bool->width = 0;
							  backpatch($1.bool->falselist, $3.BoolM->instr);
							  $$.bool->truelist = merge($1.bool->truelist, $4.join->truelist);
							  $$.bool->falselist = $4.join->falselist;
							}
	| join					{ printf("bool -> join\n"); 
							  $$.bool = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( $$.bool->str, $1.join->str );
   							  $$.bool->type = $1.join->type;
   							  $$.bool->addr = $1.join->addr;
   							  $$.bool->width = $1.join->width;
   							  $$.bool->truelist = $1.join->truelist;
   							  $$.bool->falselist = $1.join->falselist;
							}
;

join: join AND BoolM equality
							{ printf("join -> join && equality\n"); 
							  $$.join = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( $$.join->str, "" );
							  $$.join->type = 0;
							  $$.join->addr = 0;
							  $$.join->width = 0;
							  backpatch($1.join->truelist, $3.BoolM->instr);
							  $$.join->truelist = $4.equality->truelist;
							  $$.join->falselist = merge($1.join->falselist, $4.equality->falselist);
							}
	| equality				{ printf("join -> equality\n"); 
							  $$.join = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( $$.join->str, $1.equality->str );
   							  $$.join->type = $1.equality->type;
   							  $$.join->addr = $1.equality->addr;
   							  $$.join->width = $1.equality->width;
   							  $$.join->truelist = $1.equality->truelist;
   							  $$.join->falselist = $1.equality->falselist;
							}
;

BoolM: /* epsilon */		{ $$.BoolM = (struct boolMNode *)malloc(sizeof(struct boolMNode));
							  $$.BoolM->instr = nextinstr;
							}
;

equality: equality EQ rel	{ printf("equality -> equality == rel\n"); 
							  $$.equality = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( $$.equality->str, "" );
   							  $$.equality->type = 0;
   							  $$.equality->addr = 0;
   							  $$.equality->width = 0;
   							  $$.equality->truelist = makelist(nextinstr);
   							  $$.equality->falselist = makelist(nextinstr + 1);
   							  Gen(OEQGoto, $1.equality->addr, $3.rel->addr, 0, $1.equality->str, $3.rel->str, "");
   							  Gen(OGoto, 0, 0, 0, "", "", "");
							}
		| equality NE rel	{ printf("equality -> equality != rel\n"); 
							  $$.equality = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( $$.equality->str, "" );
   							  $$.equality->type = 0;
   							  $$.equality->addr = 0;
   							  $$.equality->width = 0;
   							  $$.equality->truelist = makelist(nextinstr);
   							  $$.equality->falselist = makelist(nextinstr + 1);
   							  Gen(ONEQGoto, $1.equality->addr, $3.rel->addr, 0, $1.equality->str, $3.rel->str, "");
   							  Gen(OGoto, 0, 0, 0, "", "", "");
							}
		| rel				{ printf("equality -> rel\n");
							  $$.equality = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( $$.equality->str, $1.rel->str );
   							  $$.equality->type = $1.rel->type;
   							  $$.equality->addr = $1.rel->addr;
   							  $$.equality->width = $1.rel->width;
   							  $$.equality->truelist = $1.rel->truelist;
   							  $$.equality->falselist = $1.rel->falselist;
							}
;

rel: expr LESS expr			{ printf("rel -> expr < expr\n"); 
							  $$.rel = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( $$.rel->str, "");
							  $$.rel->type = 0;
							  $$.rel->addr = 0;
							  $$.rel->width = 0;
							  $$.rel->truelist = makelist(nextinstr);
							  $$.rel->falselist = makelist(nextinstr + 1);
							  Gen(OLTGoto, $1.expr->addr, $3.expr->addr, 0, $1.expr->str, $3.expr->str, "");
							  Gen(OGoto, 0, 0, 0, "", "", "");
							}
   | expr LE expr			{ printf("rel -> expr <= expr\n"); 
   							  $$.rel = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( $$.rel->str, "");
							  $$.rel->type = 0;
							  $$.rel->addr = 0;
							  $$.rel->width = 0;
							  $$.rel->truelist = makelist(nextinstr);
							  $$.rel->falselist = makelist(nextinstr + 1);
							  Gen(OLEGoto, $1.expr->addr, $3.expr->addr, 0, $1.expr->str, $3.expr->str, "");
							  Gen(OGoto, 0, 0, 0, "", "", "");
   							}
   | expr GE expr			{ printf("rel -> expr >= expr\n"); 
   							  $$.rel = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( $$.rel->str, "");
							  $$.rel->type = 0;
							  $$.rel->addr = 0;
							  $$.rel->width = 0;
							  $$.rel->truelist = makelist(nextinstr);
							  $$.rel->falselist = makelist(nextinstr + 1);
							  Gen(OGEGoto, $1.expr->addr, $3.expr->addr, 0, $1.expr->str, $3.expr->str, "");
							  Gen(OGoto, 0, 0, 0, "", "", "");
   							}
   | expr GREAT expr		{ printf("rel -> expr > expr\n"); 
   							  $$.rel = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( $$.rel->str, "");
							  $$.rel->type = 0;
							  $$.rel->addr = 0;
							  $$.rel->width = 0;
							  $$.rel->truelist = makelist(nextinstr);
							  $$.rel->falselist = makelist(nextinstr + 1);
							  Gen(OGTGoto, $1.expr->addr, $3.expr->addr, 0, $1.expr->str, $3.expr->str, "");
							  Gen(OGoto, 0, 0, 0, "", "", "");
   							}
   | expr					{ printf("rel -> expr\n");
   							  $$.rel = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
   							  strcpy( $$.rel->str, $1.expr->str );
   							  $$.rel->type = $1.expr->type;
   							  $$.rel->addr = $1.expr->addr;
   							  $$.rel->width = $1.expr->width;
   							  $$.rel->truelist = NULL;
   							  $$.rel->falselist = NULL;
   							}
;

expr: expr ADD term			{ $$.expr = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  printf("expr -> expr + term\n");
							  $$.expr->type = maxType($1.expr->type, $3.term->type);
							  $$.expr->addr = NewTemp(TopSymbolList, $$.expr->str, $$.expr->type);
							  $$.expr->truelist = NULL;
							  $$.expr->falselist = NULL;
							  switch ($$.expr->type)
							  {
							  	  case BOOL : $$.expr->width = BOOL_WIDTH; break;
							  	  case CHAR : $$.expr->width = CHAR_WIDTH; break;
							  	  case INT  : $$.expr->width = INT_WIDTH; break;
							  	  case FLOAT: $$.expr->width = FLOAT_WIDTH; break;
							  }
							  if ($1.expr->type == $3.term->type)
							  {
							  	  if ($1.expr->type == INT)
							  	  	  Gen(OIntAdd, $1.expr->addr, $3.term->addr, $$.expr->addr, $1.expr->str, $3.term->str, $$.expr->str); 
							  	  else if ($1.expr->type == FLOAT)
							  	  	  Gen(OFloatAdd, $1.expr->addr, $3.term->addr, $$.expr->addr, $1.expr->str, $3.term->str, $$.expr->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else if ($1.expr->type > $3.term->type)
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType($3.term->addr, $3.term->type, $3.term->str, $1.expr->type, &Temp, TopSymbolList);
							  	  if ($1.expr->type == INT)
							  	  	  Gen(OIntAdd, $1.expr->addr, Temp.addr, $$.expr->addr, $1.expr->str, Temp.str, $$.expr->str);
							  	  else if ($1.expr->type == FLOAT)
							  	  	  Gen(OFloatAdd, $1.expr->addr, Temp.addr, $$.expr->addr, $1.expr->str, Temp.str, $$.expr->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType($1.expr->addr, $1.expr->type, $1.expr->str, $3.term->type, &Temp, TopSymbolList);
							  	  if ($3.term->type == INT)
							  	  	  Gen(OIntAdd, Temp.addr, $3.term->addr, $$.expr->addr, Temp.str, $3.term->str, $$.expr->str);
							  	  else if ($3.term->type == FLOAT)
							  	  	  Gen(OFloatAdd, Temp.addr, $3.term->addr, $$.expr->addr, Temp.str, $3.term->str, $$.expr->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							}
	| expr SUB term			{ $$.expr = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  printf("expr -> expr + term\n");
							  $$.expr->type = maxType($1.expr->type, $3.term->type);
							  $$.expr->addr = NewTemp(TopSymbolList, $$.expr->str, $$.expr->type);
							  $$.expr->truelist = NULL;
							  $$.expr->falselist = NULL;
							  switch ($$.expr->type)
							  {
							  	  case BOOL : $$.expr->width = BOOL_WIDTH; break;
							  	  case CHAR : $$.expr->width = CHAR_WIDTH; break;
							  	  case INT  : $$.expr->width = INT_WIDTH; break;
							  	  case FLOAT: $$.expr->width = FLOAT_WIDTH; break;
							  }
							  if ($1.expr->type == $3.term->type)
							  {
							  	  if ($1.expr->type == INT)
							  	  	  Gen(OIntSub, $1.expr->addr, $3.term->addr, $$.expr->addr, $1.expr->str, $3.term->str, $$.expr->str); 
							  	  else if ($1.expr->type == FLOAT)
							  	  	  Gen(OFloatSub, $1.expr->addr, $3.term->addr, $$.expr->addr, $1.expr->str, $3.term->str, $$.expr->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else if ($1.expr->type > $3.term->type)
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType($3.term->addr, $3.term->type, $3.term->str, $1.expr->type, &Temp, TopSymbolList);
							  	  if ($1.expr->type == INT)
							  	  	  Gen(OIntSub, $1.expr->addr, Temp.addr, $$.expr->addr, $1.expr->str, Temp.str, $$.expr->str);
							  	  else if ($1.expr->type == FLOAT)
							  	  	  Gen(OFloatSub, $1.expr->addr, Temp.addr, $$.expr->addr, $1.expr->str, Temp.str, $$.expr->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType($1.expr->addr, $1.expr->type, $1.expr->str, $3.term->type, &Temp, TopSymbolList);
							  	  if ($3.term->type == INT)
							  	  	  Gen(OIntSub, Temp.addr, $3.term->addr, $$.expr->addr, Temp.str, $3.term->str, $$.expr->str);
							  	  else if ($3.term->type == FLOAT)
							  	  	  Gen(OFloatSub, Temp.addr, $3.term->addr, $$.expr->addr, Temp.str, $3.term->str, $$.expr->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							}
	| term					{ $$.expr = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  printf("expr -> term\n");
							  strcpy( $$.expr->str, $1.term->str );
							  $$.expr->type = $1.term->type;
							  $$.expr->addr = $1.term->addr;
							  $$.expr->width = $1.term->width; 
							  $$.expr->truelist = $1.term->truelist;
							  $$.expr->falselist = $1.term->falselist;
							}
;

term: term MUL unary		{ printf("term -> term * unary\n");
							  $$.term = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  $$.term->type = maxType($1.term->type, $3.unary->type);
							  $$.term->addr = NewTemp(TopSymbolList, $$.term->str, $$.term->type);
							  $$.term->truelist = NULL;
							  $$.term->falselist = NULL;
							  switch ($$.term->type)
							  {
							  	  case BOOL : $$.term->width = BOOL_WIDTH; break;
							  	  case CHAR : $$.term->width = CHAR_WIDTH; break;
							  	  case INT  : $$.term->width = INT_WIDTH; break;
							  	  case FLOAT: $$.term->width = FLOAT_WIDTH; break;
							  }
							  if ($1.term->type == $3.unary->type)
							  {
							  	  if ($1.term->type == INT)
							  	  	  Gen(OIntMultiply, $1.term->addr, $3.unary->addr, $$.term->addr, $1.term->str, $3.unary->str, $$.term->str); 
							  	  else if ($1.expr->type == FLOAT)
							  	  	  Gen(OFloatMultiply, $1.term->addr, $3.unary->addr, $$.term->addr, $1.term->str, $3.unary->str, $$.term->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else if ($1.term->type > $3.unary->type)
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType($3.unary->addr, $3.unary->type, $3.unary->str, $1.term->type, &Temp, TopSymbolList);
							  	  if ($1.term->type == INT)
							  	  	  Gen(OIntMultiply, $1.term->addr, Temp.addr, $$.term->addr, $1.term->str, Temp.str, $$.term->str);
							  	  else if ($1.term->type == FLOAT)
							  	  	  Gen(OFloatMultiply, $1.term->addr, Temp.addr, $$.term->addr, $1.term->str, Temp.str, $$.term->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType($1.term->addr, $1.term->type, $1.term->str, $3.unary->type, &Temp, TopSymbolList);
							  	  if ($3.unary->type == INT)
							  	  	  Gen(OIntMultiply, Temp.addr, $3.unary->addr, $$.term->addr, Temp.str, $3.unary->str, $$.term->str);
							  	  else if ($3.unary->type == FLOAT)
							  	  	  Gen(OFloatMultiply, Temp.addr, $3.unary->addr, $$.term->addr, Temp.str, $3.unary->str, $$.term->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							}
	| term DIV unary		{ printf("term -> term / unary\n");
							  $$.term = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  $$.term->type = maxType($1.term->type, $3.unary->type);
							  $$.term->addr = NewTemp(TopSymbolList, $$.term->str, $$.term->type);
							  $$.term->truelist = NULL;
							  $$.term->falselist = NULL;
							  switch ($$.term->type)
							  {
							  	  case BOOL : $$.term->width = BOOL_WIDTH; break;
							  	  case CHAR : $$.term->width = CHAR_WIDTH; break;
							  	  case INT  : $$.term->width = INT_WIDTH; break;
							  	  case FLOAT: $$.term->width = FLOAT_WIDTH; break;
							  }
							  if ($1.term->type == $3.unary->type)
							  {
							  	  if ($1.term->type == INT)
							  	  	  Gen(OIntDivide, $1.term->addr, $3.unary->addr, $$.term->addr, $1.term->str, $3.unary->str, $$.term->str); 
							  	  else if ($1.expr->type == FLOAT)
							  	  	  Gen(OFloatDivide, $1.term->addr, $3.unary->addr, $$.term->addr, $1.term->str, $3.unary->str, $$.term->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else if ($1.term->type > $3.unary->type)
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType($3.unary->addr, $3.unary->type, $3.unary->str, $1.term->type, &Temp, TopSymbolList);
							  	  if ($1.term->type == INT)
							  	  	  Gen(OIntDivide, $1.term->addr, Temp.addr, $$.term->addr, $1.term->str, Temp.str, $$.term->str);
							  	  else if ($1.term->type == FLOAT)
							  	  	  Gen(OFloatDivide, $1.term->addr, Temp.addr, $$.term->addr, $1.term->str, Temp.str, $$.term->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType($1.term->addr, $1.term->type, $1.term->str, $3.unary->type, &Temp, TopSymbolList);
							  	  if ($3.unary->type == INT)
							  	  	  Gen(OIntDivide, Temp.addr, $3.unary->addr, $$.term->addr, Temp.str, $3.unary->str, $$.term->str);
							  	  else if ($3.unary->type == FLOAT)
							  	  	  Gen(OFloatDivide, Temp.addr, $3.unary->addr, $$.term->addr, Temp.str, $3.unary->str, $$.term->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							}
	| unary					{ $$.term = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  printf("term -> unary\n"); 
							  strcpy( $$.term->str, $1.unary->str );
							  $$.term->type = $1.unary->type;
							  $$.term->addr = $1.unary->addr;
							  $$.term->width = $1.unary->width;
							  $$.term->truelist = $1.unary->truelist;
							  $$.term->falselist = $1.unary->falselist;
							}
;

unary: NOT unary			{ printf("unary -> ! unary\n"); 
							  $$.unary = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( $$.unary->str, $2.unary->str);
							  $$.unary->type = $2.unary->type;
							  $$.unary->addr = $2.unary->addr;
							  $$.unary->width = $2.unary->width;
							  $$.unary->truelist = $2.unary->falselist;
							  $$.unary->falselist = $2.unary->truelist;
							}
	 | SUB unary %prec UMINUS
	 						{ printf("unary -> - unary\n");
	 						  $$.unary = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
	 						  $$.unary->type = $2.unary->type;
	 						  $$.unary->width = $2.unary->width;
	 						  $$.unary->addr = NewTemp(TopSymbolList, $$.unary->str, $$.unary->width);
	 						  $$.unary->truelist = NULL;
	 						  $$.unary->falselist = NULL;
	 						  if ($2.unary->type == INT)
	 						  	  Gen(OIntUminus, $2.unary->addr, 0, $$.unary->addr, $2.unary->str, "", $$.unary->str);
	 						  else if ($2.unary->type == FLOAT)
	 						  	  Gen(OFloatUminus, $2.unary->addr, 0, $$.unary->addr, $2.unary->str, "", $$.unary->str);
	 						  else
	 						  	  yyerror("非整型或浮点型运算");
	 						}
	 | factor				{ $$.unary = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
	 						  printf("unary -> factor\n");
	 						  strcpy( $$.unary->str, $1.factor->str );
							  $$.unary->type = $1.factor->type;
							  $$.unary->addr = $1.factor->addr;
							  $$.unary->width = $1.factor->width;
							  $$.unary->truelist = $1.factor->truelist;
							  $$.unary->falselist = $1.factor->falselist;
							}
;

factor: '(' expr ')'		{ $$.factor = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  printf("factor -> ( expr )\n"); 
							  strcpy( $$.factor->str, $2.expr->str );
							  $$.factor->type  = $2.expr->type;
							  $$.factor->addr  = $2.expr->addr;
							  $$.factor->width = $2.expr->width;
							  $$.factor->truelist = $2.expr->truelist;
							  $$.factor->falselist = $2.expr->falselist;
							}
	  | ID					{ $$.factor = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
	  						  $$.factor->truelist = NULL;
	  						  $$.factor->falselist = NULL;
	  						  printf("factor -> id\n"); 
	  						  struct SymbolElem * p;
							  p = LookUpAllSymbolList( TopSymbolList, $1.id->name );
							  if( p != NULL )
							  {
								  strcpy( $$.factor->str, p->name );
								  $$.factor->type  = p->type;
								  $$.factor->addr  = p->addr;
								  $$.factor->width = p->width;
							  }							    
							  else
							  {
							      yyerror( "变量名没有定义" );
								  strcpy( $$.factor->str, "no_id_defined" ); /*容错处理*/
								  $$.factor->type = INT;
								  $$.factor->addr = -1;
								  $$.factor->width = INT_WIDTH;							    
							  }
							}
	  | CONST				{ $$.factor = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
	  						  $$.factor->truelist = NULL;
	  						  $$.factor->falselist = NULL;
	  						  printf("factor -> const\n");
	  						  struct ConstElem * p; 
							  p = LookUpConstList( $1.constval->type, $1.constval->value, $1.constval->width ) ;
							  if( p == NULL )
								  p = AddToConstList( $1.constval->str, $1.constval->type, $1.constval->value, $1.constval->width );
							  strcpy( $$.factor->str, $1.constval->str );
							  $$.factor->type  = $1.constval->type;
							  $$.factor->addr  = p->addr;
							  $$.factor->width = p->width;
							}
;

%%

