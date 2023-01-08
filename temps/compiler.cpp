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
#line 1 "compiler.ypp"

    #include <fstream>
    #include <iostream>
    #include "main.hpp"

    extern "C" {
        int yylex ( void );
    }  

    #include "../utilities/Scope/Scope.hpp"
    #include "../utilities/Scope/impl/Scope.hpp"

    Scope * pCurrentScope = Scope :: pGlobalScope;
    Scope * pNonClassScope;
    std :: ofstream debugOut ( "debug.out" );

    unsigned long long int errorCount = 0;

    using StringList               = std :: list < char const * >;
    using ArraytypePair            = TypeEntry :: ArraytypePair;
    using ParameterDeclarationPair = Scope :: ParameterDeclarationPair;
    using ParameterDeclarationList = Scope :: ParameterDeclarationList;
    using IdentifierAccessPair     = std :: pair < char const *, SymbolEntry * >;
    using IdentifierList           = std :: list < SymbolEntry * >;

#line 97 "compiler.cpp"

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

#include "compiler.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_INT_NUMBER = 3,               /* T_INT_NUMBER  */
  YYSYMBOL_T_CHAR_VALUE = 4,               /* T_CHAR_VALUE  */
  YYSYMBOL_T_FLOAT_NUMBER = 5,             /* T_FLOAT_NUMBER  */
  YYSYMBOL_T_BOOL_VALUE = 6,               /* T_BOOL_VALUE  */
  YYSYMBOL_T_STRING_VALUE = 7,             /* T_STRING_VALUE  */
  YYSYMBOL_T_MAIN_IDENTIFIER = 8,          /* T_MAIN_IDENTIFIER  */
  YYSYMBOL_T_CLASS = 9,                    /* T_CLASS  */
  YYSYMBOL_T_IF = 10,                      /* T_IF  */
  YYSYMBOL_T_WHILE = 11,                   /* T_WHILE  */
  YYSYMBOL_T_FOR = 12,                     /* T_FOR  */
  YYSYMBOL_T_CONST = 13,                   /* T_CONST  */
  YYSYMBOL_T_TYPE = 14,                    /* T_TYPE  */
  YYSYMBOL_T_IDENTIFIER = 15,              /* T_IDENTIFIER  */
  YYSYMBOL_T_BAND = 16,                    /* T_BAND  */
  YYSYMBOL_T_BOR = 17,                     /* T_BOR  */
  YYSYMBOL_UNOT = 18,                      /* UNOT  */
  YYSYMBOL_19_ = 19,                       /* '-'  */
  YYSYMBOL_20_ = 20,                       /* '+'  */
  YYSYMBOL_21_ = 21,                       /* '*'  */
  YYSYMBOL_22_ = 22,                       /* '/'  */
  YYSYMBOL_UMINUS = 23,                    /* UMINUS  */
  YYSYMBOL_24_ = 24,                       /* '('  */
  YYSYMBOL_25_ = 25,                       /* ')'  */
  YYSYMBOL_26_ = 26,                       /* '.'  */
  YYSYMBOL_27_ = 27,                       /* ','  */
  YYSYMBOL_28_ = 28,                       /* '!'  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* '['  */
  YYSYMBOL_31_ = 31,                       /* ']'  */
  YYSYMBOL_32_ = 32,                       /* '{'  */
  YYSYMBOL_33_ = 33,                       /* '}'  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_N_START = 36,                   /* N_START  */
  YYSYMBOL_N_CONSTANT_VALUE = 37,          /* N_CONSTANT_VALUE  */
  YYSYMBOL_N_SYMBOL_ACCESS = 38,           /* N_SYMBOL_ACCESS  */
  YYSYMBOL_N_NON_ARRAY_SYMBOL_ACCESS = 39, /* N_NON_ARRAY_SYMBOL_ACCESS  */
  YYSYMBOL_M_PARAMETER_LOOKUP_SCOPE_CHANGE = 40, /* M_PARAMETER_LOOKUP_SCOPE_CHANGE  */
  YYSYMBOL_N_ARRAY_SYMBOL_ACCESS = 41,     /* N_ARRAY_SYMBOL_ACCESS  */
  YYSYMBOL_N_VARIABLE_ACCESS = 42,         /* N_VARIABLE_ACCESS  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_M_CLASS_ACCESS_SCOPE_CHANGE = 44, /* M_CLASS_ACCESS_SCOPE_CHANGE  */
  YYSYMBOL_N_PARAMETER = 45,               /* N_PARAMETER  */
  YYSYMBOL_N_PARAMETER_LIST = 46,          /* N_PARAMETER_LIST  */
  YYSYMBOL_N_MIXED_TYPE = 47,              /* N_MIXED_TYPE  */
  YYSYMBOL_N_EXPRESSION = 48,              /* N_EXPRESSION  */
  YYSYMBOL_N_BOOL_EXPRESSION = 49,         /* N_BOOL_EXPRESSION  */
  YYSYMBOL_N_DECLARATION = 50,             /* N_DECLARATION  */
  YYSYMBOL_N_BLOCK_SCOPE_DECLARATION = 51, /* N_BLOCK_SCOPE_DECLARATION  */
  YYSYMBOL_N_VARIABLE_DECLARATION = 52,    /* N_VARIABLE_DECLARATION  */
  YYSYMBOL_N_ARRAY_SUBSCRIPT = 53,         /* N_ARRAY_SUBSCRIPT  */
  YYSYMBOL_N_CLASS_DECLARATION = 54,       /* N_CLASS_DECLARATION  */
  YYSYMBOL_M_BLOCK_BEGIN = 55,             /* M_BLOCK_BEGIN  */
  YYSYMBOL_N_FUNCTION_DECLARATION = 56,    /* N_FUNCTION_DECLARATION  */
  YYSYMBOL_N_PARAMETER_DECLARATION = 57,   /* N_PARAMETER_DECLARATION  */
  YYSYMBOL_N_PARAMETER_DECLARATION_LIST = 58, /* N_PARAMETER_DECLARATION_LIST  */
  YYSYMBOL_N_BLOCK = 59,                   /* N_BLOCK  */
  YYSYMBOL_N_STATEMENT = 60,               /* N_STATEMENT  */
  YYSYMBOL_N_ASSIGNMENT = 61,              /* N_ASSIGNMENT  */
  YYSYMBOL_N_IF_STATEMENT = 62,            /* N_IF_STATEMENT  */
  YYSYMBOL_N_WHILE_STATEMENT = 63,         /* N_WHILE_STATEMENT  */
  YYSYMBOL_N_FOR_STATEMENT = 64            /* N_FOR_STATEMENT  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   274


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
       2,     2,     2,    28,     2,     2,     2,     2,     2,     2,
      24,    25,    21,    20,    27,    19,    26,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    34,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      15,    16,    17,    18,    23
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   117,   117,   133,   134,   135,   136,   137,   140,   141,
     144,   155,   169,   172,   187,   187,   208,   216,   219,   222,
     225,   229,   236,   237,   240,   241,   242,   243,   244,   245,
     246,   247,   251,   252,   253,   254,   255,   259,   260,   261,
     262,   266,   267,   271,   274,   278,   281,   288,   297,   306,
     319,   326,   331,   332,   336,   340,   346,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   374,   378,   382,   386
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
  "\"end of file\"", "error", "\"invalid token\"", "T_INT_NUMBER",
  "T_CHAR_VALUE", "T_FLOAT_NUMBER", "T_BOOL_VALUE", "T_STRING_VALUE",
  "T_MAIN_IDENTIFIER", "T_CLASS", "T_IF", "T_WHILE", "T_FOR", "T_CONST",
  "T_TYPE", "T_IDENTIFIER", "T_BAND", "T_BOR", "UNOT", "'-'", "'+'", "'*'",
  "'/'", "UMINUS", "'('", "')'", "'.'", "','", "'!'", "';'", "'['", "']'",
  "'{'", "'}'", "'='", "$accept", "N_START", "N_CONSTANT_VALUE",
  "N_SYMBOL_ACCESS", "N_NON_ARRAY_SYMBOL_ACCESS",
  "M_PARAMETER_LOOKUP_SCOPE_CHANGE", "N_ARRAY_SYMBOL_ACCESS",
  "N_VARIABLE_ACCESS", "$@1", "M_CLASS_ACCESS_SCOPE_CHANGE", "N_PARAMETER",
  "N_PARAMETER_LIST", "N_MIXED_TYPE", "N_EXPRESSION", "N_BOOL_EXPRESSION",
  "N_DECLARATION", "N_BLOCK_SCOPE_DECLARATION", "N_VARIABLE_DECLARATION",
  "N_ARRAY_SUBSCRIPT", "N_CLASS_DECLARATION", "M_BLOCK_BEGIN",
  "N_FUNCTION_DECLARATION", "N_PARAMETER_DECLARATION",
  "N_PARAMETER_DECLARATION_LIST", "N_BLOCK", "N_STATEMENT", "N_ASSIGNMENT",
  "N_IF_STATEMENT", "N_WHILE_STATEMENT", "N_FOR_STATEMENT", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-24)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -92,    20,    80,   -92,    -5,    13,    47,   -92,    14,    18,
     -92,   -92,    69,   -92,    70,    86,   100,    40,   -92,   -92,
     -92,    93,    89,    60,   117,   -92,   -92,    90,   -92,   -92,
     106,    98,    97,    94,    68,   -92,   -92,   -92,   -92,    60,
      89,   -92,   -92,   111,   -92,    39,   -92,    99,   -92,   -92,
     -92,   -92,   -92,   103,   105,   107,    65,    81,    81,   -92,
     -92,   108,    89,   -92,   -18,    84,    87,   101,   -92,   104,
     -92,   -92,   -92,   -92,     7,     7,   109,   -92,   112,   -92,
      92,   110,   -92,    81,   -92,    89,    81,    81,    81,    81,
     -92,   -92,   -92,     7,   -92,   112,   -10,     1,   113,   -92,
     120,    71,   115,    82,    82,   -92,   -92,   -92,     7,     7,
      90,    90,   114,   108,   118,   119,   120,   125,   -92,   -92,
     -92,    90,   -92,   120,   108,   -92,   108
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      40,     0,     0,     1,     0,     0,    22,    23,     0,     0,
      42,    41,     0,    39,     0,     0,     0,    43,    38,    37,
      50,     0,    44,    53,     0,    45,    40,     0,    46,    22,
       0,     0,    52,     0,     0,    50,     2,    55,    51,     0,
      48,    49,    65,     0,    47,     0,    54,     0,     3,     5,
       4,     6,     7,     0,     0,     0,    11,     0,     0,    56,
      30,    16,     8,     9,    31,     0,     0,     0,    64,     0,
      58,    59,    60,    63,     0,     0,     0,    11,    31,    29,
       0,     0,    13,     0,    14,    43,     0,     0,     0,     0,
      61,    62,    57,     0,    35,    36,     0,     0,     0,    28,
      19,    66,     0,    25,    24,    26,    27,    34,     0,     0,
       0,     0,     0,    21,     0,    18,     0,    32,    33,    67,
      68,     0,    10,     0,    15,    69,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -72,   -91,   -92,   -92,   -92,   -41,   -92,   -92,
     -92,   -92,    34,   -27,   -70,   121,   116,   -92,   -21,   -92,
     102,   -92,   -92,   -92,   -45,   -92,   -92,   -92,   -92,   -92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    60,    61,    62,    81,    63,    78,   102,    84,
     114,   115,     8,    66,    96,     2,     9,    10,    25,    11,
      26,    12,    31,    32,    36,    45,    69,    70,    71,    72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      68,    28,    94,    94,    64,    97,   108,   109,   -17,   113,
      48,    49,    50,    51,    52,   110,    83,   108,   109,    44,
       3,    94,    77,   107,    13,   124,   111,    16,    14,    17,
      79,    80,   126,    95,    95,    93,    94,    94,   117,   118,
      47,    82,    48,    49,    50,    51,    52,    18,     5,    53,
      54,    55,    95,    29,    56,    15,   101,    30,    57,   103,
     104,   105,   106,    58,    23,   119,   120,    95,    95,     4,
      24,    35,    59,    43,    29,     7,   125,     5,   -23,    65,
     -23,     4,    29,     7,    48,    49,    50,    51,    52,     5,
      86,    87,    88,    89,     6,     7,    77,    16,    19,    85,
      57,    41,    20,    88,    89,    58,    86,    87,    88,    89,
      21,    86,    87,    88,    89,    22,    90,    99,    27,    24,
      33,    37,    35,    38,    39,    40,    46,    74,    73,    75,
      91,    76,   -12,    92,   100,    77,    98,    42,   -17,   121,
     112,   116,   109,   122,     0,     0,   123,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67
};

static const yytype_int8 yycheck[] =
{
      45,    22,    74,    75,    45,    75,    16,    17,    26,   100,
       3,     4,     5,     6,     7,    25,    34,    16,    17,    40,
       0,    93,    15,    93,    29,   116,    25,    13,    15,    15,
      57,    58,   123,    74,    75,    28,   108,   109,   108,   109,
       1,    62,     3,     4,     5,     6,     7,    29,     9,    10,
      11,    12,    93,    14,    15,     8,    83,    23,    19,    86,
      87,    88,    89,    24,    24,   110,   111,   108,   109,     1,
      30,    32,    33,    39,    14,    15,   121,     9,    13,    45,
      15,     1,    14,    15,     3,     4,     5,     6,     7,     9,
      19,    20,    21,    22,    14,    15,    15,    13,    29,    15,
      19,    33,    32,    21,    22,    24,    19,    20,    21,    22,
      24,    19,    20,    21,    22,    15,    29,    25,    25,    30,
       3,    15,    32,    25,    27,    31,    15,    24,    29,    24,
      29,    24,    24,    29,    24,    15,    27,    35,    26,    25,
      27,    26,    17,    25,    -1,    -1,    27,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    50,     0,     1,     9,    14,    15,    47,    51,
      52,    54,    56,    29,    15,     8,    13,    15,    29,    29,
      32,    24,    15,    24,    30,    53,    55,    25,    53,    14,
      47,    57,    58,     3,    50,    32,    59,    15,    25,    27,
      31,    33,    55,    47,    53,    60,    15,     1,     3,     4,
       5,     6,     7,    10,    11,    12,    15,    19,    24,    33,
      37,    38,    39,    41,    42,    47,    48,    51,    59,    61,
      62,    63,    64,    29,    24,    24,    24,    15,    42,    48,
      48,    40,    53,    34,    44,    15,    19,    20,    21,    22,
      29,    29,    29,    28,    37,    42,    49,    49,    27,    25,
      24,    48,    43,    48,    48,    48,    48,    49,    16,    17,
      25,    25,    27,    38,    45,    46,    26,    49,    49,    59,
      59,    25,    25,    27,    38,    59,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    37,    37,    37,    38,    38,
      39,    39,    40,    41,    43,    42,    42,    44,    45,    45,
      46,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    49,    49,    49,    49,    49,    50,    50,    50,
      50,    51,    51,    52,    52,    52,    52,    53,    53,    54,
      55,    56,    57,    57,    58,    58,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    62,    63,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     1,     1,     1,     1,     1,     1,     1,
       5,     1,     0,     2,     0,     5,     1,     0,     1,     0,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     2,
       1,     1,     3,     3,     2,     1,     1,     3,     3,     3,
       0,     1,     1,     2,     3,     3,     4,     4,     3,     6,
       0,     5,     1,     0,     4,     2,     4,     3,     2,     2,
       2,     3,     3,     3,     2,     0,     3,     5,     5,     6
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
  case 2: /* N_START: N_DECLARATION T_TYPE T_MAIN_IDENTIFIER '(' ')' N_BLOCK  */
