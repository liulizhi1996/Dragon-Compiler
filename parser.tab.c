/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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


#line 93 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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
#line 29 "parser.y" /* yacc.c:355  */

	union {
		struct idNode *id; /*标识符:终结符ID的综合属性*/
	
		struct constvalNode *constval; /*终结符const的综合属性*/
	
		struct basicNode *basic; /*基本数据类型：终结符BASIC的综合属性*/
	
		struct nonterminalNode *factor, *unary, *term, *expr, *rel, *equality, *join, *bool; /*非终结符factor, unary, term, expr, rel, equality, join, bool的综合属性*/
		struct declarationNode *stmts, *stmt, *block, *BoolN; /*非终结符stmts, stmt, block, BoolN的综合属性*/
		struct boolMNode *BoolM; /*非终结符BoolM的综合属性*/
	} a;

#line 173 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 190 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   88

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  92

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    72,    79,    82,    90,    91,    94,   108,
     114,   119,   125,   215,   221,   231,   239,   246,   252,   258,
     268,   279,   290,   301,   306,   317,   328,   339,   350,   361,
     372,   383,   394,   439,   484,   495,   540,   585,   596,   605,
     620,   631,   640,   662
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BASIC", "CONST", "ID", "IF", "DO",
  "WHILE", "ASSIGN", "OR", "AND", "EQ", "NE", "LESS", "LE", "GREAT", "GE",
  "ADD", "SUB", "MUL", "DIV", "NOT", "UMINUS", "LOWER_THEN_ELSE", "ELSE",
  "'{'", "'}'", "';'", "'('", "')'", "$accept", "program", "block",
  "blockM1", "blockM2", "decls", "decl", "type", "stmts", "stmt", "BoolN",
  "bool", "join", "BoolM", "equality", "rel", "expr", "term", "unary",
  "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   123,   125,    59,    40,
      41
};
# endif

#define YYPACT_NINF -38

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-38)))

#define YYTABLE_NINF -6

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -22,   -38,    23,   -38,   -38,   -38,   -38,     9,   -38,    29,
      15,   -38,   -38,   -38,   -38,    44,     1,   -38,     3,     3,
      13,    33,    38,    52,    13,   -38,   -38,     3,     3,     3,
      12,    43,   -38,   -38,    -1,    59,    56,   -38,    42,    72,
       3,   -38,   -38,   -38,   -38,   -38,    18,     3,     3,   -38,
       3,     3,   -38,   -38,   -38,     3,     3,     3,     3,     3,
       3,   -38,    16,   -38,    43,    43,   -38,   -38,     3,    13,
       3,   -38,   -38,    54,    54,    54,    54,    53,   -38,    59,
      58,    56,     3,    13,   -38,    17,   -38,   -38,    57,    13,
     -38,   -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,    23,     7,     1,     2,     0,     9,     0,
       0,    23,    23,    17,     6,     0,    23,    11,     0,     0,
       0,     0,     0,     0,     0,    43,    42,     0,     0,     0,
       0,    34,    37,    40,     0,    20,    22,    26,    31,     0,
       0,     8,     3,    10,    39,    38,     0,     0,     0,    12,
       0,     0,    23,    23,    23,     0,     0,     0,     0,     0,
       0,    23,     0,    41,    32,    33,    35,    36,     0,     0,
       0,    24,    25,    27,    28,    30,    29,     0,    23,    19,
      13,    21,     0,     0,    18,     0,    15,    23,     0,     0,
      16,    14
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,    81,   -38,   -38,   -38,   -38,   -38,   -38,   -18,
     -38,   -37,    20,   -11,    14,    19,    -5,    30,   -17,   -38
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    13,     4,    23,     7,    14,    15,    16,    17,
      87,    34,    35,     6,    36,    37,    38,    31,    32,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      20,    21,    39,    62,     1,    24,    43,    25,    26,    52,
      44,    45,     8,    30,     9,    10,    11,    12,     9,    10,
      11,    12,    27,     5,    46,    28,    52,    52,    -5,    53,
      47,    48,    29,    66,    67,     1,    47,    48,    18,     1,
      49,    68,    69,    70,    19,    85,    78,    88,    63,    22,
      77,    80,    73,    74,    75,    76,    57,    58,    59,    60,
      47,    48,    40,    50,    51,    86,    41,    83,    55,    56,
      54,    91,    47,    48,    71,    72,    89,    64,    65,    42,
      61,     3,    82,    84,    81,    90,     0,     0,    79
};

