/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "cminus.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char * message);


#line 88 "cminus.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "cminus.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_VOID = 8,                       /* VOID  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_NUM = 10,                       /* NUM  */
  YYSYMBOL_MAIS = 11,                      /* MAIS  */
  YYSYMBOL_MENOS = 12,                     /* MENOS  */
  YYSYMBOL_VEZES = 13,                     /* VEZES  */
  YYSYMBOL_DIVISAO = 14,                   /* DIVISAO  */
  YYSYMBOL_MENOR = 15,                     /* MENOR  */
  YYSYMBOL_MENORIGUAL = 16,                /* MENORIGUAL  */
  YYSYMBOL_MAIOR = 17,                     /* MAIOR  */
  YYSYMBOL_MAIORIGUAL = 18,                /* MAIORIGUAL  */
  YYSYMBOL_IGUAL = 19,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 20,                 /* DIFERENTE  */
  YYSYMBOL_ATRIBUICAO = 21,                /* ATRIBUICAO  */
  YYSYMBOL_LPAREN = 22,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 23,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 24,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 25,                  /* RBRACKET  */
  YYSYMBOL_LKEY = 26,                      /* LKEY  */
  YYSYMBOL_RKEY = 27,                      /* RKEY  */
  YYSYMBOL_SEMI = 28,                      /* SEMI  */
  YYSYMBOL_COMMA = 29,                     /* COMMA  */
  YYSYMBOL_ERROR = 30,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_programa = 32,                  /* programa  */
  YYSYMBOL_declaration_list = 33,          /* declaration_list  */
  YYSYMBOL_declaration = 34,               /* declaration  */
  YYSYMBOL_var_declaration = 35,           /* var_declaration  */
  YYSYMBOL_type_specifier = 36,            /* type_specifier  */
  YYSYMBOL_fun_declaration = 37,           /* fun_declaration  */
  YYSYMBOL_params = 38,                    /* params  */
  YYSYMBOL_param_list = 39,                /* param_list  */
  YYSYMBOL_param = 40,                     /* param  */
  YYSYMBOL_compound_stmt = 41,             /* compound_stmt  */
  YYSYMBOL_local_declarations = 42,        /* local_declarations  */
  YYSYMBOL_statement_list = 43,            /* statement_list  */
  YYSYMBOL_statement = 44,                 /* statement  */
  YYSYMBOL_expression_stmt = 45,           /* expression_stmt  */
  YYSYMBOL_selection_stmt = 46,            /* selection_stmt  */
  YYSYMBOL_iteration_stmt = 47,            /* iteration_stmt  */
  YYSYMBOL_return_stmt = 48,               /* return_stmt  */
  YYSYMBOL_expression = 49,                /* expression  */
  YYSYMBOL_var = 50,                       /* var  */
  YYSYMBOL_simple_expression = 51,         /* simple_expression  */
  YYSYMBOL_relop = 52,                     /* relop  */
  YYSYMBOL_additive_expression = 53,       /* additive_expression  */
  YYSYMBOL_addop = 54,                     /* addop  */
  YYSYMBOL_term = 55,                      /* term  */
  YYSYMBOL_mulop = 56,                     /* mulop  */
  YYSYMBOL_factor = 57,                    /* factor  */
  YYSYMBOL_call = 58,                      /* call  */
  YYSYMBOL_args = 59,                      /* args  */
  YYSYMBOL_arg_list = 60,                  /* arg_list  */
  YYSYMBOL_id = 61,                        /* id  */
  YYSYMBOL_num = 62                        /* num  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   97

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    37,    37,    41,    50,    54,    56,    60,    65,    74,
      78,    84,    94,    96,   100,   109,   113,   118,   126,   133,
     143,   146,   156,   159,   161,   163,   165,   167,   171,   173,
     177,   182,   190,   197,   199,   205,   211,   215,   219,   227,
     232,   236,   238,   240,   242,   244,   246,   250,   255,   259,
     261,   265,   270,   274,   276,   280,   282,   284,   286,   290,
     297,   300,   303,   312,   317,   323
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "RETURN", "INT", "VOID", "ID", "NUM", "MAIS", "MENOS", "VEZES",
  "DIVISAO", "MENOR", "MENORIGUAL", "MAIOR", "MAIORIGUAL", "IGUAL",
  "DIFERENTE", "ATRIBUICAO", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "LKEY", "RKEY", "SEMI", "COMMA", "ERROR", "$accept", "programa",
  "declaration_list", "declaration", "var_declaration", "type_specifier",
  "fun_declaration", "params", "param_list", "param", "compound_stmt",
  "local_declarations", "statement_list", "statement", "expression_stmt",
  "selection_stmt", "iteration_stmt", "return_stmt", "expression", "var",
  "simple_expression", "relop", "additive_expression", "addop", "term",
  "mulop", "factor", "call", "args", "arg_list", "id", "num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      36,   -88,   -88,    49,    36,   -88,   -88,    38,   -88,   -88,
     -88,   -88,   -11,    53,    41,   -88,    30,    38,    32,    43,
     -88,   -88,    48,    50,    51,    36,    52,    54,   -88,   -88,
     -88,   -88,   -88,    36,   -88,    38,     0,   -10,    56,    60,
      28,    24,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
      57,    62,   -88,    47,    55,   -88,   -88,    -1,   -88,    24,
      24,   -88,    58,    61,   -88,    24,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,    24,    24,   -88,   -88,    24,    24,
      24,    64,    65,   -88,   -88,   -88,   -88,    59,    55,   -88,
     -88,    66,    46,    67,    26,    26,   -88,    24,   -88,    72,
     -88,   -88,    26,   -88
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,    64,     0,     0,     0,     7,    10,     0,     0,    12,
      15,    65,     0,    16,     0,     0,     0,     0,    20,    11,
      14,     8,    17,    22,    19,     0,     0,     0,     0,     0,
       0,     0,    18,    29,    24,    21,    23,    25,    26,    27,
       0,    56,    36,    40,    48,    52,    57,    37,    58,     0,
       0,    33,     0,     0,    28,     0,    49,    50,    42,    41,
      43,    44,    45,    46,     0,     0,    53,    54,     0,    61,
       0,     0,     0,    34,    55,    35,    56,    39,    47,    51,
      63,     0,    60,     0,     0,     0,    59,     0,    38,    30,
      32,    62,     0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,   -88,    77,    63,    -9,   -88,   -88,   -88,    68,
      70,   -88,   -88,   -87,   -88,   -88,   -88,   -88,   -40,   -33,
     -88,   -88,    16,   -88,    20,   -88,    13,   -88,   -88,   -88,
      -5,    83
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    18,    19,    20,
      44,    33,    36,    45,    46,    47,    48,    49,    50,    51,
      52,    74,    53,    75,    54,    78,    55,    56,    91,    92,
      57,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      62,    63,    12,    38,    17,    39,    40,    99,   100,    11,
      21,    13,    23,    14,    14,   103,    17,    15,    15,    81,
      82,    79,    41,    80,    35,    85,    28,    42,    43,    38,
      37,    39,    40,    11,    21,    11,    21,    11,    21,    90,
      93,    86,    86,     1,     2,    86,    41,    11,    41,     9,
      41,    21,    28,   -13,    43,    24,    61,   101,    66,    67,
       1,    16,    68,    69,    70,    71,    72,    73,    76,    77,
      66,    67,    25,    26,    27,    97,   102,    28,    59,    32,
      31,    10,    60,    65,    84,    64,    83,    94,    95,    96,
      87,    89,    98,    30,    29,    88,    34,    22
};

static const yytype_int8 yycheck[] =
{
      40,    41,     7,     3,    13,     5,     6,    94,    95,     9,
      10,    22,    17,    24,    24,   102,    25,    28,    28,    59,
      60,    22,    22,    24,    33,    65,    26,    27,    28,     3,
      35,     5,     6,     9,    10,     9,    10,     9,    10,    79,
      80,    74,    75,     7,     8,    78,    22,     9,    22,     0,
      22,    10,    26,    23,    28,    23,    28,    97,    11,    12,
       7,     8,    15,    16,    17,    18,    19,    20,    13,    14,
      11,    12,    29,    25,    24,    29,     4,    26,    22,    25,
      28,     4,    22,    21,    23,    28,    28,    23,    23,    23,
      74,    78,    25,    25,    24,    75,    33,    14
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,    32,    33,    34,    35,    36,    37,     0,
      34,     9,    61,    22,    24,    28,     8,    36,    38,    39,
      40,    10,    62,    61,    23,    29,    25,    24,    26,    41,
      40,    28,    25,    42,    35,    36,    43,    61,     3,     5,
       6,    22,    27,    28,    41,    44,    45,    46,    47,    48,
      49,    50,    51,    53,    55,    57,    58,    61,    62,    22,
      22,    28,    49,    49,    28,    21,    11,    12,    15,    16,
      17,    18,    19,    20,    52,    54,    13,    14,    56,    22,
      24,    49,    49,    28,    23,    49,    50,    53,    55,    57,
      49,    59,    60,    49,    23,    23,    23,    29,    25,    44,
      44,    49,     4,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    35,    35,    36,
      36,    37,    38,    38,    39,    39,    40,    40,    41,    42,
      42,    43,    43,    44,    44,    44,    44,    44,    45,    45,
      46,    46,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    57,    57,    58,
      59,    59,    60,    60,    61,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     2,     3,     3,     1,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       1,     0,     3,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* programa: declaration_list  */
