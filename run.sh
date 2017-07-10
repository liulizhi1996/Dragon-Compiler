#!/bin/bash
bison -d parser.y
flex scanner.l
gcc parser.tab.c lex.yy.c compiler.c main.c -o compiler.o #> /dev/null 2>&1 #末尾的重定向可以使得产生的提示信息不输出在屏幕上，可选
./compiler.o #<<delimeter
#input1.drg
#gencode1.txt
#delimeter
#input1.drg为输入的Dragon源程序文件，文件名可以修改
#gencode1.txt为保存生成的中间代码，文件名可以修改
