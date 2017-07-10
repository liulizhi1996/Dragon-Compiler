%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
#include "compiler.h"

extern int LineNo;
%}

/* white space */
delim		[ \t\r\v\f]
ws			{delim}+
nextline	[\n]

letter_		[a-zA-Z_]
digit		[0-9]

/* identifier */
id			{letter_}({letter_}|{digit})*

/* exponent */
exp			([Ee][-+]?[0-9]+)
/* integer */
integer		{digit}+
/* real */
real		({digit}*\.{digit}*+|{digit}+\.){exp}?
/* character */
character	"'"."'"

/* comment */
comment_interline	(\/\*([^*]|\*+[^/*])*\*+\/)
comment_inline		"//".*\n

%%

 /* ignore white space */
{ws}		{ }
{nextline}	{ ++LineNo; }

 /* comments */
{comment_interline}	{
						int len = strlen(yytext), i;
						for(i = 0; i < len; ++i)
						{
							if(yytext[i] == '\n')
								++LineNo;
						}
					}
{comment_inline}	{ ++LineNo; }

 /* single operators */
"+"			{ return (ADD); }
"-"			{ return (SUB); }
"*"			{ return (MUL); }
"/"			{ return (DIV); }
"="			{ return (ASSIGN); }
"||"		{ return (OR); }
"&&"		{ return (AND); }
"!"			{ return (NOT); }
";"			{ return (';'); }
"("			{ return ('('); }
")"			{ return (')'); }
"{"			{ return ('{'); }
"}"			{ return ('}'); }

 /* comparison operators */
"<"			{ return (LESS); }
"<="		{ return (LE); }
">"			{ return (GREAT); }
">="		{ return (GE); }
"=="		{ return (EQ); }
"!="		{ return (NE); }

 /* keywords */
"if"		{ return (IF); }
"else"		{ return (ELSE); }
"while"		{ return (WHILE); }
"do"		{ return (DO); }
"true"		{ yylval.a.constval = (struct constvalNode *)malloc(sizeof(struct constvalNode));
			  strcpy(yylval.a.constval->str, yytext); /*str用于演示用*/
              yylval.a.constval->type = BOOL;
              memset( &yylval.a.constval->value, 0, sizeof( yylval.a.constval->value) );
              yylval.a.constval->value.n = 1;
              yylval.a.constval->width = BOOL_WIDTH;
              return (CONST); 
            }
"false"		{ yylval.a.constval = (struct constvalNode *)malloc(sizeof(struct constvalNode));
			  strcpy(yylval.a.constval->str, yytext); /*str用于演示用*/
              yylval.a.constval->type = BOOL;
              memset( &yylval.a.constval->value, 0, sizeof( yylval.a.constval->value) );
              yylval.a.constval->value.n = 0;
              yylval.a.constval->width = BOOL_WIDTH;
              return (CONST);
            }
"int"		{ yylval.a.basic = (struct basicNode *)malloc(sizeof(struct basicNode)); yylval.a.basic->type = INT; return (BASIC); }
"float"		{ yylval.a.basic = (struct basicNode *)malloc(sizeof(struct basicNode)); yylval.a.basic->type = FLOAT; return (BASIC); }
"char"		{ yylval.a.basic = (struct basicNode *)malloc(sizeof(struct basicNode)); yylval.a.basic->type = CHAR; return (BASIC); }
"bool"		{ yylval.a.basic = (struct basicNode *)malloc(sizeof(struct basicNode)); yylval.a.basic->type = BOOL; return (BASIC); }

 /* identifiers */
{id}		{ yylval.a.id = (struct idNode *)malloc(sizeof(struct idNode)); 
			  strncpy( yylval.a.id->name, yytext, ID_MAX_LEN );
			  yylval.a.id->name[ID_MAX_LEN]='\0'; 
			  return (ID);
			}
 /* invaild identifiers */
[0-9]+{id}	{ printf("Error in line %d: invalid identifier: %s\n", LineNo, yytext); }

 /* numbers */
{real}		{ yylval.a.constval = (struct constvalNode *)malloc(sizeof(struct constvalNode));
			  strcpy(yylval.a.constval->str, yytext);  /*str用于演示用*/
              yylval.a.constval->type = FLOAT;
              memset( &yylval.a.constval->value, 0, sizeof( yylval.a.constval->value) );
              sscanf( yytext, "%lf", &yylval.a.constval->value.f );
              yylval.a.constval->width = FLOAT_WIDTH;
              return (CONST); 
            }
{integer}	{ yylval.a.constval = (struct constvalNode *)malloc(sizeof(struct constvalNode));
			  strcpy(yylval.a.constval->str, yytext); /*str用于演示用*/
              yylval.a.constval->type = INT; 
              memset( &yylval.a.constval->value, 0, sizeof( yylval.a.constval->value) );
              sscanf( yytext, "%d",&yylval.a.constval->value.n);
              yylval.a.constval->width = INT_WIDTH;
              return (CONST);
			}
{character} { yylval.a.constval = (struct constvalNode *)malloc(sizeof(struct constvalNode));
			  yylval.a.constval->str[0] = yytext[1]; yylval.a.constval->str[1]='\0';  /*str用于演示用*/
              yylval.a.constval->type = CHAR;    
              memset( &yylval.a.constval->value, 0, sizeof( yylval.a.constval->value) );
              yylval.a.constval->value.ch = yytext[1];
              yylval.a.constval->width = CHAR_WIDTH;
              return (CONST); 
            }

 /* other characters */
.			{ printf("Error in line %d: unknown character: %s\n", LineNo, yytext); }

%%
int yywrap()
{
   return 1;
}