#line 38 "cminus.y"
                 { savedTree = yyvsp[0];}
#line 1207 "cminus.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 42 "cminus.y"
                 { YYSTYPE t = yyvsp[-1];
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = yyvsp[0];
                     yyval = yyvsp[-1]; }
                     else yyval = yyvsp[0];
                 }
#line 1220 "cminus.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 51 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1226 "cminus.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 55 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1232 "cminus.tab.c"
    break;

  case 6: /* declaration: fun_declaration  */
#line 57 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1238 "cminus.tab.c"
    break;

  case 7: /* var_declaration: type_specifier id SEMI  */
#line 61 "cminus.y"
                 { yyval = yyvsp[-2];
                   yyval->child[0] = yyvsp[-1];
                   yyval->child[0]->kind.var.mem = LOCALK; /* Default, analyze arruma */
                 }
#line 1247 "cminus.tab.c"
    break;

  case 8: /* var_declaration: type_specifier id LBRACKET num RBRACKET SEMI  */
#line 66 "cminus.y"
                 { yyval = yyvsp[-5];
                   yyval->child[0] = yyvsp[-4];
                   yyval->child[0]->kind.var.varKind = VECTORK;
                   yyval->child[0]->kind.var.mem = LOCALK;
                   yyval->child[0]->child[0] = yyvsp[-2];
                 }
