#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include "compiler.h"

/**************************** 下面：符号表的定义和相关函数 ****************************/
/* 创建并返回一个新的符号表（SymbolList就是书上的Env），PrevList是其的上一层符号表 */
SymbolList CreateSymbolList( SymbolList PrevList, int StartAddr )
{
	SymbolList list;
    list = (SymbolList) malloc( sizeof(struct SymbolList) );
    memset( list, 0, sizeof( struct SymbolList ) );
    list->prev = PrevList;
	list->endaddr = list->beginaddr = StartAddr;

    return list;
}

/* 销毁符号表 */
void DestroySymbolList( SymbolList List )
{
	struct SymbolElem * p, *q;
    
    if( List == NULL)
		return;
    p = List->head;
    while( p!=NULL )
    {
        q = p->next; 
        free(p);
        p = q;
    }
    free(List);    
}

/* 在符号表List中查找是否存在标识符IdName，如果存在，则返回该结点指针，否则返回空 */
struct SymbolElem * LookUpSymbolList( SymbolList List, char * IdName )
{
	struct SymbolElem * p;
    if( List==NULL )
    	return NULL;
    for( p = List->head; p!=NULL; p = p->next ) 
        if( strcmp( p->name, IdName ) == 0 )
        	break;
    return p;
}

/* 从符号表List开始并不断地往上一层符号表中查找是否存在标识符IdName，如果存在，则返回该结点指针，否则返回空 */
struct SymbolElem * LookUpAllSymbolList( SymbolList List, char * IdName )
{
	SymbolList env;
	struct SymbolElem * p;
    env = List;
    while( env!=NULL )
    {
        p = LookUpSymbolList( env, IdName );
        if( p != NULL )
        	return p; /*找到该符号*/
        env = env->prev;
    }
    return NULL;
}

/* 创建一个新的符号结点,并添加到符号表中，而后返回该结点指针 */
struct SymbolElem * AddToSymbolList( SymbolList List, char * IdName, int IdType, int Width )
{
	struct SymbolElem * p;

    p = (struct SymbolElem *) malloc( sizeof(struct SymbolElem) );

    strcpy( p->name, IdName );
    p->type = IdType;
	p->width = Width;
	p->addr = List->endaddr;
	List->endaddr += Width;

    p->next = List->head;  /*将该标识符添加到符号表表头*/
    List->head = p;

    return p;    
}

/* 输出符号表 */
void PrintSymbolList( SymbolList List )
{
	struct SymbolElem * p;
    printf("***********************变量列表*************************\n");
    if( List == NULL )
    	return;
    for( p=List->head; p!=NULL; p=p->next ) 
    {
        printf("变量名:%s, 类型:", p->name);
		switch( p->type )
		{
            case CHAR : printf("char");  break;
            case INT  : printf("int");   break;
            case FLOAT: printf("float"); break;
            case BOOL : printf("bool");  break;
		}
        printf(", 地址:%d, 宽度:%d\n", p->addr, p->width );
	}
    printf("*************该变量列表共占用%d个字节空间***************\n", List->endaddr - List->beginaddr);
}

/*分配一个临时变量,返回临时变量的地址、临时变量的名称*/
int NewTemp( SymbolList List, char Name[], int Width )
{
	static int TempID = 1;
	int addr;
    sprintf( Name, "T%d", TempID++ ); /*例如T1，T2等*/
	addr = List->endaddr;
    List->endaddr += Width;
  
    return addr;
}
/**************************** 上面：符号表的定义和相关函数 ****************************/

/**************************** 下面：常数表的定义和相关函数 ****************************/
/* 创建并返回常量表 */
void CreateConstList( int StartAddr )
{ 
	ConstList.head = NULL;
	ConstList.endaddr = ConstList.beginaddr = StartAddr;
}

/* 销毁常量表 */
void DestroyConstList( void )
{
	struct ConstElem * p, *q;
    
    p = ConstList.head;
    while( p!=NULL )
    {
        q = p->next;
        free(p); 
        p=q;
    }
	memset( &ConstList, 0, sizeof(struct ConstList) );
}

/* 在常量表ConstList中查找是否存在常量，如果存在，则返回该结点指针，否则返回空 */
struct ConstElem * LookUpConstList( int ConstType, union ConstVal ConstValue, int Width )
{
	struct ConstElem * p;
    for( p = ConstList.head; p!=NULL; p = p->next ) 
        if( p->type == ConstType && memcmp( &p->value,&ConstValue, Width) == 0 )
        	break;
	