#line 118 "compiler.ypp"
                                             {
        debugOut << "Scope: " << pCurrentScope << '\n' << "With variables:\n";
        for ( auto e : * pCurrentScope->getSymbolTable()->getSymbols() ) {
            debugOut << e->getTypeName() << ' ' << e->getName() << '\n';
        }
        debugOut << "And types:\n";
        for ( auto e : * pCurrentScope->getTypeTable()->getTypes() ) {
            debugOut << e->getName() << ' ' << e->getLength() << '\n';
        }
        debugOut << '\n';
        
        std :: cout << "Error count: " << errorCount << '\n';
    }
#line 1251 "compiler.cpp"
    break;

  case 4: /* N_CONSTANT_VALUE: T_FLOAT_NUMBER  */
#line 134 "compiler.ypp"
                   { }
#line 1257 "compiler.cpp"
    break;

  case 5: /* N_CONSTANT_VALUE: T_CHAR_VALUE  */
#line 135 "compiler.ypp"
                 { }
#line 1263 "compiler.cpp"
    break;

  case 6: /* N_CONSTANT_VALUE: T_BOOL_VALUE  */
#line 136 "compiler.ypp"
                 { }
#line 1269 "compiler.cpp"
    break;

  case 7: /* N_CONSTANT_VALUE: T_STRING_VALUE  */
