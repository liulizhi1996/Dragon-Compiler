# Dragon Compiler
This my final project of Compilers Principles in XMU. It's an Intermediate Representation Code Generator implemented by Flex and Yacc.

## Syntax Description
We call the following language as the **Dragon** Language, as it's proposed in the appendix A of the Dragon Book. The syntax is:

```
program -> block
block -> {decls stmts}
decls -> decls decl | ε
decl -> type id ;
type -> basic
stmts -> stmts stmt | stmt
stmt -> id = expr ;
		| if ( bool ) stmt
		| if (bool) stmt else stmt
		| while ( bool ) stmt
		| do stmt while ( bool ) ;
		| block
bool -> bool || join | join
join -> join && equality | equality
equality -> equality == rel | equality != rel | rel
rel -> expr < expr | expr <= expr | expr >= expr | expr > expr | expr
expr -> expr + term | expr - term | term
term -> term * unary | term / unary | unary
unary -> ! unary | - unary | factor
factor -> ( expr ) | id | num
```

## Requirements
It can be executed normally if

- Operating System: Ubuntu 16.04 LTS
- Flex 2.6.0
- Bison 3.0.4
- Gcc 5.4.0
- GNU bash 4.3

## Installation

First, generate the scanner `lex.yy.c`. 

```
flex scanner.l
```

Then, generate the parser `parser.tab.c` and `parser.tab.h`.

```
bison -d parser.y
```

Next, get the executable file `compiler.o`.

```
gcc parser.tab.c lex.yy.c compiler.c main.c -o compiler.o
```

Finally, you can execute `compiler.o` to get the IR code.

```
./compiler.o
```

Enter thr file names of source file `*.drg` and object file `*.txt`, then the IR code generated will be stored in `*.txt`. For example, you can try:

```
$ ./compiler.o
请输入要编译的源程序文件名：input1.drg
请输入要存放中间代码的文件名：gencode1.txt
```

## Quick Installation

I write a shell file called `run.sh` to finish all the steps above. You can type `./run.sh` in the terminal. Please check the names of source file and object file before your execution.