#line 1258 "cminus.tab.c"
    break;

  case 9: /* type_specifier: INT  */
#line 75 "cminus.y"
                 { yyval = newStmtNode(INTEGERK);
                   yyval->type = INTEGER_TYPE;
                 }
#line 1266 "cminus.tab.c"
    break;

  case 10: /* type_specifier: VOID  */
#line 79 "cminus.y"
                 { yyval = newStmtNode(VOIDK);
                   yyval->type = VOID_TYPE;
                 }
#line 1274 "cminus.tab.c"
    break;

  case 11: /* fun_declaration: type_specifier id LPAREN params RPAREN compound_stmt  */
#line 85 "cminus.y"
                 { yyval = yyvsp[-5];
                   yyval->child[0] = yyvsp[-4];
                   yyval->child[0]->kind.var.varKind = FUNCTIONK;
                   yyval->child[0]->kind.var.mem = FUNCTION_MEM;
                   yyval->child[0]->child[0] = yyvsp[-2]; /* Parametros */
                   yyval->child[0]->child[1] = yyvsp[0]; /* Corpo */
                 }
#line 1286 "cminus.tab.c"
    break;

  case 12: /* params: param_list  */
#line 95 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1292 "cminus.tab.c"
    break;

  case 13: /* params: VOID  */