    return p;
}

/* 创建一个新的常数结点,并添加到常数表中，而后返回该结点指针 */
struct ConstElem * AddToConstList( char * Str, int ConstType, union ConstVal ConstValue, int Width )
{
	struct ConstElem * p;

    p = (struct ConstElem *) malloc( sizeof(struct ConstElem) );

    strcpy( p->str, Str );
    p->type = ConstType;
    p->value = ConstValue;
    p->width = Width;

    p->addr = ConstList.endaddr;
    ConstList.endaddr += Width;

    p->next = ConstList.head;  /*将该常量添加到常量表表头*/
    ConstList.head = p;

    return p;    
}

/* 输出常量表 */
void PrintConstList(void)
{
	struct ConstElem * p;
    printf("***********************常量列表*************************\n");
    for( p=ConstList.head; p!=NULL; p=p->next ) 
    {
	    printf("常量:%s, 类型:", p->str);
		switch( p->type ) 
		{
            case CHAR : printf("char");  break;
            case INT  : printf("int");   break;
            case FLOAT: printf("float"); break;
            case BOOL : printf("bool");  break;
		}
        printf(", 地址:%d, 宽度:%d\n", p->addr, p->width );
	}
    printf("**************该常量列表共占用%d个字节空间***************\n", ConstList.endaddr - ConstList.beginaddr);
}
/**************************** 上面：常数表的定义和相关函数 ****************************/

/**************************** 下面：四元式的定义和函数 ****************************/
void CreateQuadTable(int StartAddr)
{
    quadTable.startaddr = StartAddr; 
    quadTable.size = 1000; /* 一开始假设可以存放1000个四元式*/
    quadTable.base = ( struct Quadruple *)malloc( quadTable.size * sizeof(struct Quadruple) );
    quadTable.len = 0;
    nextinstr = 100;
}

void DestroyQuadTable( void )
{
    quadTable.startaddr = 0; 
    quadTable.size = 0;
    if( quadTable.base != NULL)
    	free(quadTable.base); 
    quadTable.len = 0;   
}

/* 当Arg1是变量或临时变量时，Arg1Name是该变量的名称,用于演示时使用，其余参数类同 */
int Gen( int Op, int Arg1, int Arg2, int Arg3, char *Arg1Name, char *Arg2Name, char *Arg3Name )
{
	struct Quadruple * ptr; 
	int incr = 100;
    if( quadTable.len >= quadTable.size ) 
    {
        ptr = realloc( quadTable.base, quadTable.size+incr );
        if( ptr==NULL )
        	return -1;
        quadTable.base = ptr;
        quadTable.size += incr;
    }
    ptr = & quadTable.base[quadTable.len];
    ptr->op = Op;
    ptr->arg1 = Arg1;
    ptr->arg2 = Arg2;
    ptr->arg3 = Arg3;
    strcpy( ptr->arg1name, Arg1Name);
    strcpy( ptr->arg2name, Arg2Name);
    strcpy( ptr->arg3name, Arg3Name);
    quadTable.len++;
    nextinstr++;

    return quadTable.len - 1;
}