#line 137 "compiler.ypp"
                   { }
#line 1275 "compiler.cpp"
    break;

  case 10: /* N_NON_ARRAY_SYMBOL_ACCESS: N_SYMBOL_ACCESS M_PARAMETER_LOOKUP_SCOPE_CHANGE '(' N_PARAMETER ')'  */
#line 144 "compiler.ypp"
                                                                        {
        if ( pCurrentScope != nullptr ) {
            auto pFunction = dynamic_cast < FunctionEntry * > ( (yyvsp[-4].pSymbol) );
            if ( pFunction == nullptr ) {
                error :: nonFunctionCallError ( (yyvsp[-4].pSymbol)->getName() );
            } else {
                pFunction->matchParameterList ( (yyvsp[-1].pSymbolList) );
            }
        }
        pCurrentScope = (yyvsp[-3].pScope);
    }
#line 1291 "compiler.cpp"
    break;

  case 11: /* N_NON_ARRAY_SYMBOL_ACCESS: T_IDENTIFIER  */
#line 155 "compiler.ypp"
                 {
        if ( pCurrentScope != nullptr ) {
            auto pSymbol = pCurrentScope->getSymbol ( (yyvsp[0].stringValue) );
            if ( pSymbol == nullptr ) {
                (yyval.pSymbol) = new VariableEntry ( (yyvsp[0].stringValue), nullptr );
            } else {
                (yyval.pSymbol) = pSymbol;
            }
        } else {
            (yyval.pSymbol) = new VariableEntry ( (yyvsp[0].stringValue), nullptr );
        }
    }