#line 97 "cminus.y"
                 { yyval = NULL; }
#line 1298 "cminus.tab.c"
    break;

  case 14: /* param_list: param_list COMMA param  */
#line 101 "cminus.y"
                 { YYSTYPE t = yyvsp[-2];
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = yyvsp[0];
                     yyval = yyvsp[-2]; }
                     else yyval = yyvsp[0];
                 }
#line 1311 "cminus.tab.c"
    break;

  case 15: /* param_list: param  */
#line 110 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1317 "cminus.tab.c"
    break;

  case 16: /* param: type_specifier id  */
#line 114 "cminus.y"
                 { yyval = yyvsp[-1];
                   yyval->child[0] = yyvsp[0];
                   yyval->child[0]->kind.var.mem = PARAMK;
                 }
#line 1326 "cminus.tab.c"
    break;

  case 17: /* param: type_specifier id LBRACKET RBRACKET  */
#line 119 "cminus.y"
                 { yyval = yyvsp[-3];
                   yyval->child[0] = yyvsp[-2];
                   yyval->child[0]->kind.var.mem = PARAMK;
                   yyval->child[0]->kind.var.varKind = VECTORK;
                 }
#line 1336 "cminus.tab.c"
    break;

  case 18: /* compound_stmt: LKEY local_declarations statement_list RKEY  */
#line 127 "cminus.y"
                 { yyval = newStmtNode(COMPK);
                   yyval->child[0] = yyvsp[-2];
                   yyval->child[1] = yyvsp[-1];
                 }
#line 1345 "cminus.tab.c"
    break;

  case 19: /* local_declarations: local_declarations var_declaration  */
#line 134 "cminus.y"
                 { YYSTYPE t = yyvsp[-1];
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = yyvsp[0];
                     yyval = yyvsp[-1]; }
                     else yyval = yyvsp[0];
                 }
#line 1358 "cminus.tab.c"
    break;

  case 20: /* local_declarations: %empty  */
#line 143 "cminus.y"
                 { yyval = NULL; }
#line 1364 "cminus.tab.c"
    break;

  case 21: /* statement_list: statement_list statement  */
#line 147 "cminus.y"
                 { YYSTYPE t = yyvsp[-1];
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = yyvsp[0];
                     yyval = yyvsp[-1]; }
                     else yyval = yyvsp[0];
                 }
#line 1377 "cminus.tab.c"
    break;

  case 22: /* statement_list: %empty  */
#line 156 "cminus.y"
                 { yyval = NULL; }
#line 1383 "cminus.tab.c"
    break;

  case 23: /* statement: expression_stmt  */
#line 160 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1389 "cminus.tab.c"
    break;

  case 24: /* statement: compound_stmt  */
#line 162 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1395 "cminus.tab.c"
    break;

  case 25: /* statement: selection_stmt  */
#line 164 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1401 "cminus.tab.c"
    break;

  case 26: /* statement: iteration_stmt  */
#line 166 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1407 "cminus.tab.c"
    break;

  case 27: /* statement: return_stmt  */
#line 168 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1413 "cminus.tab.c"
    break;

  case 28: /* expression_stmt: expression SEMI  */
#line 172 "cminus.y"
                 { yyval = yyvsp[-1]; }
#line 1419 "cminus.tab.c"
    break;

  case 29: /* expression_stmt: SEMI  */
#line 174 "cminus.y"
                 { yyval = NULL; }
#line 1425 "cminus.tab.c"
    break;

  case 30: /* selection_stmt: IF LPAREN expression RPAREN statement  */
#line 178 "cminus.y"
                 { yyval = newStmtNode(IFK);
                   yyval->child[0] = yyvsp[-2];
                   yyval->child[1] = yyvsp[0];
                 }