/* 把四元式所对应的三地址代码写入到文件中 */
void WriteQuadTableToFile( const char * FileName )
{
	FILE * fp;
	struct Quadruple * ptr;
	int i,op;
	char str[1000], ch;
    fp = fopen( FileName, "w" );
    if( fp==NULL )
    	return;
    for( i=0, ptr = quadTable.base; i < quadTable.len; i++,ptr++ )
    {
		fprintf(fp, "%5d:  ", quadTable.startaddr + i);
        op = ptr->op;
        switch( op ) 
        {
            case OIntAdd        :
            case OIntSub        :
            case OIntMultiply   :
            case OIntDivide     :
            case OFloatAdd      :
            case OFloatSub      :
            case OFloatMultiply :
            case OFloatDivide   : if( op==OIntAdd || op==OFloatAdd) ch = '+';
                                  if( op==OIntSub || op==OFloatSub) ch = '-';
                                  if( op==OIntMultiply || op==OFloatMultiply) ch = '*';
                                  if( op==OIntDivide || op==OFloatDivide) ch = '/';
                                  sprintf(str,"[%d] = [%d] %c [%d]", ptr->arg3, ptr->arg1, ch, ptr->arg2);
                                  break;
            case OIntUminus		:
            case OFloatUminus	: sprintf(str, "[%d] = minus [%d]", ptr->arg3, ptr->arg1); break;
            case OIntEvaluation   :
            case OFloatEvaluation :
            case OCharEvaluation  :
            case OBoolEvaluation  : sprintf(str,"[%d] = [%d]", ptr->arg3, ptr->arg1);
                                    break;
            case OGoto            : sprintf(str,"Goto %d", ptr->arg3);
                                    break;
            case OGTGoto  : sprintf(str,"if [%d]>[%d] Goto %d", ptr->arg1, ptr->arg2, ptr->arg3 );  break;
            case OGEGoto  : sprintf(str,"if [%d]>=[%d] Goto %d", ptr->arg1, ptr->arg2, ptr->arg3 ); break;
            case OLTGoto  : sprintf(str,"if [%d]<[%d] Goto %d", ptr->arg1, ptr->arg2, ptr->arg3 );  break;
            case OLEGoto  : sprintf(str,"if [%d]<=[%d] Goto %d", ptr->arg1, ptr->arg2, ptr->arg3 ); break;
            case OEQGoto  : sprintf(str,"if [%d]==[%d] Goto %d", ptr->arg1, ptr->arg2, ptr->arg3 ); break;
            case ONEQGoto : sprintf(str,"if [%d]!=[%d] Goto %d", ptr->arg1, ptr->arg2, ptr->arg3 ); break;

            case OCharToInt   : sprintf( str,"[%d] = (int) [%d]",   ptr->arg3, ptr->arg1 );  break;
            case OCharToFloat : sprintf( str,"[%d] = (float) [%d]", ptr->arg3, ptr->arg1 );  break;
            case OIntToFloat  : sprintf( str,"[%d] = (float) [%d]", ptr->arg3, ptr->arg1 );  break;
            case OIntToChar   : sprintf( str,"[%d] = (char) [%d]",  ptr->arg3, ptr->arg1 );  break;
            case OFloatToChar : sprintf( str,"[%d] = (char) [%d]",  ptr->arg3, ptr->arg1 );  break;
            case OFloatToInt  : sprintf( str,"[%d] = (int) [%d]",   ptr->arg3, ptr->arg1 );  break;

            case OCharToBool   : sprintf( str,"[%d] = (bool) [%d]",  ptr->arg3, ptr->arg1 );  break;
            case OIntToBool    : sprintf( str,"[%d] = (bool) [%d]",  ptr->arg3, ptr->arg1 );  break;
            case OFloatToBool  : sprintf( str,"[%d] = (bool) [%d]",  ptr->arg3, ptr->arg1 );  break;
            case OBoolToChar   : sprintf( str,"[%d] = (char) [%d]",  ptr->arg3, ptr->arg1 );  break;
            case OBoolToInt    : sprintf( str,"[%d] = (int) [%d]",   ptr->arg3, ptr->arg1 );  break;
            case OBoolToFloat  : sprintf( str,"[%d] = (float) [%d]", ptr->arg3, ptr->arg1 );  break;
            
            case OHalt		   : sprintf( str,"halt" );  break;

            default: yyerror("程序错误：出现不认识的运算符！"); strcpy(str, "error: Unknown operator");break;
        }
        fprintf(fp,"%s\n",str);
    }

    fclose(fp);
}