#line 1308 "compiler.cpp"
    break;

  case 12: /* M_PARAMETER_LOOKUP_SCOPE_CHANGE: %empty  */
#line 169 "compiler.ypp"
    { (yyval.pScope) = pCurrentScope; pCurrentScope = pNonClassScope; }
#line 1314 "compiler.cpp"
    break;

  case 13: /* N_ARRAY_SYMBOL_ACCESS: N_NON_ARRAY_SYMBOL_ACCESS N_ARRAY_SUBSCRIPT  */
#line 172 "compiler.ypp"
                                                {
        auto pType = (yyvsp[-1].pSymbol)->getType();
        if ( pType != nullptr ) {
            if ( pType->getName()[0] != 'A' ) {
                error :: nonArrayTypeArrayAccess ( (yyvsp[-1].pSymbol)->getName() );
            } else {
                if ( pType->matchArraySubscript ( (yyvsp[0].pArraytypePair) ) ) {

                }
            }
        } 
        (yyval.pSymbol) = (yyvsp[-1].pSymbol);
    }
#line 1332 "compiler.cpp"
    break;

  case 14: /* $@1: %empty  */
#line 187 "compiler.ypp"
                                                  {
        if ( (yyvsp[-1].pSymbol)->getType() != nullptr ) {
            std :: string typeName = (yyvsp[-1].pSymbol)->getTypeName();
            if ( typeName[0] < '0' || typeName[0] > '9' ) {
                error :: nonStructureType ( typeName.c_str() );
                pCurrentScope = nullptr;
            } else {
                pCurrentScope = ( reinterpret_cast < StructuredTypeEntry * > ( (yyvsp[-1].pSymbol)->getType() ) )->getScope();
            }
        } else {
            pCurrentScope = nullptr;
        }
    }