static const yytype_int8 yycheck[] =
{
      11,    12,    20,    40,    26,    16,    24,     4,     5,    10,
      27,    28,     3,    18,     5,     6,     7,     8,     5,     6,
       7,     8,    19,     0,    29,    22,    10,    10,    27,    30,
      18,    19,    29,    50,    51,    26,    18,    19,     9,    26,
      28,    52,    53,    54,    29,    82,    30,    30,    30,     5,
      61,    69,    57,    58,    59,    60,    14,    15,    16,    17,
      18,    19,    29,    20,    21,    83,    28,    78,    12,    13,
      11,    89,    18,    19,    55,    56,    87,    47,    48,    27,
       8,     0,    29,    25,    70,    28,    -1,    -1,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    32,    33,    34,     0,    44,    36,     3,     5,
       6,     7,     8,    33,    37,    38,    39,    40,     9,    29,
      44,    44,     5,    35,    44,     4,     5,    19,    22,    29,
      47,    48,    49,    50,    42,    43,    45,    46,    47,    40,
      29,    28,    27,    40,    49,    49,    47,    18,    19,    28,
      20,    21,    10,    30,    11,    12,    13,    14,    15,    16,
      17,     8,    42,    30,    48,    48,    49,    49,    44,    44,
      44,    46,    46,    47,    47,    47,    47,    44,    30,    43,
      40,    45,    29,    44,    25,    42,    40,    41,    30,    44,
      28,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    34,    35,    36,    36,    37,    38,
      39,    39,    40,    40,    40,    40,    40,    40,    41,    42,
      42,    43,    43,    44,    45,    45,    45,    46,    46,    46,
      46,    46,    47,    47,    47,    48,    48,    48,    49,    49,
      49,    50,    50,    50
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     6,     0,     0,     2,     0,     3,     1,
       3,     1,     4,     6,    10,     7,     9,     1,     0,     4,
       1,     4,     1,     0,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     2,     2,
       1,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 66 "parser.y" /* yacc.c:1646  */
    { printf("program -> block\n"); 
							  backpatch((yyvsp[-1].a).block->nextlist, (yyvsp[0].a).BoolM->instr);
							  Gen(OHalt, 0, 0, 0, "", "", "");
							}
#line 1326 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 73 "parser.y" /* yacc.c:1646  */
    { printf("block -> { decl stmts }\n"); 
							  (yyval.a).block = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  (yyval.a).block->nextlist = (yyvsp[-2].a).stmts->nextlist;
							}
#line 1335 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 79 "parser.y" /* yacc.c:1646  */
    { TopSymbolList = CreateSymbolList( TopSymbolList, TopSymbolList->endaddr ); }
#line 1341 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 82 "parser.y" /* yacc.c:1646  */
    { SymbolList env;
							  PrintSymbolList( TopSymbolList); 
							  env = TopSymbolList->prev;
							  DestroySymbolList( TopSymbolList ); 
							  TopSymbolList = env;                 
							}
#line 1352 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 90 "parser.y" /* yacc.c:1646  */
    { printf("decls -> decls decl\n"); }
#line 1358 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 91 "parser.y" /* yacc.c:1646  */
    { printf("decls -> ε\n"); }
#line 1364 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 94 "parser.y" /* yacc.c:1646  */
    { int width;
							  printf("decl -> type id ;\n"); 
							  switch( (yyvsp[-2].a).basic->type )
							  {
								  case CHAR  : width = CHAR_WIDTH;  break;
								  case INT   : width = INT_WIDTH;   break;
								  case FLOAT : width = FLOAT_WIDTH; break;
								  case BOOL  : width = BOOL_WIDTH;  break;
								  default    : width = -1; break;
							  }
							  AddToSymbolList( TopSymbolList, (yyvsp[-1].a).id->name, (yyvsp[-2].a).basic->type, width );
							}
#line 1381 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 108 "parser.y" /* yacc.c:1646  */
    { (yyval.a).basic = (struct basicNode *)malloc(sizeof(struct basicNode)); 
							  printf("type -> basic\n");
							  (yyval.a).basic->type = (yyvsp[0].a).basic->type;
							}
#line 1390 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 114 "parser.y" /* yacc.c:1646  */
    { printf("stmts -> stmts stmt\n"); 
							  (yyval.a).stmts = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  backpatch((yyvsp[-2].a).stmts->nextlist, (yyvsp[-1].a).BoolM->instr);
							  (yyval.a).stmts->nextlist = (yyvsp[0].a).stmt->nextlist;
							}
#line 1400 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "parser.y" /* yacc.c:1646  */
    { printf("stmts -> stmt\n"); 
	 						  (yyval.a).stmts = (struct declarationNode *)malloc(sizeof(struct declarationNode));
	 						  (yyval.a).stmts->nextlist = (yyvsp[0].a).stmt->nextlist;
	 						}
#line 1409 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 125 "parser.y" /* yacc.c:1646  */
    { printf("stmt -> id = expr ;\n");
							  (yyval.a).stmt = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  (yyval.a).stmt->nextlist = NULL;
							  struct SymbolElem * p;
							  p = LookUpAllSymbolList( TopSymbolList, (yyvsp[-3].a).id->name );
							  if( p != NULL )
							  {
							  	  if (p->type == (yyvsp[-1].a).expr->type)
								  {
								  	  switch (p->type)
								  	  {
								  	  	  case BOOL	: Gen(OBoolEvaluation , (yyvsp[-1].a).expr->addr, 0, p->addr, (yyvsp[-1].a).expr->str, "",  p->name); break;
								  	  	  case CHAR	: Gen(OCharEvaluation , (yyvsp[-1].a).expr->addr, 0, p->addr, (yyvsp[-1].a).expr->str, "",  p->name); break;
								  	  	  case INT	: Gen(OIntEvaluation , (yyvsp[-1].a).expr->addr, 0, p->addr, (yyvsp[-1].a).expr->str, "",  p->name); break;
								  	  	  case FLOAT: Gen(OFloatEvaluation , (yyvsp[-1].a).expr->addr, 0, p->addr, (yyvsp[-1].a).expr->str, "",  p->name); break;
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
								  	  	  switch ((yyvsp[-1].a).expr->type)
								  	  	  {
								  	  	  	  case CHAR	: Gen(OCharToBool, (yyvsp[-1].a).expr->addr, 0, Temp.addr, (yyvsp[-1].a).expr->str, "", Temp.str); break;
								  	  	  	  case INT	: Gen(OIntToBool, (yyvsp[-1].a).expr->addr, 0, Temp.addr, (yyvsp[-1].a).expr->str, "", Temp.str); break;
								  	  	  	  case FLOAT: Gen(OFloatToBool, (yyvsp[-1].a).expr->addr, 0, Temp.addr, (yyvsp[-1].a).expr->str, "", Temp.str); break;
								  	  	  	  default: yyerror("非法类型");
								  	  	  }
								  	  }
								  	  else if (p->type == CHAR)
								  	  {
								  	  	  Temp.type = CHAR;
								  	  	  Temp.width = CHAR_WIDTH;
								  	  	  Temp.addr = NewTemp(TopSymbolList, Temp.str, Temp.width);
								  	  	  switch ((yyvsp[-1].a).expr->type)
								  	  	  {
								  	  	  	  case BOOL	: Gen(OBoolToChar, (yyvsp[-1].a).expr->addr, 0, Temp.addr, (yyvsp[-1].a).expr->str, "", Temp.str); break;
								  	  	  	  case INT	: Gen(OIntToChar, (yyvsp[-1].a).expr->addr, 0, Temp.addr, (yyvsp[-1].a).expr->str, "", Temp.str); break;
								  	  	  	  case FLOAT: Gen(OFloatToChar, (yyvsp[-1].a).expr->addr, 0, Temp.addr, (yyvsp[-1].a).expr->str, "", Temp.str); break;
								  	  	  	  default: yyerror("非法类型");
								  	  	  }
								  	  }
								  	  else if (p->type == INT)
								  	  {
								  	  	  Temp.type = INT;
								  	  	  Temp.width = INT_WIDTH;
								  	  	  Temp.addr = NewTemp(TopSymbolList, Temp.str, Temp.width);
								  	  	  switch ((yyvsp[-1].a).expr->type)
								  	  	  {
								  	  	  	  case BOOL	: Gen(OBoolToInt, (yyvsp[-1].a).expr->addr, 0, Temp.addr, (yyvsp[-1].a).expr->str, "", Temp.str); break;
								  	  	  	  case CHAR	: Gen(OCharToInt, (yyvsp[-1].a).expr->addr, 0, Temp.addr, (yyvsp[-1].a).expr->str, "", Temp.str); break;
								  	  	  	  case FLOAT: Gen(OFloatToInt, (yyvsp[-1].a).expr->addr, 0, Temp.addr, (yyvsp[-1].a).expr->str, "", Temp.str); break;
								  	  	  	  default: yyerror("非法类型");
								  	  	  }
								  	  }
								  	  else if (p->type == FLOAT)
								  	  {
								  	  	  Temp.type = FLOAT;
								  	  	  Temp.width = FLOAT_WIDTH;
								  	  	  Temp.addr = NewTemp(TopSymbolList, Temp.str, Temp.width);
								  	  	  switch ((yyvsp[-1].a).expr->type)
								  	  	  {
								  	  	  	  case BOOL	: Gen(OBoolToFloat, (yyvsp[-1].a).expr->addr, 0, Temp.addr, (yyvsp[-1].a).expr->str, "", Temp.str); break;
								  	  	  	  case CHAR	: Gen(OCharToFloat, (yyvsp[-1].a).expr->addr, 0, Temp.addr, (yyvsp[-1].a).expr->str, "", Temp.str); break;
								  	  	  	  case INT	: Gen(OIntToFloat, (yyvsp[-1].a).expr->addr, 0, Temp.addr, (yyvsp[-1].a).expr->str, "", Temp.str); break;
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
#line 1504 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 216 "parser.y" /* yacc.c:1646  */
    { printf("stmt -> if ( bool ) stmt\n");
							  (yyval.a).stmt = (struct declarationNode *)malloc(sizeof(struct declarationNode)); 
							  backpatch((yyvsp[-3].a).bool->truelist, (yyvsp[-1].a).BoolM->instr);
							  (yyval.a).stmt->nextlist = merge((yyvsp[-3].a).bool->falselist, (yyvsp[0].a).stmt->nextlist);
							}
#line 1514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 222 "parser.y" /* yacc.c:1646  */
    { printf("stmt -> if ( bool ) stmt else stmt\n"); 
							  (yyval.a).stmt = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  backpatch((yyvsp[-7].a).bool->truelist, (yyvsp[-5].a).BoolM->instr);
							  backpatch((yyvsp[-7].a).bool->falselist, (yyvsp[-1].a).BoolM->instr);
							  struct BoolList *temp;
							  temp = merge((yyvsp[-4].a).stmt->nextlist, (yyvsp[-2].a).BoolN->nextlist);
							  (yyval.a).stmt->nextlist = merge(temp, (yyvsp[0].a).stmt->nextlist);
							  
							}
#line 1528 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 232 "parser.y" /* yacc.c:1646  */
    { printf("stmt -> while ( bool ) stmt\n"); 
							  (yyval.a).stmt = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  backpatch((yyvsp[0].a).stmt->nextlist, (yyvsp[-5].a).BoolM->instr);
							  backpatch((yyvsp[-3].a).bool->truelist, (yyvsp[-1].a).BoolM->instr);
							  (yyval.a).stmt->nextlist = (yyvsp[-3].a).bool->falselist;
							  Gen(OGoto, 0, 0, (yyvsp[-5].a).BoolM->instr, "", "", "");
							}
#line 1540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 240 "parser.y" /* yacc.c:1646  */
    { printf("stmt -> do stmt while ( bool ) ;\n"); 
							  (yyval.a).stmt = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  backpatch((yyvsp[-6].a).stmt->nextlist, (yyvsp[-4].a).BoolM->instr);
							  backpatch((yyvsp[-2].a).bool->truelist, (yyvsp[-7].a).BoolM->instr);
							  (yyval.a).stmt->nextlist = (yyvsp[-2].a).bool->falselist;
							}
#line 1551 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 246 "parser.y" /* yacc.c:1646  */
    { printf("stmt -> block\n"); 
							  (yyval.a).stmt = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  (yyval.a).stmt->nextlist = (yyvsp[0].a).block->nextlist;
							}
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 252 "parser.y" /* yacc.c:1646  */
    { (yyval.a).BoolN = (struct declarationNode *)malloc(sizeof(struct declarationNode));
							  (yyval.a).BoolN->nextlist = makelist(nextinstr);
							  Gen(OGoto, 0, 0, 0, "", "", "");
							}
#line 1569 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 258 "parser.y" /* yacc.c:1646  */
    { printf("bool -> bool || join\n"); 
							  (yyval.a).bool = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( (yyval.a).bool->str, "");
							  (yyval.a).bool->type = 0;
							  (yyval.a).bool->addr = 0;
							  (yyval.a).bool->width = 0;
							  backpatch((yyvsp[-3].a).bool->falselist, (yyvsp[-1].a).BoolM->instr);
							  (yyval.a).bool->truelist = merge((yyvsp[-3].a).bool->truelist, (yyvsp[0].a).join->truelist);
							  (yyval.a).bool->falselist = (yyvsp[0].a).join->falselist;
							}
#line 1584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 268 "parser.y" /* yacc.c:1646  */
    { printf("bool -> join\n"); 
							  (yyval.a).bool = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( (yyval.a).bool->str, (yyvsp[0].a).join->str );
   							  (yyval.a).bool->type = (yyvsp[0].a).join->type;
   							  (yyval.a).bool->addr = (yyvsp[0].a).join->addr;
   							  (yyval.a).bool->width = (yyvsp[0].a).join->width;
   							  (yyval.a).bool->truelist = (yyvsp[0].a).join->truelist;
   							  (yyval.a).bool->falselist = (yyvsp[0].a).join->falselist;
							}
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 280 "parser.y" /* yacc.c:1646  */
    { printf("join -> join && equality\n"); 
							  (yyval.a).join = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( (yyval.a).join->str, "" );
							  (yyval.a).join->type = 0;
							  (yyval.a).join->addr = 0;
							  (yyval.a).join->width = 0;
							  backpatch((yyvsp[-3].a).join->truelist, (yyvsp[-1].a).BoolM->instr);
							  (yyval.a).join->truelist = (yyvsp[0].a).equality->truelist;
							  (yyval.a).join->falselist = merge((yyvsp[-3].a).join->falselist, (yyvsp[0].a).equality->falselist);
							}
#line 1613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 290 "parser.y" /* yacc.c:1646  */
    { printf("join -> equality\n"); 
							  (yyval.a).join = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( (yyval.a).join->str, (yyvsp[0].a).equality->str );
   							  (yyval.a).join->type = (yyvsp[0].a).equality->type;
   							  (yyval.a).join->addr = (yyvsp[0].a).equality->addr;
   							  (yyval.a).join->width = (yyvsp[0].a).equality->width;
   							  (yyval.a).join->truelist = (yyvsp[0].a).equality->truelist;
   							  (yyval.a).join->falselist = (yyvsp[0].a).equality->falselist;
							}
#line 1627 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 301 "parser.y" /* yacc.c:1646  */
    { (yyval.a).BoolM = (struct boolMNode *)malloc(sizeof(struct boolMNode));
							  (yyval.a).BoolM->instr = nextinstr;
							}
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 306 "parser.y" /* yacc.c:1646  */
    { printf("equality -> equality == rel\n"); 
							  (yyval.a).equality = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( (yyval.a).equality->str, "" );
   							  (yyval.a).equality->type = 0;
   							  (yyval.a).equality->addr = 0;
   							  (yyval.a).equality->width = 0;
   							  (yyval.a).equality->truelist = makelist(nextinstr);
   							  (yyval.a).equality->falselist = makelist(nextinstr + 1);
   							  Gen(OEQGoto, (yyvsp[-2].a).equality->addr, (yyvsp[0].a).rel->addr, 0, (yyvsp[-2].a).equality->str, (yyvsp[0].a).rel->str, "");
   							  Gen(OGoto, 0, 0, 0, "", "", "");
							}
#line 1651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 317 "parser.y" /* yacc.c:1646  */
    { printf("equality -> equality != rel\n"); 
							  (yyval.a).equality = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( (yyval.a).equality->str, "" );
   							  (yyval.a).equality->type = 0;
   							  (yyval.a).equality->addr = 0;
   							  (yyval.a).equality->width = 0;
   							  (yyval.a).equality->truelist = makelist(nextinstr);
   							  (yyval.a).equality->falselist = makelist(nextinstr + 1);
   							  Gen(ONEQGoto, (yyvsp[-2].a).equality->addr, (yyvsp[0].a).rel->addr, 0, (yyvsp[-2].a).equality->str, (yyvsp[0].a).rel->str, "");
   							  Gen(OGoto, 0, 0, 0, "", "", "");
							}
#line 1667 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 328 "parser.y" /* yacc.c:1646  */
    { printf("equality -> rel\n");
							  (yyval.a).equality = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( (yyval.a).equality->str, (yyvsp[0].a).rel->str );
   							  (yyval.a).equality->type = (yyvsp[0].a).rel->type;
   							  (yyval.a).equality->addr = (yyvsp[0].a).rel->addr;
   							  (yyval.a).equality->width = (yyvsp[0].a).rel->width;
   							  (yyval.a).equality->truelist = (yyvsp[0].a).rel->truelist;
   							  (yyval.a).equality->falselist = (yyvsp[0].a).rel->falselist;
							}
#line 1681 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 339 "parser.y" /* yacc.c:1646  */
    { printf("rel -> expr < expr\n"); 
							  (yyval.a).rel = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( (yyval.a).rel->str, "");
							  (yyval.a).rel->type = 0;
							  (yyval.a).rel->addr = 0;
							  (yyval.a).rel->width = 0;
							  (yyval.a).rel->truelist = makelist(nextinstr);
							  (yyval.a).rel->falselist = makelist(nextinstr + 1);
							  Gen(OLTGoto, (yyvsp[-2].a).expr->addr, (yyvsp[0].a).expr->addr, 0, (yyvsp[-2].a).expr->str, (yyvsp[0].a).expr->str, "");
							  Gen(OGoto, 0, 0, 0, "", "", "");
							}
#line 1697 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 350 "parser.y" /* yacc.c:1646  */
    { printf("rel -> expr <= expr\n"); 
   							  (yyval.a).rel = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( (yyval.a).rel->str, "");
							  (yyval.a).rel->type = 0;
							  (yyval.a).rel->addr = 0;
							  (yyval.a).rel->width = 0;
							  (yyval.a).rel->truelist = makelist(nextinstr);
							  (yyval.a).rel->falselist = makelist(nextinstr + 1);
							  Gen(OLEGoto, (yyvsp[-2].a).expr->addr, (yyvsp[0].a).expr->addr, 0, (yyvsp[-2].a).expr->str, (yyvsp[0].a).expr->str, "");
							  Gen(OGoto, 0, 0, 0, "", "", "");
   							}
#line 1713 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 361 "parser.y" /* yacc.c:1646  */
    { printf("rel -> expr >= expr\n"); 
   							  (yyval.a).rel = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( (yyval.a).rel->str, "");
							  (yyval.a).rel->type = 0;
							  (yyval.a).rel->addr = 0;
							  (yyval.a).rel->width = 0;
							  (yyval.a).rel->truelist = makelist(nextinstr);
							  (yyval.a).rel->falselist = makelist(nextinstr + 1);
							  Gen(OGEGoto, (yyvsp[-2].a).expr->addr, (yyvsp[0].a).expr->addr, 0, (yyvsp[-2].a).expr->str, (yyvsp[0].a).expr->str, "");
							  Gen(OGoto, 0, 0, 0, "", "", "");
   							}
#line 1729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 372 "parser.y" /* yacc.c:1646  */
    { printf("rel -> expr > expr\n"); 
   							  (yyval.a).rel = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( (yyval.a).rel->str, "");
							  (yyval.a).rel->type = 0;
							  (yyval.a).rel->addr = 0;
							  (yyval.a).rel->width = 0;
							  (yyval.a).rel->truelist = makelist(nextinstr);
							  (yyval.a).rel->falselist = makelist(nextinstr + 1);
							  Gen(OGTGoto, (yyvsp[-2].a).expr->addr, (yyvsp[0].a).expr->addr, 0, (yyvsp[-2].a).expr->str, (yyvsp[0].a).expr->str, "");
							  Gen(OGoto, 0, 0, 0, "", "", "");
   							}
#line 1745 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 383 "parser.y" /* yacc.c:1646  */
    { printf("rel -> expr\n");
   							  (yyval.a).rel = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
   							  strcpy( (yyval.a).rel->str, (yyvsp[0].a).expr->str );
   							  (yyval.a).rel->type = (yyvsp[0].a).expr->type;
   							  (yyval.a).rel->addr = (yyvsp[0].a).expr->addr;
   							  (yyval.a).rel->width = (yyvsp[0].a).expr->width;
   							  (yyval.a).rel->truelist = NULL;
   							  (yyval.a).rel->falselist = NULL;
   							}
#line 1759 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 394 "parser.y" /* yacc.c:1646  */
    { (yyval.a).expr = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  printf("expr -> expr + term\n");
							  (yyval.a).expr->type = maxType((yyvsp[-2].a).expr->type, (yyvsp[0].a).term->type);
							  (yyval.a).expr->addr = NewTemp(TopSymbolList, (yyval.a).expr->str, (yyval.a).expr->type);
							  (yyval.a).expr->truelist = NULL;
							  (yyval.a).expr->falselist = NULL;
							  switch ((yyval.a).expr->type)
							  {
							  	  case BOOL : (yyval.a).expr->width = BOOL_WIDTH; break;
							  	  case CHAR : (yyval.a).expr->width = CHAR_WIDTH; break;
							  	  case INT  : (yyval.a).expr->width = INT_WIDTH; break;
							  	  case FLOAT: (yyval.a).expr->width = FLOAT_WIDTH; break;
							  }
							  if ((yyvsp[-2].a).expr->type == (yyvsp[0].a).term->type)
							  {
							  	  if ((yyvsp[-2].a).expr->type == INT)
							  	  	  Gen(OIntAdd, (yyvsp[-2].a).expr->addr, (yyvsp[0].a).term->addr, (yyval.a).expr->addr, (yyvsp[-2].a).expr->str, (yyvsp[0].a).term->str, (yyval.a).expr->str); 
							  	  else if ((yyvsp[-2].a).expr->type == FLOAT)
							  	  	  Gen(OFloatAdd, (yyvsp[-2].a).expr->addr, (yyvsp[0].a).term->addr, (yyval.a).expr->addr, (yyvsp[-2].a).expr->str, (yyvsp[0].a).term->str, (yyval.a).expr->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else if ((yyvsp[-2].a).expr->type > (yyvsp[0].a).term->type)
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType((yyvsp[0].a).term->addr, (yyvsp[0].a).term->type, (yyvsp[0].a).term->str, (yyvsp[-2].a).expr->type, &Temp, TopSymbolList);
							  	  if ((yyvsp[-2].a).expr->type == INT)
							  	  	  Gen(OIntAdd, (yyvsp[-2].a).expr->addr, Temp.addr, (yyval.a).expr->addr, (yyvsp[-2].a).expr->str, Temp.str, (yyval.a).expr->str);
							  	  else if ((yyvsp[-2].a).expr->type == FLOAT)
							  	  	  Gen(OFloatAdd, (yyvsp[-2].a).expr->addr, Temp.addr, (yyval.a).expr->addr, (yyvsp[-2].a).expr->str, Temp.str, (yyval.a).expr->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType((yyvsp[-2].a).expr->addr, (yyvsp[-2].a).expr->type, (yyvsp[-2].a).expr->str, (yyvsp[0].a).term->type, &Temp, TopSymbolList);
							  	  if ((yyvsp[0].a).term->type == INT)
							  	  	  Gen(OIntAdd, Temp.addr, (yyvsp[0].a).term->addr, (yyval.a).expr->addr, Temp.str, (yyvsp[0].a).term->str, (yyval.a).expr->str);
							  	  else if ((yyvsp[0].a).term->type == FLOAT)
							  	  	  Gen(OFloatAdd, Temp.addr, (yyvsp[0].a).term->addr, (yyval.a).expr->addr, Temp.str, (yyvsp[0].a).term->str, (yyval.a).expr->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							}
#line 1809 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 439 "parser.y" /* yacc.c:1646  */
    { (yyval.a).expr = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  printf("expr -> expr + term\n");
							  (yyval.a).expr->type = maxType((yyvsp[-2].a).expr->type, (yyvsp[0].a).term->type);
							  (yyval.a).expr->addr = NewTemp(TopSymbolList, (yyval.a).expr->str, (yyval.a).expr->type);
							  (yyval.a).expr->truelist = NULL;
							  (yyval.a).expr->falselist = NULL;
							  switch ((yyval.a).expr->type)
							  {
							  	  case BOOL : (yyval.a).expr->width = BOOL_WIDTH; break;
							  	  case CHAR : (yyval.a).expr->width = CHAR_WIDTH; break;
							  	  case INT  : (yyval.a).expr->width = INT_WIDTH; break;
							  	  case FLOAT: (yyval.a).expr->width = FLOAT_WIDTH; break;
							  }
							  if ((yyvsp[-2].a).expr->type == (yyvsp[0].a).term->type)
							  {
							  	  if ((yyvsp[-2].a).expr->type == INT)
							  	  	  Gen(OIntSub, (yyvsp[-2].a).expr->addr, (yyvsp[0].a).term->addr, (yyval.a).expr->addr, (yyvsp[-2].a).expr->str, (yyvsp[0].a).term->str, (yyval.a).expr->str); 
							  	  else if ((yyvsp[-2].a).expr->type == FLOAT)
							  	  	  Gen(OFloatSub, (yyvsp[-2].a).expr->addr, (yyvsp[0].a).term->addr, (yyval.a).expr->addr, (yyvsp[-2].a).expr->str, (yyvsp[0].a).term->str, (yyval.a).expr->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else if ((yyvsp[-2].a).expr->type > (yyvsp[0].a).term->type)
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType((yyvsp[0].a).term->addr, (yyvsp[0].a).term->type, (yyvsp[0].a).term->str, (yyvsp[-2].a).expr->type, &Temp, TopSymbolList);
							  	  if ((yyvsp[-2].a).expr->type == INT)
							  	  	  Gen(OIntSub, (yyvsp[-2].a).expr->addr, Temp.addr, (yyval.a).expr->addr, (yyvsp[-2].a).expr->str, Temp.str, (yyval.a).expr->str);
							  	  else if ((yyvsp[-2].a).expr->type == FLOAT)
							  	  	  Gen(OFloatSub, (yyvsp[-2].a).expr->addr, Temp.addr, (yyval.a).expr->addr, (yyvsp[-2].a).expr->str, Temp.str, (yyval.a).expr->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType((yyvsp[-2].a).expr->addr, (yyvsp[-2].a).expr->type, (yyvsp[-2].a).expr->str, (yyvsp[0].a).term->type, &Temp, TopSymbolList);
							  	  if ((yyvsp[0].a).term->type == INT)
							  	  	  Gen(OIntSub, Temp.addr, (yyvsp[0].a).term->addr, (yyval.a).expr->addr, Temp.str, (yyvsp[0].a).term->str, (yyval.a).expr->str);
							  	  else if ((yyvsp[0].a).term->type == FLOAT)
							  	  	  Gen(OFloatSub, Temp.addr, (yyvsp[0].a).term->addr, (yyval.a).expr->addr, Temp.str, (yyvsp[0].a).term->str, (yyval.a).expr->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							}
#line 1859 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 484 "parser.y" /* yacc.c:1646  */
    { (yyval.a).expr = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  printf("expr -> term\n");
							  strcpy( (yyval.a).expr->str, (yyvsp[0].a).term->str );
							  (yyval.a).expr->type = (yyvsp[0].a).term->type;
							  (yyval.a).expr->addr = (yyvsp[0].a).term->addr;
							  (yyval.a).expr->width = (yyvsp[0].a).term->width; 
							  (yyval.a).expr->truelist = (yyvsp[0].a).term->truelist;
							  (yyval.a).expr->falselist = (yyvsp[0].a).term->falselist;
							}
#line 1873 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 495 "parser.y" /* yacc.c:1646  */
    { printf("term -> term * unary\n");
							  (yyval.a).term = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  (yyval.a).term->type = maxType((yyvsp[-2].a).term->type, (yyvsp[0].a).unary->type);
							  (yyval.a).term->addr = NewTemp(TopSymbolList, (yyval.a).term->str, (yyval.a).term->type);
							  (yyval.a).term->truelist = NULL;
							  (yyval.a).term->falselist = NULL;
							  switch ((yyval.a).term->type)
							  {
							  	  case BOOL : (yyval.a).term->width = BOOL_WIDTH; break;
							  	  case CHAR : (yyval.a).term->width = CHAR_WIDTH; break;
							  	  case INT  : (yyval.a).term->width = INT_WIDTH; break;
							  	  case FLOAT: (yyval.a).term->width = FLOAT_WIDTH; break;
							  }
							  if ((yyvsp[-2].a).term->type == (yyvsp[0].a).unary->type)
							  {
							  	  if ((yyvsp[-2].a).term->type == INT)
							  	  	  Gen(OIntMultiply, (yyvsp[-2].a).term->addr, (yyvsp[0].a).unary->addr, (yyval.a).term->addr, (yyvsp[-2].a).term->str, (yyvsp[0].a).unary->str, (yyval.a).term->str); 
							  	  else if ((yyvsp[-2].a).expr->type == FLOAT)
							  	  	  Gen(OFloatMultiply, (yyvsp[-2].a).term->addr, (yyvsp[0].a).unary->addr, (yyval.a).term->addr, (yyvsp[-2].a).term->str, (yyvsp[0].a).unary->str, (yyval.a).term->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else if ((yyvsp[-2].a).term->type > (yyvsp[0].a).unary->type)
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType((yyvsp[0].a).unary->addr, (yyvsp[0].a).unary->type, (yyvsp[0].a).unary->str, (yyvsp[-2].a).term->type, &Temp, TopSymbolList);
							  	  if ((yyvsp[-2].a).term->type == INT)
							  	  	  Gen(OIntMultiply, (yyvsp[-2].a).term->addr, Temp.addr, (yyval.a).term->addr, (yyvsp[-2].a).term->str, Temp.str, (yyval.a).term->str);
							  	  else if ((yyvsp[-2].a).term->type == FLOAT)
							  	  	  Gen(OFloatMultiply, (yyvsp[-2].a).term->addr, Temp.addr, (yyval.a).term->addr, (yyvsp[-2].a).term->str, Temp.str, (yyval.a).term->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType((yyvsp[-2].a).term->addr, (yyvsp[-2].a).term->type, (yyvsp[-2].a).term->str, (yyvsp[0].a).unary->type, &Temp, TopSymbolList);
							  	  if ((yyvsp[0].a).unary->type == INT)
							  	  	  Gen(OIntMultiply, Temp.addr, (yyvsp[0].a).unary->addr, (yyval.a).term->addr, Temp.str, (yyvsp[0].a).unary->str, (yyval.a).term->str);
							  	  else if ((yyvsp[0].a).unary->type == FLOAT)
							  	  	  Gen(OFloatMultiply, Temp.addr, (yyvsp[0].a).unary->addr, (yyval.a).term->addr, Temp.str, (yyvsp[0].a).unary->str, (yyval.a).term->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							}
#line 1923 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 540 "parser.y" /* yacc.c:1646  */
    { printf("term -> term / unary\n");
							  (yyval.a).term = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  (yyval.a).term->type = maxType((yyvsp[-2].a).term->type, (yyvsp[0].a).unary->type);
							  (yyval.a).term->addr = NewTemp(TopSymbolList, (yyval.a).term->str, (yyval.a).term->type);
							  (yyval.a).term->truelist = NULL;
							  (yyval.a).term->falselist = NULL;
							  switch ((yyval.a).term->type)
							  {
							  	  case BOOL : (yyval.a).term->width = BOOL_WIDTH; break;
							  	  case CHAR : (yyval.a).term->width = CHAR_WIDTH; break;
							  	  case INT  : (yyval.a).term->width = INT_WIDTH; break;
							  	  case FLOAT: (yyval.a).term->width = FLOAT_WIDTH; break;
							  }
							  if ((yyvsp[-2].a).term->type == (yyvsp[0].a).unary->type)
							  {
							  	  if ((yyvsp[-2].a).term->type == INT)
							  	  	  Gen(OIntDivide, (yyvsp[-2].a).term->addr, (yyvsp[0].a).unary->addr, (yyval.a).term->addr, (yyvsp[-2].a).term->str, (yyvsp[0].a).unary->str, (yyval.a).term->str); 
							  	  else if ((yyvsp[-2].a).expr->type == FLOAT)
							  	  	  Gen(OFloatDivide, (yyvsp[-2].a).term->addr, (yyvsp[0].a).unary->addr, (yyval.a).term->addr, (yyvsp[-2].a).term->str, (yyvsp[0].a).unary->str, (yyval.a).term->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else if ((yyvsp[-2].a).term->type > (yyvsp[0].a).unary->type)
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType((yyvsp[0].a).unary->addr, (yyvsp[0].a).unary->type, (yyvsp[0].a).unary->str, (yyvsp[-2].a).term->type, &Temp, TopSymbolList);
							  	  if ((yyvsp[-2].a).term->type == INT)
							  	  	  Gen(OIntDivide, (yyvsp[-2].a).term->addr, Temp.addr, (yyval.a).term->addr, (yyvsp[-2].a).term->str, Temp.str, (yyval.a).term->str);
							  	  else if ((yyvsp[-2].a).term->type == FLOAT)
							  	  	  Gen(OFloatDivide, (yyvsp[-2].a).term->addr, Temp.addr, (yyval.a).term->addr, (yyvsp[-2].a).term->str, Temp.str, (yyval.a).term->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							  else
							  {
							  	  struct nonterminalNode Temp;
							  	  widenType((yyvsp[-2].a).term->addr, (yyvsp[-2].a).term->type, (yyvsp[-2].a).term->str, (yyvsp[0].a).unary->type, &Temp, TopSymbolList);
							  	  if ((yyvsp[0].a).unary->type == INT)
							  	  	  Gen(OIntDivide, Temp.addr, (yyvsp[0].a).unary->addr, (yyval.a).term->addr, Temp.str, (yyvsp[0].a).unary->str, (yyval.a).term->str);
							  	  else if ((yyvsp[0].a).unary->type == FLOAT)
							  	  	  Gen(OFloatDivide, Temp.addr, (yyvsp[0].a).unary->addr, (yyval.a).term->addr, Temp.str, (yyvsp[0].a).unary->str, (yyval.a).term->str);
							  	  else
							  	  	  yyerror("非整型或浮点型运算");
							  }
							}
#line 1973 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 585 "parser.y" /* yacc.c:1646  */
    { (yyval.a).term = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  printf("term -> unary\n"); 
							  strcpy( (yyval.a).term->str, (yyvsp[0].a).unary->str );
							  (yyval.a).term->type = (yyvsp[0].a).unary->type;
							  (yyval.a).term->addr = (yyvsp[0].a).unary->addr;
							  (yyval.a).term->width = (yyvsp[0].a).unary->width;
							  (yyval.a).term->truelist = (yyvsp[0].a).unary->truelist;
							  (yyval.a).term->falselist = (yyvsp[0].a).unary->falselist;
							}
#line 1987 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 596 "parser.y" /* yacc.c:1646  */
    { printf("unary -> ! unary\n"); 
							  (yyval.a).unary = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  strcpy( (yyval.a).unary->str, (yyvsp[0].a).unary->str);
							  (yyval.a).unary->type = (yyvsp[0].a).unary->type;
							  (yyval.a).unary->addr = (yyvsp[0].a).unary->addr;
							  (yyval.a).unary->width = (yyvsp[0].a).unary->width;
							  (yyval.a).unary->truelist = (yyvsp[0].a).unary->falselist;
							  (yyval.a).unary->falselist = (yyvsp[0].a).unary->truelist;
							}
#line 2001 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 606 "parser.y" /* yacc.c:1646  */
    { printf("unary -> - unary\n");
	 						  (yyval.a).unary = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
	 						  (yyval.a).unary->type = (yyvsp[0].a).unary->type;
	 						  (yyval.a).unary->width = (yyvsp[0].a).unary->width;
	 						  (yyval.a).unary->addr = NewTemp(TopSymbolList, (yyval.a).unary->str, (yyval.a).unary->width);
	 						  (yyval.a).unary->truelist = NULL;
	 						  (yyval.a).unary->falselist = NULL;
	 						  if ((yyvsp[0].a).unary->type == INT)
	 						  	  Gen(OIntUminus, (yyvsp[0].a).unary->addr, 0, (yyval.a).unary->addr, (yyvsp[0].a).unary->str, "", (yyval.a).unary->str);
	 						  else if ((yyvsp[0].a).unary->type == FLOAT)
	 						  	  Gen(OFloatUminus, (yyvsp[0].a).unary->addr, 0, (yyval.a).unary->addr, (yyvsp[0].a).unary->str, "", (yyval.a).unary->str);
	 						  else
	 						  	  yyerror("非整型或浮点型运算");
	 						}
#line 2020 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 620 "parser.y" /* yacc.c:1646  */
    { (yyval.a).unary = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
	 						  printf("unary -> factor\n");
	 						  strcpy( (yyval.a).unary->str, (yyvsp[0].a).factor->str );
							  (yyval.a).unary->type = (yyvsp[0].a).factor->type;
							  (yyval.a).unary->addr = (yyvsp[0].a).factor->addr;
							  (yyval.a).unary->width = (yyvsp[0].a).factor->width;
							  (yyval.a).unary->truelist = (yyvsp[0].a).factor->truelist;
							  (yyval.a).unary->falselist = (yyvsp[0].a).factor->falselist;
							}
#line 2034 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 631 "parser.y" /* yacc.c:1646  */
    { (yyval.a).factor = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
							  printf("factor -> ( expr )\n"); 
							  strcpy( (yyval.a).factor->str, (yyvsp[-1].a).expr->str );
							  (yyval.a).factor->type  = (yyvsp[-1].a).expr->type;
							  (yyval.a).factor->addr  = (yyvsp[-1].a).expr->addr;
							  (yyval.a).factor->width = (yyvsp[-1].a).expr->width;
							  (yyval.a).factor->truelist = (yyvsp[-1].a).expr->truelist;
							  (yyval.a).factor->falselist = (yyvsp[-1].a).expr->falselist;
							}
#line 2048 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 640 "parser.y" /* yacc.c:1646  */
    { (yyval.a).factor = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
	  						  (yyval.a).factor->truelist = NULL;
	  						  (yyval.a).factor->falselist = NULL;
	  						  printf("factor -> id\n"); 
	  						  struct SymbolElem * p;
							  p = LookUpAllSymbolList( TopSymbolList, (yyvsp[0].a).id->name );
							  if( p != NULL )
							  {
								  strcpy( (yyval.a).factor->str, p->name );
								  (yyval.a).factor->type  = p->type;
								  (yyval.a).factor->addr  = p->addr;
								  (yyval.a).factor->width = p->width;
							  }							    
							  else
							  {
							      yyerror( "变量名没有定义" );
								  strcpy( (yyval.a).factor->str, "no_id_defined" ); /*容错处理*/
								  (yyval.a).factor->type = INT;
								  (yyval.a).factor->addr = -1;
								  (yyval.a).factor->width = INT_WIDTH;							    
							  }
							}
#line 2075 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 662 "parser.y" /* yacc.c:1646  */
    { (yyval.a).factor = (struct nonterminalNode *)malloc(sizeof(struct nonterminalNode));
	  						  (yyval.a).factor->truelist = NULL;
	  						  (yyval.a).factor->falselist = NULL;
	  						  printf("factor -> const\n");
	  						  struct ConstElem * p; 
							  p = LookUpConstList( (yyvsp[0].a).constval->type, (yyvsp[0].a).constval->value, (yyvsp[0].a).constval->width ) ;
							  if( p == NULL )
								  p = AddToConstList( (yyvsp[0].a).constval->str, (yyvsp[0].a).constval->type, (yyvsp[0].a).constval->value, (yyvsp[0].a).constval->width );
							  strcpy( (yyval.a).factor->str, (yyvsp[0].a).constval->str );
							  (yyval.a).factor->type  = (yyvsp[0].a).constval->type;
							  (yyval.a).factor->addr  = p->addr;
							  (yyval.a).factor->width = p->width;
							}
#line 2093 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2097 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 677 "parser.y" /* yacc.c:1906  */