/* 把四元式所对应的三地址代码显示在屏幕上 */
void PrintQuadTable( void )
{
	struct Quadruple * ptr;
	int i,op;
	char str[1000], ch;
    printf("***********************中间代码*************************\n");
    for( i=0, ptr = quadTable.base; i < quadTable.len; i++,ptr++ )
    {
		printf("%5d:  ", quadTable.startaddr + i);
        op = ptr->op;
        switch( op ) 
        {
            case OIntAdd        :
            case OIntSub        :
            case OIntMultiply   :
            case OIntDivide     :
            case OFloatAdd      :
            case OFloatSub      :
            case OFloatMultiply :
            case OFloatDivide   : if( op==OIntAdd || op==OFloatAdd) ch = '+';
                                  if( op==OIntSub || op==OFloatSub) ch = '-';
                                  if( op==OIntMultiply || op==OFloatMultiply) ch = '*';
                                  if( op==OIntDivide || op==OFloatDivide) ch = '/';
                                  sprintf(str,"%s = %s %c %s", ptr->arg3name, ptr->arg1name, ch, ptr->arg2name);
                                  break;
            case OIntUminus		:
            case OFloatUminus	: sprintf(str, "%s = minus %s", ptr->arg3name, ptr->arg1name); break;
            case OIntEvaluation   :
            case OFloatEvaluation :
            case OCharEvaluation  :
            case OBoolEvaluation  : sprintf(str,"%s = %s", ptr->arg3name, ptr->arg1name);
                                    break;
            case OGoto            : sprintf(str,"Goto %d", ptr->arg3);
                                    break;
            case OGTGoto  : sprintf(str,"if %s>%s Goto %d", ptr->arg1name, ptr->arg2name, ptr->arg3 );  break;
            case OGEGoto  : sprintf(str,"if %s>=%s Goto %d", ptr->arg1name, ptr->arg2name, ptr->arg3 ); break;
            case OLTGoto  : sprintf(str,"if %s<%s Goto %d", ptr->arg1name, ptr->arg2name, ptr->arg3 );  break;
            case OLEGoto  : sprintf(str,"if %s<=%s Goto %d", ptr->arg1name, ptr->arg2name, ptr->arg3 ); break;
            case OEQGoto  : sprintf(str,"if %s==%s Goto %d", ptr->arg1name, ptr->arg2name, ptr->arg3 ); break;
            case ONEQGoto : sprintf(str,"if %s!=%s Goto %d", ptr->arg1name, ptr->arg2name, ptr->arg3 ); break;

            case OCharToInt   : sprintf( str,"%s = (int) %s",   ptr->arg3name, ptr->arg1name );  break;
            case OCharToFloat : sprintf( str,"%s = (float) %s", ptr->arg3name, ptr->arg1name );  break;
            case OIntToFloat  : sprintf( str,"%s = (float) %s", ptr->arg3name, ptr->arg1name );  break;
            case OIntToChar   : sprintf( str,"%s = (char) %s",  ptr->arg3name, ptr->arg1name );  break;
            case OFloatToChar : sprintf( str,"%s = (char) %s",  ptr->arg3name, ptr->arg1name );  break;
            case OFloatToInt  : sprintf( str,"%s = (int) %s",   ptr->arg3name, ptr->arg1name );  break;

            case OCharToBool   : sprintf( str,"%s = (bool) %s",  ptr->arg3name, ptr->arg1name );  break;
            case OIntToBool    : sprintf( str,"%s = (bool) %s",  ptr->arg3name, ptr->arg1name );  break;
            case OFloatToBool  : sprintf( str,"%s = (bool) %s",  ptr->arg3name, ptr->arg1name );  break;
            case OBoolToChar   : sprintf( str,"%s = (char) %s",  ptr->arg3name, ptr->arg1name );  break;
            case OBoolToInt    : sprintf( str,"%s = (int) %s",   ptr->arg3name, ptr->arg1name );  break;
            case OBoolToFloat  : sprintf( str,"%s = (float) %s", ptr->arg3name, ptr->arg1name );  break;
            
            case OHalt		   : sprintf( str,"halt" );  break;

            default: yyerror("程序错误：出现不认识的运算符！"); strcpy(str, "error: Unknown operator");break;
        }
        printf("%s\n",str);
    }
    printf("******************共生成%d条中间代码*********************\n", quadTable.len);
}
/**************************** 上面：四元式的定义和函数 ****************************/

/**************************** 下面：定义句法分析栈中元素的信息，即终结符和非终结符的综合属性 ****************************/
/**************************** 上面：定义句法分析栈中元素的信息，即终结符和非终结符的综合属性 ****************************/

/**************************** 下面：强制类型转换处理 ****************************/
/* 拓宽类型转换示意图 */
/* float  ...4
     |
    int   ...3
     |
    char  ...2
     |
    bool  ...1
*/

/* 返回type1和type2在拓宽层次结构中的最大者 */
int maxType(int type1, int type2)
{
	return ( type1 > type2 ? type1 : type2 );
}