#line 1350 "compiler.cpp"
    break;

  case 15: /* N_VARIABLE_ACCESS: N_VARIABLE_ACCESS M_CLASS_ACCESS_SCOPE_CHANGE $@1 '.' N_SYMBOL_ACCESS  */
#line 199 "compiler.ypp"
                          { 
        if ( pCurrentScope != nullptr ) {
            if ( (yyvsp[0].pSymbol)->getType() == nullptr ) {
                error :: nonExistentMember ( (yyvsp[-4].pSymbol)->getTypeName().c_str(), (yyvsp[-4].pSymbol)->getName() );
            }
        } 
        pCurrentScope = (yyvsp[-3].pScope);
        (yyval.pSymbol) = (yyvsp[0].pSymbol);
    }
#line 1364 "compiler.cpp"
    break;

  case 16: /* N_VARIABLE_ACCESS: N_SYMBOL_ACCESS  */
#line 208 "compiler.ypp"
                    {
        if ( (yyvsp[0].pSymbol)->getType() == nullptr ) {
            error :: undeclaredSymbol ( (yyvsp[0].pSymbol)->getName() );
        }
        (yyval.pSymbol) = (yyvsp[0].pSymbol);
    }
#line 1375 "compiler.cpp"
    break;

  case 17: /* M_CLASS_ACCESS_SCOPE_CHANGE: %empty  */
