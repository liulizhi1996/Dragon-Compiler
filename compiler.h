extern void yyerror( char * ErrStr );

/* 变量和常量的基本类型BASIC */
#define BOOL     1
#define CHAR     2
#define INT      3
#define FLOAT    4

#define CHAR_WIDTH  1
#define INT_WIDTH   4
#define FLOAT_WIDTH 8  
#define BOOL_WIDTH  1

/**************************** 下面：符号表的定义和相关函数 ****************************/
/* 变量名长度不超过ID_MAX_LEN 个字符 */
#define ID_MAX_LEN   64

/* 存放一个标识符 */
struct SymbolElem
{
    char name[ ID_MAX_LEN + 1 ]; /*符号名(例如变量名)长度不超过ID_MAX_LEN 个字符*/
    int type; /*用来存放类型名，例如int, 这个程序只处理简单类型，在实际的编译器中，这里要建立树结构*/
    int  addr;      /*为该变量分配的空间的首地址*/
	int  width;     /*该变量的宽度，即占用多少个字节*/
    struct SymbolElem * next;  /*指向下一个标识符*/
};

/* 标识符表 */
typedef struct SymbolList
{
    struct SymbolElem * head;  /*指向符号表（用链表实现）的第一个结点，没有头结点,初始化为NULL*/
    struct SymbolList * prev; /*上一层的符号表*/
    int beginaddr; /*该符号表中分配给变量和临时变量空间的开始地址*/
    int endaddr;    /*该符号表中分配给变量和临时变量空间的结束地址*/
                   /*beginaddr~endaddr的空间存放该符号表的所有变量和临时变量*/
} * SymbolList;  /*符号表*/

/* 创建并返回一个新的符号表（SymbolList就是书上的Env），PrevList是其的上一层符号表 */
SymbolList CreateSymbolList( SymbolList PrevList, int StartAddr );

/* 销毁符号表 */
void DestroySymbolList( SymbolList List );

/* 在符号表List中查找是否存在标识符IdName，如果存在，则返回该结点指针，否则返回空 */
struct SymbolElem * LookUpSymbolList( SymbolList List, char * IdName );

/* 从符号表List开始并不断地往上一层符号表中查找是否存在标识符IdName，如果存在，则返回该结点指针，否则返回空 */
struct SymbolElem * LookUpAllSymbolList( SymbolList List, char * IdName );

/* 创建一个新的符号结点,并添加到符号表中，而后返回该结点指针 */
struct SymbolElem * AddToSymbolList( SymbolList List, char * IdName, int IdType, int Width );

/* 输出符号表 */
void PrintSymbolList( SymbolList List );

/*分配一个临时变量,返回临时变量的地址、临时变量的名称*/
int NewTemp( SymbolList List, char Name[], int Width );

/**************************** 上面：符号表的定义和相关函数 ****************************/

/**************************** 下面：常数表的定义和相关函数 ****************************/
union ConstVal
{
	char    ch;    /*存放字符常量*/
	int     n;     /*存放整型常量，或true=1，false=0 */
	double  f;     /*存放浮点数常量*/
};

/* 存放一个常数 */
struct ConstElem
{
    char str[ID_MAX_LEN + 1 ]; /*该变量用于存储常数的文本形式，演示的时候用的,实际的编译系统不需要*/	   
    int type; /*用来存放类型名，例如int, 这个程序只处理简单类型，在实际的编译器中，这里要建立树结构*/
    union ConstVal value;
    int  addr;      /*为该常量分配的空间的首地址*/
	int  width;     /*该变量的宽度，即占用多少个字节*/
    struct ConstElem * next;  /*指向下一个常量*/
};

/* 常量表 */
struct ConstList
{
    struct ConstElem * head;  /*指向常量表（用链表实现）的第一个结点，没有头结点,初始化为NULL*/
    int beginaddr;  /*该符号表中分配给常量空间的开始地址*/
    int endaddr;    /*该符号表中分配给常量空间的结束地址*/
                   /*beginaddr~endaddr的空间存放该常量表的所有常量*/
};

extern struct ConstList ConstList;  /*常量表，全局变量，注意整个程序只需要一个常量表*/

/* 创建并返回常量表 */
void CreateConstList( int StartAddr );

/* 销毁常量表 */
void DestroyConstList( void );

/* 在常量表ConstList中查找是否存在常量，如果存在，则返回该结点指针，否则返回空 */
struct ConstElem * LookUpConstList( int ConstType, union ConstVal ConstValue, int Width );

/* 创建一个新的常数结点,并添加到常数表中，而后返回该结点指针 */
struct ConstElem * AddToConstList( char * Str, int ConstType, union ConstVal ConstValue, int Width );

/* 输出常量表 */
void PrintConstList(void);

/**************************** 上面：常数表的定义和相关函数 ****************************/

/**************************** 下面：四元式的定义和函数 ****************************/
/* 整型加减乘除 */
#define OIntAdd          1001
#define OIntSub          1002
#define OIntMultiply     1003
#define OIntDivide       1004
#define OIntUminus		 1005

/* 浮点数加减乘除 */
#define OFloatAdd        1011
#define OFloatSub        1012
#define OFloatMultiply   1013
#define OFloatDivide     1014
#define OFloatUminus	 1015