#line 1434 "cminus.tab.c"
    break;

  case 31: /* selection_stmt: IF LPAREN expression RPAREN statement ELSE statement  */
#line 183 "cminus.y"
                 { yyval = newStmtNode(IFK);
                   yyval->child[0] = yyvsp[-4];
                   yyval->child[1] = yyvsp[-2];
                   yyval->child[2] = yyvsp[0];
                 }
#line 1444 "cminus.tab.c"
    break;

  case 32: /* iteration_stmt: WHILE LPAREN expression RPAREN statement  */
#line 191 "cminus.y"
                 { yyval = newStmtNode(WHILEK);
                   yyval->child[0] = yyvsp[-2];
                   yyval->child[1] = yyvsp[0];
                 }
#line 1453 "cminus.tab.c"
    break;

  case 33: /* return_stmt: RETURN SEMI  */
#line 198 "cminus.y"
                 { yyval = newStmtNode(RETURNK); }
#line 1459 "cminus.tab.c"
    break;

  case 34: /* return_stmt: RETURN expression SEMI  */
#line 200 "cminus.y"
                 { yyval = newStmtNode(RETURNK);
                   yyval->child[0] = yyvsp[-1];
                 }
#line 1467 "cminus.tab.c"
    break;

  case 35: /* expression: var ATRIBUICAO expression  */
#line 206 "cminus.y"
                 { yyval = newExpNode(ATRIBK);
                   yyval->op = ATRIBUICAO;
                   yyval->child[0] = yyvsp[-2];
                   yyval->child[1] = yyvsp[0];
                 }
#line 1477 "cminus.tab.c"
    break;

  case 36: /* expression: simple_expression  */
#line 212 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1483 "cminus.tab.c"
    break;

  case 37: /* var: id  */
#line 216 "cminus.y"
                 { yyval = yyvsp[0]; 
                   yyval->kind.var.acesso = ACCESSK; 
                 }
#line 1491 "cminus.tab.c"
    break;

  case 38: /* var: id LBRACKET expression RBRACKET  */
#line 220 "cminus.y"
                 { yyval = yyvsp[-3];
                   yyval->kind.var.acesso = ACCESSK;
                   yyval->kind.var.varKind = VECTORK;
                   yyval->child[0] = yyvsp[-1];
                 }
#line 1501 "cminus.tab.c"
    break;

  case 39: /* simple_expression: additive_expression relop additive_expression  */
#line 228 "cminus.y"
                 { yyval = yyvsp[-1];
                   yyval->child[0] = yyvsp[-2];
                   yyval->child[1] = yyvsp[0];
                 }
#line 1510 "cminus.tab.c"
    break;

  case 40: /* simple_expression: additive_expression  */
#line 233 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1516 "cminus.tab.c"
    break;

  case 41: /* relop: MENORIGUAL  */
#line 237 "cminus.y"
                 { yyval = newExpNode(RELK); yyval->op = MENORIGUAL; }
#line 1522 "cminus.tab.c"
    break;

  case 42: /* relop: MENOR  */
#line 239 "cminus.y"
                 { yyval = newExpNode(RELK); yyval->op = MENOR; }
#line 1528 "cminus.tab.c"
    break;

  case 43: /* relop: MAIOR  */
#line 241 "cminus.y"
                 { yyval = newExpNode(RELK); yyval->op = MAIOR; }
#line 1534 "cminus.tab.c"
    break;

  case 44: /* relop: MAIORIGUAL  */
#line 243 "cminus.y"
                 { yyval = newExpNode(RELK); yyval->op = MAIORIGUAL; }
#line 1540 "cminus.tab.c"
    break;

  case 45: /* relop: IGUAL  */
#line 245 "cminus.y"
                 { yyval = newExpNode(RELK); yyval->op = IGUAL; }
#line 1546 "cminus.tab.c"
    break;

  case 46: /* relop: DIFERENTE  */