#line 216 "compiler.ypp"
    { (yyval.pScope) = pCurrentScope; }
#line 1381 "compiler.cpp"
    break;

  case 18: /* N_PARAMETER: N_PARAMETER_LIST  */
#line 219 "compiler.ypp"
                     {
        (yyval.pSymbolList) = (yyvsp[0].pSymbolList);
    }
#line 1389 "compiler.cpp"
    break;

  case 19: /* N_PARAMETER: %empty  */
#line 222 "compiler.ypp"
    { (yyval.pSymbolList) = new IdentifierList; }
#line 1395 "compiler.cpp"
    break;

  case 20: /* N_PARAMETER_LIST: N_PARAMETER_LIST ',' N_SYMBOL_ACCESS  */
#line 225 "compiler.ypp"
                                         {
        (yyvsp[-2].pSymbolList)->push_back ( (yyvsp[0].pSymbol) );
        (yyval.pSymbolList) = (yyvsp[-2].pSymbolList);
    }
#line 1404 "compiler.cpp"
    break;

  case 21: /* N_PARAMETER_LIST: N_SYMBOL_ACCESS  */
#line 229 "compiler.ypp"
                    {
        (yyval.pSymbolList) = new IdentifierList;
        (yyval.pSymbolList)->push_back ( (yyvsp[0].pSymbol) );
    }
#line 1413 "compiler.cpp"
    break;

  case 28: /* N_EXPRESSION: '(' N_EXPRESSION ')'  */
#line 244 "compiler.ypp"
                         {}
#line 1419 "compiler.cpp"
    break;

  case 29: /* N_EXPRESSION: '-' N_EXPRESSION  */
#line 245 "compiler.ypp"
                                  {}
#line 1425 "compiler.cpp"
    break;

  case 31: /* N_EXPRESSION: N_VARIABLE_ACCESS  */
#line 247 "compiler.ypp"
                      { }
#line 1431 "compiler.cpp"
    break;

  case 34: /* N_BOOL_EXPRESSION: '!' N_BOOL_EXPRESSION  */
#line 253 "compiler.ypp"
                                     { }
#line 1437 "compiler.cpp"
    break;

  case 35: /* N_BOOL_EXPRESSION: N_CONSTANT_VALUE  */
#line 254 "compiler.ypp"
                     { }
#line 1443 "compiler.cpp"
    break;

  case 36: /* N_BOOL_EXPRESSION: N_VARIABLE_ACCESS  */
#line 255 "compiler.ypp"
                      { }
#line 1449 "compiler.cpp"
    break;

  case 39: /* N_DECLARATION: N_DECLARATION error ';'  */
#line 261 "compiler.ypp"
                            { ++ errorCount; }
#line 1455 "compiler.cpp"
    break;

  case 40: /* N_DECLARATION: %empty  */
