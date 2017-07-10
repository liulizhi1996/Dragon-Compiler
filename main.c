#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compiler.h"

extern int yyparse();
int LineNo = 1;
int CompileFailed = 0;
SymbolList TopSymbolList = NULL;
int nextinstr;	/*下一条四元式的标号*/
struct ConstList ConstList;  /*常量表，全局变量，注意整个程序只需要一个常量表*/
struct QuadTable quadTable; /*只需要一个四元式表*/

int main()
{
	extern FILE *yyin;
	
	char sourcefile[1000], destfile[1000];

	printf("请输入要编译的源程序文件名："); fgets(sourcefile, 1000, stdin); sourcefile[strlen(sourcefile) - 1] = 0;
	printf("请输入存放中间代码的文件名："); fgets(destfile, 1000, stdin); destfile[strlen(destfile) - 1] = 0;
	
	if ((yyin = fopen(sourcefile, "r")) == NULL)
	{
		fprintf(stderr, "Fail to open file!\n");
		exit(1);
	}
	
	CreateConstList(3000);/*创建常量表,假设从地址3000开始分配空间给常量*/
    /*在C语言编译器中，该符号表用于存放外部变量，函数名等。
      在我们的语法中并不支持外部变量和函数，所以该表没有被用到*/
    TopSymbolList = CreateSymbolList( NULL, 2000 ); /*假设从地址2000开始分配空间给变量*/
    CreateQuadTable(100); /*创建四元式表，假设四元式从地址空间100开始存放*/
	
	printf("开始编译！\n");
	if (yyparse() == 1)
	{
		fprintf(stderr, "Parser error!\n");
		exit(1);
	}
	
	PrintConstList();
	PrintQuadTable();
    WriteQuadTableToFile( destfile ); /*把四元式写入到文件destfile中*/

    DestroyQuadTable();
    DestroySymbolList( TopSymbolList );
    DestroyConstList();

    if( CompileFailed == 0 ) 
	    printf("编译成功，生成的四元式在文件%s中。\n", destfile );
	else
	    printf("源文件%s有错误，编译失败。\n", sourcefile );
	
	return 0;
}

