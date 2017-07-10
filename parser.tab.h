/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BASIC = 258,
    CONST = 259,
    ID = 260,
    IF = 261,
    DO = 262,
    WHILE = 263,
    ASSIGN = 264,
    OR = 265,
    AND = 266,
    EQ = 267,
    NE = 268,
    LESS = 269,
    LE = 270,
    GREAT = 271,
    GE = 272,
    ADD = 273,
    SUB = 274,
    MUL = 275,
    DIV = 276,
    NOT = 277,
    UMINUS = 278,
    LOWER_THEN_ELSE = 279,
    ELSE = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "parser.y" /* yacc.c:1909  */

	union {
		struct idNode *id; /*标识符:终结符ID的综合属性*/
	
		struct constvalNode *constval; /*终结符const的综合属性*/
	
		struct basicNode *basic; /*基本数据类型：终结符BASIC的综合属性*/
	
		struct nonterminalNode *factor, *unary, *term, *expr, *rel, *equality, *join, *bool; /*非终结符factor, unary, term, expr, rel, equality, join, bool的综合属性*/
		struct declarationNode *stmts, *stmt, *block, *BoolN; /*非终结符stmts, stmt, block, BoolN的综合属性*/
		struct boolMNode *BoolM; /*非终结符BoolM的综合属性*/
	} a;

#line 94 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