#line 262 "compiler.ypp"
    { }
#line 1461 "compiler.cpp"
    break;

  case 43: /* N_VARIABLE_DECLARATION: N_MIXED_TYPE T_IDENTIFIER  */
#line 271 "compiler.ypp"
                              {
        pCurrentScope->addVariable ( (yyvsp[-1].stringValue), (yyvsp[0].stringValue) );
    }
#line 1469 "compiler.cpp"
    break;

  case 44: /* N_VARIABLE_DECLARATION: N_MIXED_TYPE T_CONST T_IDENTIFIER  */
#line 274 "compiler.ypp"
                                      {
        std :: string constType = std :: string ( (yyvsp[-2].stringValue) ) + "$const";
        pCurrentScope->addVariable ( constType.c_str(), (yyvsp[0].stringValue) );
    }
#line 1478 "compiler.cpp"
    break;

  case 45: /* N_VARIABLE_DECLARATION: N_MIXED_TYPE T_IDENTIFIER N_ARRAY_SUBSCRIPT  */
#line 278 "compiler.ypp"
                                                {
        pCurrentScope->addArrayVariable ( (yyvsp[-2].stringValue), (yyvsp[-1].stringValue), (yyvsp[0].pArraytypePair)->first, (yyvsp[0].pArraytypePair)->second );
    }
#line 1486 "compiler.cpp"
    break;

  case 46: /* N_VARIABLE_DECLARATION: N_MIXED_TYPE T_CONST T_IDENTIFIER N_ARRAY_SUBSCRIPT  */
#line 281 "compiler.ypp"
                                                        {
        std :: string constType = std :: string ( (yyvsp[-3].stringValue) ) + "$const";
        pCurrentScope->addArrayVariable ( constType.c_str(), (yyvsp[-1].stringValue), (yyvsp[0].pArraytypePair)->first, (yyvsp[0].pArraytypePair)->second );
    }
#line 1495 "compiler.cpp"
    break;

  case 47: /* N_ARRAY_SUBSCRIPT: '[' T_INT_NUMBER ']' N_ARRAY_SUBSCRIPT  */
#line 288 "compiler.ypp"
                                           {
        char * pAux = new char;
        sprintf ( pAux, "A%d_", (yyvsp[-2].intValue) );
        strcat ( pAux, (yyvsp[0].pArraytypePair)->first );
        (yyval.pArraytypePair) = new ArraytypePair;
        (yyval.pArraytypePair)->first = pAux;
        (yyval.pArraytypePair)->second = (yyvsp[0].pArraytypePair)->second * (yyvsp[-2].intValue);
        delete (yyvsp[0].pArraytypePair);
    }
#line 1509 "compiler.cpp"
    break;

  case 48: /* N_ARRAY_SUBSCRIPT: '[' T_INT_NUMBER ']'  */
#line 297 "compiler.ypp"
                         { 
        (yyval.pArraytypePair) = new ArraytypePair;
        (yyval.pArraytypePair)->first = new char;
        sprintf ( (yyval.pArraytypePair)->first, "A%d_", (yyvsp[-1].intValue) );
        (yyval.pArraytypePair)->second = (yyvsp[-1].intValue);
    }
#line 1520 "compiler.cpp"
    break;

  case 49: /* N_CLASS_DECLARATION: T_CLASS T_IDENTIFIER '{' M_BLOCK_BEGIN N_DECLARATION '}'  */
#line 309 "compiler.ypp"
        {
        auto classScope = pCurrentScope;
        pCurrentScope = pCurrentScope->getUpperScope();
        auto pNewEntry = pCurrentScope->addUserDefinedType ( (yyvsp[-4].stringValue), classScope );
        if ( pNewEntry != nullptr ) {
            pCurrentScope->setUserDefinedTypeLength ( pNewEntry );
        }
    }
#line 1533 "compiler.cpp"
    break;

  case 50: /* M_BLOCK_BEGIN: %empty  */
#line 319 "compiler.ypp"
               { 
        auto newScope = new Scope ( pCurrentScope );
        pCurrentScope = pNonClassScope = newScope; 
    }