/* 赋值a=b */
#define OIntEvaluation   1021
#define OFloatEvaluation 1022
#define OCharEvaluation  1023
#define OBoolEvaluation  1024

/* 无条件goto语句 */
#define OGoto            1031

/* if a op b goto 语句 */
#define OGTGoto          1041
#define OGEGoto          1042
#define OLTGoto          1043
#define OLEGoto          1044
#define OEQGoto          1045
#define ONEQGoto         1046

/* 强制类型转换 */
#define OCharToInt       1051
#define OCharToFloat     1052
#define OIntToFloat      1053
#define OIntToChar       1054
#define OFloatToChar     1055
#define OFloatToInt      1056
#define OCharToBool      1057
#define OIntToBool       1058
#define OFloatToBool     1059
#define OBoolToChar      1060
#define OBoolToInt       1061
#define OBoolToFloat     1062 

/* 程序终止 */
#define OHalt			 1071

/* 四元式数据结构 */
struct Quadruple
{
    int op; /*运算符*/
    int arg1; /*存放第一个参数的地址，可能是变量、临时变量的地址*/
    int arg2;
    int arg3; /*存放第三个参数的地址，可能是变量、临时变量的地址，还可能是四元式的地址(Goto 的地址参数)*/
    char arg1name[ID_MAX_LEN + 1]; /*本不需要，用于演示时能显示arg1对应的变量或临时变量的名称*/
    char arg2name[ID_MAX_LEN + 1]; /*本不需要，用于演示时能显示arg2对应的变量或临时变量的名称*/
    char arg3name[ID_MAX_LEN + 1]; /*本不需要，用于演示时能显示arg3对应的变量或临时变量的名称*/
};

/* 四元式表 */
struct QuadTable
{
    int startaddr; /*四元式开始存放的地址,比如100*/
    struct Quadruple * base; /*指向一块内存，用来存放多个四元式，从base[0]开始存放*/
    int size; /*base中可以存放的四元式的个数*/
    int len; /*base[len]是下一个四元式要存放的空间*/
};

extern struct QuadTable quadTable;

extern int nextinstr;

void CreateQuadTable(int StartAddr);

void DestroyQuadTable( void );

/* 当Arg1是变量或临时变量时，Arg1Name是该变量的名称,用于演示时使用，其余参数类同 */
int Gen( int Op, int Arg1, int Arg2, int Arg3, char *Arg1Name, char *Arg2Name, char *Arg3Name );

/* 把四元式所对应的三地址代码写入到文件中 */
void WriteQuadTableToFile( const char * FileName );

/* 把四元式所对应的三地址代码显示在屏幕上 */
void PrintQuadTable( void );

/**************************** 上面：四元式的定义和函数 ****************************/

/**************************** 下面：定义句法分析栈中元素的信息，即终结符和非终结符的综合属性 ****************************/
struct idNode
{
	/*符号名(例如变量名)长度不超过ID_MAX_LEN 个字符*/
	/*如果建立hash表来存储所有的不同名字的标识符的名字，这里就可以使用一个指针指向该标识符的名字，
	  好处是减少分析栈中元素的空间大小，从而节省空间且提高编译效率，*/
	char name[ID_MAX_LEN + 1 ]; 
}; /*标识符:终结符ID的综合属性*/

struct constvalNode
{
	char str[ID_MAX_LEN + 1 ]; /*该变量用于存储常数的文本形式，演示的时候用的,实际的编译系统不需要*/	   
	int type; /*用来存放类型名，例如INT*/
	union ConstVal value; /*常量：终结符CONST的信息*/
	int width;
}; /*终结符const的综合属性*/
	
struct basicNode
{
	int type; /*用来存放类型名，例如INT*/
}; /*基本数据类型：终结符BASIC的综合属性*/
	
struct nonterminalNode
{
	char str[ID_MAX_LEN + 1 ]; /*该变量用于存储变量名、临时变量名或常数的文本形式，演示的时候用的,实际的编译系统不需要*/
	int type;
	int addr;
	int width;
	struct BoolList *truelist;
	struct BoolList *falselist;
}; /*非终结符factor, unary, term, expr, rel, equality, join, bool的综合属性*/

struct declarationNode
{
	struct BoolList *nextlist;
}; /*非终结符stmts, stmt, block, BoolN的综合属性*/

struct boolMNode
{
	int instr;
}; /*非终结符BoolM的综合属性*/
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
int maxType(int type1, int type2);

/* 将类型为Type、变量名为name的地址Addr中的内容转换成WideType类型的值，并产生类型转换代码，Temp为生成的临时变量 */
void widenType(int Addr, int Type, char name[], int WideType, struct nonterminalNode *Temp, SymbolList List);

/**************************** 上面：强制类型转换处理 ****************************/

/**************************** 下面：回填列表的定义与处理函数 ****************************/
struct BoolList
{
	int instrNo;
	struct BoolList *next;
}; /* 回填列表的结点定义 */

/* 创建一个只包含instr的列表，返回一个指向新创建列表的指针 */
struct BoolList *makelist(int instr);

/* 将p1和p2指向的列表进行合并，返回指向合并后列表的指针 */
struct BoolList *merge(struct BoolList *p1, struct BoolList *p2);

/* 将instr作为目标标号插入到p所指向列表的各指令中 */
void backpatch(struct BoolList *p, int instr);

/**************************** 上面：回填列表的定义与处理函数 ****************************/