/* 将类型为Type、变量名为name的地址Addr中的内容转换成WideType类型的值，并产生类型转换代码，Temp为生成的临时变量 */
void widenType(int Addr, int Type, char name[], int WideType, struct nonterminalNode *Temp, SymbolList List)
{
	if (Type == WideType)
		return;
	else
	{
		switch (WideType)
		{
			case BOOL: Temp->width = BOOL_WIDTH; break;
			case CHAR: Temp->width = CHAR_WIDTH; break;
			case INT:  Temp->width = INT_WIDTH; break;
			case FLOAT:Temp->width = FLOAT_WIDTH; break;
			default: yyerror("程序错误：出现不认识的类型！"); break;
		}
		Temp->type = WideType;
		Temp->addr = NewTemp(List, Temp->str, Temp->width);
		
		int op;
		if (Type == BOOL)
		{
			switch (WideType)
			{
				case CHAR:	op = OBoolToChar; break;
				case INT:	op = OBoolToInt; break;
				case FLOAT:	op = OBoolToFloat; break;
				default: yyerror("程序错误：强制类型转换出错！"); break;
			}
		}
		else if (Type == CHAR)
		{
			switch (WideType)
			{
				case INT: 	op = OCharToInt; break;
				case FLOAT:	op = OCharToFloat; break;
				default: yyerror("程序错误：强制类型转换出错！"); break;
			}
		}
		else if (Type == INT)
		{
			if (WideType == FLOAT)
				op = OIntToFloat;
			else
				yyerror("程序错误：强制类型转换出错！");
		}
		Gen(op, Addr, 0, Temp->addr, name, "", Temp->str);
	}
}

/**************************** 上面：强制类型转换处理 ****************************/

/**************************** 下面：回填列表的定义与处理函数 ****************************/
/* 创建一个只包含instr的列表，返回一个指向新创建列表的指针 */
struct BoolList *makelist(int instr)
{
	struct BoolList *p = (struct BoolList *)malloc(sizeof(struct BoolList));
	p->instrNo = instr;
	p->next = NULL;
	return p;
}

/* 将p1和p2指向的列表进行合并，返回指向合并后列表的指针 */
struct BoolList *merge(struct BoolList *p1, struct BoolList *p2)
{
	struct BoolList *q, *q1, *q2, *q0, *temp;
	q1 = p1; q2 = p2;
	
	if (!p1 && !p2)
		return NULL;
		
	q = (struct BoolList *)malloc(sizeof(struct BoolList));
	if (q1 && q2)
	{
		if (q1->instrNo <= q2->instrNo)
		{
			q->instrNo = q1->instrNo;
			q1 = q1->next;
			q->next = NULL;
			q0 = q;
		}
		else
		{
			q->instrNo = q2->instrNo;
			q2 = q2->next;
			q->next = NULL;
			q0 = q;
		}
	}
	else if (q1)
	{
		q->instrNo = q1->instrNo;
		q1 = q1->next;
		q->next = NULL;
		q0 = q;
	}
	else if (q2)
	{
		q->instrNo = q2->instrNo;
		q2 = q2->next;
		q->next = NULL;
		q0 = q;
	}
	while (q1 && q2)
	{
		if (q1->instrNo <= q2->instrNo)
		{
			temp = (struct BoolList *)malloc(sizeof(struct BoolList));
			temp->instrNo = q1->instrNo;
			temp->next = NULL;
			q0->next = temp;
			q0 = temp;
			q1 = q1->next;
		}
		else
		{
			temp = (struct BoolList *)malloc(sizeof(struct BoolList));
			temp->instrNo = q2->instrNo;
			temp->next = NULL;
			q0->next = temp;
			q0 = temp;
			q2 = q2->next;
		}
	}
	while (q1)
	{
		temp = (struct BoolList *)malloc(sizeof(struct BoolList));
		temp->instrNo = q1->instrNo;
		temp->next = NULL;
		q0->next = temp;
		q0 = temp;
		q1 = q1->next;
	}
	while (q2)
	{
		temp = (struct BoolList *)malloc(sizeof(struct BoolList));
		temp->instrNo = q2->instrNo;
		temp->next = NULL;
		q0->next = temp;
		q0 = temp;
		q2 = q2->next;
	}
	return q;
}

/* 将instr作为目标标号插入到p所指向列表的各指令中 */
void backpatch(struct BoolList *p, int instr)
{
	struct BoolList *p0 = p;
	struct Quadruple *quadptr;
	int instrno;
	while (p0)
	{
		instrno = p0->instrNo;
		quadptr = &quadTable.base[instrno - quadTable.startaddr];
		switch (quadptr->op)
		{
			case OGoto:
			case OGTGoto:
			case OGEGoto:
			case OLTGoto:
			case OLEGoto:
			case OEQGoto:
			case ONEQGoto: quadptr->arg3 = instr; break;
			default: yyerror("非法转移指令");
		}
		p0 = p0->next;
	}
}

/**************************** 上面：回填列表的定义与处理函数 ****************************/