#line 1542 "compiler.cpp"
    break;

  case 51: /* N_FUNCTION_DECLARATION: N_MIXED_TYPE T_IDENTIFIER '(' N_PARAMETER_DECLARATION ')'  */
#line 326 "compiler.ypp"
                                                              {
        pCurrentScope->addFunction ( (yyvsp[-3].stringValue), (yyvsp[-4].stringValue), nullptr, (yyvsp[-1].pParamDeclarationList), nullptr );
    }
#line 1550 "compiler.cpp"
    break;

  case 53: /* N_PARAMETER_DECLARATION: %empty  */
#line 332 "compiler.ypp"
    { (yyval.pParamDeclarationList) = new ParameterDeclarationList; }
#line 1556 "compiler.cpp"
    break;

  case 54: /* N_PARAMETER_DECLARATION_LIST: N_PARAMETER_DECLARATION_LIST ',' N_MIXED_TYPE T_IDENTIFIER  */
#line 336 "compiler.ypp"
                                                               {
        (yyvsp[-3].pParamDeclarationList)->push_back ( new ParameterDeclarationPair { (yyvsp[-1].stringValue), (yyvsp[0].stringValue) } );
        (yyval.pParamDeclarationList) = (yyvsp[-3].pParamDeclarationList);
    }
#line 1565 "compiler.cpp"
    break;

  case 55: /* N_PARAMETER_DECLARATION_LIST: N_MIXED_TYPE T_IDENTIFIER  */
#line 340 "compiler.ypp"
                              {
        (yyval.pParamDeclarationList) = new ParameterDeclarationList;
        (yyval.pParamDeclarationList)->push_back( new ParameterDeclarationPair { (yyvsp[-1].stringValue), (yyvsp[0].stringValue) } );
    }
#line 1574 "compiler.cpp"
    break;

  case 56: /* N_BLOCK: '{' M_BLOCK_BEGIN N_STATEMENT '}'  */
#line 346 "compiler.ypp"
                                           {
        (yyval.pScope) = pCurrentScope;
        debugOut << "Scope: " << pCurrentScope << '\n' << "With variables:\n";
        for ( auto e : * pCurrentScope->getSymbolTable()->getSymbols() ) {
            debugOut << e->getTypeName() << ' ' << e->getName() << '\n';
        }
        debugOut << "And types:\n";
        for ( auto e : * pCurrentScope->getTypeTable()->getTypes() ) {
            debugOut << e->getName() << ' ' << e->getLength() << '\n';
        }
        debugOut << '\n';
        pCurrentScope = pCurrentScope->getUpperScope();
    }
#line 1592 "compiler.cpp"
    break;

  case 62: /* N_STATEMENT: N_STATEMENT N_BLOCK_SCOPE_DECLARATION ';'  */
#line 367 "compiler.ypp"
                                              { }
#line 1598 "compiler.cpp"
    break;

  case 63: /* N_STATEMENT: N_STATEMENT error ';'  */
#line 368 "compiler.ypp"
                          { ++ errorCount; }
#line 1604 "compiler.cpp"
    break;

  case 65: /* N_STATEMENT: %empty  */
#line 370 "compiler.ypp"
    { }
#line 1610 "compiler.cpp"
    break;

  case 66: /* N_ASSIGNMENT: N_VARIABLE_ACCESS '=' N_EXPRESSION  */
#line 374 "compiler.ypp"
                                       { }
#line 1616 "compiler.cpp"
    break;

  case 67: /* N_IF_STATEMENT: T_IF '(' N_BOOL_EXPRESSION ')' N_BLOCK  */
#line 378 "compiler.ypp"
                                           { }
#line 1622 "compiler.cpp"
    break;

  case 68: /* N_WHILE_STATEMENT: T_WHILE '(' N_BOOL_EXPRESSION ')' N_BLOCK  */
#line 382 "compiler.ypp"
                                              { }
#line 1628 "compiler.cpp"
    break;

  case 69: /* N_FOR_STATEMENT: T_FOR '(' ',' ',' ')' N_BLOCK  */
#line 386 "compiler.ypp"
                                  { }
#line 1634 "compiler.cpp"
    break;


#line 1638 "compiler.cpp"

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

#line 388 "compiler.ypp"