#line 247 "cminus.y"
                 { yyval = newExpNode(RELK); yyval->op = DIFERENTE; }
#line 1552 "cminus.tab.c"
    break;

  case 47: /* additive_expression: additive_expression addop term  */
#line 251 "cminus.y"
                 { yyval = yyvsp[-1];
                   yyval->child[0] = yyvsp[-2];
                   yyval->child[1] = yyvsp[0];
                 }
#line 1561 "cminus.tab.c"
    break;

  case 48: /* additive_expression: term  */
#line 256 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1567 "cminus.tab.c"
    break;

  case 49: /* addop: MAIS  */
#line 260 "cminus.y"
                 { yyval = newExpNode(ARITHK); yyval->op = MAIS; }
#line 1573 "cminus.tab.c"
    break;

  case 50: /* addop: MENOS  */
#line 262 "cminus.y"
                 { yyval = newExpNode(ARITHK); yyval->op = MENOS; }
#line 1579 "cminus.tab.c"
    break;

  case 51: /* term: term mulop factor  */
#line 266 "cminus.y"
                 { yyval = yyvsp[-1];
                   yyval->child[0] = yyvsp[-2];
                   yyval->child[1] = yyvsp[0];
                 }
#line 1588 "cminus.tab.c"
    break;

  case 52: /* term: factor  */
#line 271 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1594 "cminus.tab.c"
    break;

  case 53: /* mulop: VEZES  */
#line 275 "cminus.y"
                 { yyval = newExpNode(ARITHK); yyval->op = VEZES; }
#line 1600 "cminus.tab.c"
    break;

  case 54: /* mulop: DIVISAO  */
#line 277 "cminus.y"
                 { yyval = newExpNode(ARITHK); yyval->op = DIVISAO; }
#line 1606 "cminus.tab.c"
    break;

  case 55: /* factor: LPAREN expression RPAREN  */
#line 281 "cminus.y"
                 { yyval = yyvsp[-1]; }
#line 1612 "cminus.tab.c"
    break;

  case 56: /* factor: var  */
#line 283 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1618 "cminus.tab.c"
    break;

  case 57: /* factor: call  */
#line 285 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1624 "cminus.tab.c"
    break;

  case 58: /* factor: num  */
#line 287 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1630 "cminus.tab.c"
    break;

  case 59: /* call: id LPAREN args RPAREN  */
#line 291 "cminus.y"
                 { yyval = yyvsp[-3];
                   yyval->kind.var.varKind = CALLK;
                   yyval->child[0] = yyvsp[-1];
                 }
#line 1639 "cminus.tab.c"
    break;

  case 60: /* args: arg_list  */
#line 298 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1645 "cminus.tab.c"
    break;

  case 61: /* args: %empty  */
#line 300 "cminus.y"
                 { yyval = NULL; }
#line 1651 "cminus.tab.c"
    break;

  case 62: /* arg_list: arg_list COMMA expression  */
#line 304 "cminus.y"
                 { YYSTYPE t = yyvsp[-2];
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = yyvsp[0];
                     yyval = yyvsp[-2]; }
                     else yyval = yyvsp[0];
                 }
#line 1664 "cminus.tab.c"
    break;

  case 63: /* arg_list: expression  */
#line 313 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1670 "cminus.tab.c"
    break;

  case 64: /* id: ID  */
#line 318 "cminus.y"
                 { yyval = newVarNode(IDK);
                   yyval->kind.var.attr.name = copyString(tokenString);
                 }
#line 1678 "cminus.tab.c"
    break;

  case 65: /* num: NUM  */
#line 324 "cminus.y"
                 { yyval = newVarNode(CONSTK);
                   yyval->kind.var.attr.val = atoi(tokenString);
                 }
#line 1686 "cminus.tab.c"
    break;


#line 1690 "cminus.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 329 "cminus.y"


int yyerror(char * message)
{ fprintf(listing,"ERRO SINTÁTICO: %s LINHA: %d\n",tokenString,lineno);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with e.g. the TINY parser
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}
