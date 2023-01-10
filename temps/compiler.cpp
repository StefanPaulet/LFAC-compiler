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

    #include "../utilities/AbstractSyntaxTree/AbstractSyntaxTree.hpp"
    #include "../utilities/AbstractSyntaxTree/impl/AbstractSyntaxTree.hpp"

    Scope * pCurrentScope = Scope :: pGlobalScope;
    Scope * pNonClassScope;
    std :: ofstream debugOut ( "debug.out" );

    unsigned long long int errorCount = 0;

    using StringList               = std :: list < char const * >;
    using ArraytypePair            = TypeEntry :: ArraytypePair;
    using ParameterDeclarationPair = Scope :: ParameterDeclarationPair;
    using ParameterDeclarationList = Scope :: ParameterDeclarationList;
    using IdentifierAccessPair     = std :: pair < char const *, SymbolEntry * >;
    using ParameterCallList        = FunctionEntry :: ParameterList;
    using IdentifierLookup         = std :: pair < bool, TreeNodeIdentifier * >;
    using TreeNodeLabels           = AbstractSyntaxTree :: ASTOperators;
    using BlockType                = std :: pair < Scope *, TreeNode * >;
    using ExpressionType           = std :: pair < TreeNode *, TypeEntry * >;

#line 104 "compiler.cpp"

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
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '['  */
  YYSYMBOL_32_ = 32,                       /* ']'  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
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
  YYSYMBOL_N_VARIABLE_DEFINITION = 53,     /* N_VARIABLE_DEFINITION  */
  YYSYMBOL_N_ARRAY_SUBSCRIPT = 54,         /* N_ARRAY_SUBSCRIPT  */
  YYSYMBOL_N_CLASS_DECLARATION = 55,       /* N_CLASS_DECLARATION  */
  YYSYMBOL_M_BLOCK_BEGIN = 56,             /* M_BLOCK_BEGIN  */
  YYSYMBOL_N_FUNCTION_DECLARATION = 57,    /* N_FUNCTION_DECLARATION  */
  YYSYMBOL_58_2 = 58,                      /* $@2  */
  YYSYMBOL_M_FUNCTION_DECLARATION_BLOCK_BEGIN = 59, /* M_FUNCTION_DECLARATION_BLOCK_BEGIN  */
  YYSYMBOL_N_FUNCTION_BLOCK = 60,          /* N_FUNCTION_BLOCK  */
  YYSYMBOL_N_PARAMETER_DECLARATION = 61,   /* N_PARAMETER_DECLARATION  */
  YYSYMBOL_N_PARAMETER_DECLARATION_LIST = 62, /* N_PARAMETER_DECLARATION_LIST  */
  YYSYMBOL_N_BLOCK = 63,                   /* N_BLOCK  */
  YYSYMBOL_N_STATEMENT = 64,               /* N_STATEMENT  */
  YYSYMBOL_N_ASSIGNMENT = 65,              /* N_ASSIGNMENT  */
  YYSYMBOL_N_IF_STATEMENT = 66,            /* N_IF_STATEMENT  */
  YYSYMBOL_N_WHILE_STATEMENT = 67,         /* N_WHILE_STATEMENT  */
  YYSYMBOL_N_FOR_STATEMENT = 68            /* N_FOR_STATEMENT  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

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
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
       0,   130,   130,   141,   150,   159,   168,   177,   188,   189,
     192,   220,   253,   256,   279,   279,   304,   315,   318,   321,
     324,   328,   335,   336,   339,   353,   367,   381,   395,   396,
     404,   405,   408,   409,   410,   411,   412,   416,   422,   428,
     429,   433,   434,   435,   439,   443,   447,   451,   457,   469,
     484,   492,   501,   515,   522,   522,   530,   535,   541,   546,
     547,   551,   555,   561,   590,   596,   597,   598,   599,   605,
     611,   612,   618,   622,   639,   643,   647
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
  "'/'", "UMINUS", "'('", "')'", "'.'", "','", "'!'", "';'", "'='", "'['",
  "']'", "'{'", "'}'", "$accept", "N_START", "N_CONSTANT_VALUE",
  "N_SYMBOL_ACCESS", "N_NON_ARRAY_SYMBOL_ACCESS",
  "M_PARAMETER_LOOKUP_SCOPE_CHANGE", "N_ARRAY_SYMBOL_ACCESS",
  "N_VARIABLE_ACCESS", "$@1", "M_CLASS_ACCESS_SCOPE_CHANGE", "N_PARAMETER",
  "N_PARAMETER_LIST", "N_MIXED_TYPE", "N_EXPRESSION", "N_BOOL_EXPRESSION",
  "N_DECLARATION", "N_BLOCK_SCOPE_DECLARATION", "N_VARIABLE_DECLARATION",
  "N_VARIABLE_DEFINITION", "N_ARRAY_SUBSCRIPT", "N_CLASS_DECLARATION",
  "M_BLOCK_BEGIN", "N_FUNCTION_DECLARATION", "$@2",
  "M_FUNCTION_DECLARATION_BLOCK_BEGIN", "N_FUNCTION_BLOCK",
  "N_PARAMETER_DECLARATION", "N_PARAMETER_DECLARATION_LIST", "N_BLOCK",
  "N_STATEMENT", "N_ASSIGNMENT", "N_IF_STATEMENT", "N_WHILE_STATEMENT",
  "N_FOR_STATEMENT", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-102)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -102,    24,    14,  -102,    10,    18,    48,  -102,     4,    41,
    -102,  -102,  -102,  -102,  -102,    26,    50,    73,    72,  -102,
    -102,    69,   110,   122,    80,    89,  -102,  -102,    85,    80,
    -102,  -102,    82,  -102,    78,  -102,  -102,  -102,  -102,  -102,
    -102,    80,    80,  -102,    97,    92,  -102,   104,    32,   121,
      64,  -102,  -102,    32,  -102,   127,   122,  -102,   124,   130,
    -102,  -102,    80,    80,    80,    80,    92,  -102,  -102,   123,
     140,  -102,   142,   132,   126,   126,  -102,  -102,  -102,    57,
     128,  -102,    97,   134,   133,   142,   135,   138,   139,   141,
      62,  -102,     6,    67,   106,   137,  -102,   143,  -102,  -102,
    -102,  -102,  -102,  -102,   142,    97,  -102,     7,     7,   144,
      80,   120,  -102,  -102,  -102,   105,    97,     7,  -102,   104,
      30,   117,   146,    32,  -102,  -102,     7,     7,    85,    85,
     145,   150,  -102,  -102,  -102,    85,  -102
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      40,     0,     0,     1,     0,     0,    22,    23,     0,     0,
      42,    43,    41,    37,    39,     0,     0,     0,    44,    38,
      53,     0,    45,    60,     0,     0,    46,    40,     0,     0,
      47,    22,     0,    57,    59,     3,     5,     4,     6,     7,
      11,     0,     0,    30,    16,     8,     9,    31,    48,     0,
       0,    53,     2,    49,    62,     0,     0,    29,     0,     0,
      13,    14,     0,     0,     0,     0,    51,    52,    72,    56,
       0,    28,    19,     0,    25,    24,    26,    27,    50,     0,
       0,    61,    21,     0,    18,     0,     0,     0,     0,     0,
      11,    63,    31,     0,     0,     0,    71,     0,    65,    66,
      67,    72,    55,    10,     0,    15,    70,     0,     0,     0,
       0,    44,    68,    69,    64,     0,    20,     0,    35,    36,
       0,     0,     0,    73,    58,    34,     0,     0,     0,     0,
       0,    32,    33,    74,    75,     0,    76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,  -101,   -67,  -102,  -102,  -102,   -77,  -102,  -102,
    -102,  -102,   -22,   -21,     5,   147,   -70,  -102,  -102,   -18,
    -102,   118,  -102,  -102,  -102,  -102,  -102,  -102,   -28,    74,
    -102,  -102,  -102,  -102
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    43,    44,    45,    59,    46,    47,    73,    61,
      83,    84,     8,    94,   120,     2,     9,    10,    11,    26,
      12,    27,    13,    80,    55,   102,    33,    34,    96,    79,
      97,    98,    99,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    32,    92,    48,    30,    82,   118,   118,    53,    95,
      35,    36,    37,    38,    39,     4,   118,    17,   105,    18,
      57,    58,    40,     5,     3,   118,   118,    60,     6,     7,
     119,   119,   -17,    15,    70,   117,   110,   116,    92,    14,
     119,    74,    75,    76,    77,    95,   126,   127,    78,   119,
     119,    62,    63,    64,    65,   128,    16,    93,    86,    20,
      35,    36,    37,    38,    39,     4,     5,    87,    88,    89,
      19,    31,    90,     5,    21,   -23,    41,   -23,    31,     7,
      17,    42,   111,    35,    36,    37,    38,    39,    22,   123,
      51,    91,    49,    93,    28,    40,    23,    54,    67,    41,
     133,   134,    24,    25,    42,    56,    86,   136,    35,    36,
      37,    38,    39,   121,     5,    87,    88,    89,    51,    31,
      90,   -12,   125,    25,    41,    62,    63,    64,    65,    42,
     -17,   131,   132,   126,   127,   112,    31,     7,    51,   124,
      29,    25,   129,    62,    63,    64,    65,    64,    65,    71,
      24,    25,    69,    66,    72,    81,   -54,    40,    85,   103,
     104,   101,   107,   108,   106,   109,   113,   127,     0,    68,
     135,   122,   114,   130,    50,   115
};

static const yytype_int16 yycheck[] =
{
      28,    23,    79,    24,    22,    72,   107,   108,    29,    79,
       3,     4,     5,     6,     7,     1,   117,    13,    85,    15,
      41,    42,    15,     9,     0,   126,   127,    45,    14,    15,
     107,   108,    26,    15,    56,    28,    30,   104,   115,    29,
     117,    62,    63,    64,    65,   115,    16,    17,    66,   126,
     127,    19,    20,    21,    22,    25,     8,    79,     1,    33,
       3,     4,     5,     6,     7,     1,     9,    10,    11,    12,
      29,    14,    15,     9,    24,    13,    19,    15,    14,    15,
      13,    24,    15,     3,     4,     5,     6,     7,    15,   110,
      33,    34,     3,   115,    25,    15,    24,    15,    34,    19,
     128,   129,    30,    31,    24,    27,     1,   135,     3,     4,
       5,     6,     7,   108,     9,    10,    11,    12,    33,    14,
      15,    24,   117,    31,    19,    19,    20,    21,    22,    24,
      26,   126,   127,    16,    17,    29,    14,    15,    33,    34,
      30,    31,    25,    19,    20,    21,    22,    21,    22,    25,
      30,    31,    25,    32,    24,    15,    33,    15,    26,    25,
      27,    33,    24,    24,    29,    24,    29,    17,    -1,    51,
      25,    27,    29,    27,    27,   101
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    50,     0,     1,     9,    14,    15,    47,    51,
      52,    53,    55,    57,    29,    15,     8,    13,    15,    29,
      33,    24,    15,    24,    30,    31,    54,    56,    25,    30,
      54,    14,    47,    61,    62,     3,     4,     5,     6,     7,
      15,    19,    24,    37,    38,    39,    41,    42,    48,     3,
      50,    33,    63,    48,    15,    59,    27,    48,    48,    40,
      54,    44,    19,    20,    21,    22,    32,    34,    56,    25,
      47,    25,    24,    43,    48,    48,    48,    48,    54,    64,
      58,    15,    38,    45,    46,    26,     1,    10,    11,    12,
      15,    34,    42,    47,    48,    51,    63,    65,    66,    67,
      68,    33,    60,    25,    27,    38,    29,    24,    24,    24,
      30,    15,    29,    29,    29,    64,    38,    28,    37,    42,
      49,    49,    27,    48,    34,    49,    16,    17,    25,    25,
      27,    49,    49,    63,    63,    25,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    37,    37,    37,    38,    38,
      39,    39,    40,    41,    43,    42,    42,    44,    45,    45,
      46,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    49,    49,    49,    49,    49,    50,    50,    50,
      50,    51,    51,    51,    52,    52,    52,    52,    53,    53,
      54,    54,    55,    56,    58,    57,    57,    59,    60,    61,
      61,    62,    62,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    66,    67,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     1,     1,     1,     1,     1,     1,     1,
       5,     1,     0,     2,     0,     5,     1,     0,     1,     0,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     2,
       1,     1,     3,     3,     2,     1,     1,     2,     3,     3,
       0,     1,     1,     1,     2,     3,     3,     4,     4,     5,
       4,     3,     6,     0,     0,     8,     6,     0,     3,     1,
       0,     4,     2,     4,     3,     2,     2,     2,     3,     3,
       3,     2,     0,     3,     5,     5,     6
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
#line 131 "compiler.ypp"
                                             {
        
        std :: cout << "Error count: " << errorCount << '\n';
        if ( errorCount == 0 ) {
            auto pTree = new AbstractSyntaxTree ( (yyvsp[-5].pTreeNode), (yyvsp[0].pBlock)->second );
            pTree->eval();
        }
    }
#line 1269 "compiler.cpp"
    break;

  case 3: /* N_CONSTANT_VALUE: T_INT_NUMBER  */
#line 141 "compiler.ypp"
                 {
        (yyval.pExpression) = new ExpressionType (
                new TreeNodeConstant ( 
                    TreeNodeConstant :: ValueType :: __INT, 
                    (yyvsp[0].intValue) 
                ),
                Scope :: pGlobalScope->getTypeTable()->getType ( "int" )
        );
    }
#line 1283 "compiler.cpp"
    break;

  case 4: /* N_CONSTANT_VALUE: T_FLOAT_NUMBER  */
#line 150 "compiler.ypp"
                   { 
        (yyval.pExpression) = new ExpressionType (
                new TreeNodeConstant ( 
                    TreeNodeConstant :: ValueType :: __FLOAT, 
                    (yyvsp[0].floatValue) 
                ),
                Scope :: pGlobalScope->getTypeTable()->getType ( "float" )
        );
    }
#line 1297 "compiler.cpp"
    break;

  case 5: /* N_CONSTANT_VALUE: T_CHAR_VALUE  */
#line 159 "compiler.ypp"
                 { 
        (yyval.pExpression) = new ExpressionType (
                new TreeNodeConstant ( 
                    TreeNodeConstant :: ValueType :: __CHAR, 
                    (yyvsp[0].charValue) 
                ),
                Scope :: pGlobalScope->getTypeTable()->getType ( "char" )
        );
    }
#line 1311 "compiler.cpp"
    break;

  case 6: /* N_CONSTANT_VALUE: T_BOOL_VALUE  */
#line 168 "compiler.ypp"
                 { 
        (yyval.pExpression) = new ExpressionType (
                new TreeNodeConstant ( 
                    TreeNodeConstant :: ValueType :: __BOOL, 
                    (yyvsp[0].boolValue) 
                ),
                Scope :: pGlobalScope->getTypeTable()->getType ( "bool" )
        );
    }
#line 1325 "compiler.cpp"
    break;

  case 7: /* N_CONSTANT_VALUE: T_STRING_VALUE  */
#line 177 "compiler.ypp"
                   { 
        (yyval.pExpression) = new ExpressionType (
                new TreeNodeConstant ( 
                    TreeNodeConstant :: ValueType :: __STRING, 
                    (yyvsp[0].stringValue) 
                ),
                Scope :: pGlobalScope->getTypeTable()->getType ( "string" )
        );
    }
#line 1339 "compiler.cpp"
    break;

  case 10: /* N_NON_ARRAY_SYMBOL_ACCESS: N_SYMBOL_ACCESS M_PARAMETER_LOOKUP_SCOPE_CHANGE '(' N_PARAMETER ')'  */
#line 192 "compiler.ypp"
                                                                        {

        if ( pCurrentScope != nullptr ) {
            if ( ! (yyvsp[-4].pIdentifierLookup)->first && (yyvsp[-4].pIdentifierLookup)->second->getSymbol()->getType() != nullptr ) {
                auto pFunction = dynamic_cast < FunctionEntry * > ( (yyvsp[-4].pIdentifierLookup)->second->getSymbol() );
                if ( pFunction == nullptr ) {
                    (yyvsp[-4].pIdentifierLookup)->first = true;
                    error :: nonFunctionCallError ( (yyvsp[-4].pIdentifierLookup)->second->getSymbol()->getName() );
                } else {
                    if ( pFunction->matchParameterCallList ( (yyvsp[-1].pParameterCallList) ) ) {
                        (yyvsp[-4].pIdentifierLookup)->second->setLabel ( TreeNodeLabels :: __CALL );
                        TreeNode * * pFunctionChildList = new TreeNode * [ (yyvsp[-1].pParameterCallList)->size() + 1 ];
                        unsigned short int i = 0;
                        pFunctionChildList [ i++ ] = new TreeNodeIdentifier ( TreeNodeLabels :: __VAR, pFunction );
                        for ( auto e : * (yyvsp[-1].pParameterCallList) ) {
                            pFunctionChildList [ i++ ] = new TreeNodeIdentifier ( TreeNodeLabels :: __VAR, e );
                        }
                        (yyvsp[-4].pIdentifierLookup)->second->setChildList ( pFunctionChildList );
                        (yyvsp[-4].pIdentifierLookup)->second->setSymbol ( pFunction->getScope()->getSymbolTable()->lookUpSymbol("$return" ) );
                    } else {
                        (yyvsp[-4].pIdentifierLookup)->first = true;
                    }
                }
            }
        }
        (yyval.pIdentifierLookup) = (yyvsp[-4].pIdentifierLookup);
        pCurrentScope = (yyvsp[-3].pScope);
    }
#line 1372 "compiler.cpp"
    break;

  case 11: /* N_NON_ARRAY_SYMBOL_ACCESS: T_IDENTIFIER  */
#line 220 "compiler.ypp"
                 {

        if ( pCurrentScope != nullptr ) {
            auto pSymbol = pCurrentScope->getSymbol ( (yyvsp[0].stringValue) );
            if ( pSymbol == nullptr ) {
                (yyval.pIdentifierLookup) = new IdentifierLookup ( 
                    false, 
                    new TreeNodeIdentifier ( 
                        TreeNodeLabels :: __VAR,
                        new VariableEntry ( (yyvsp[0].stringValue), nullptr ) 
                    )
                );
            } else {
                (yyval.pIdentifierLookup) = new IdentifierLookup ( 
                    false, 
                    new TreeNodeIdentifier ( 
                        TreeNodeLabels :: __VAR,
                        pSymbol
                    )
                );
            }
        } else {
            (yyval.pIdentifierLookup) = new IdentifierLookup ( 
                    false, 
                    new TreeNodeIdentifier ( 
                        TreeNodeLabels :: __VAR,
                        new VariableEntry ( (yyvsp[0].stringValue), nullptr ) 
                    )
                );
        }
    }
#line 1408 "compiler.cpp"
    break;

  case 12: /* M_PARAMETER_LOOKUP_SCOPE_CHANGE: %empty  */
#line 253 "compiler.ypp"
    { (yyval.pScope) = pCurrentScope; pCurrentScope = pNonClassScope; }
#line 1414 "compiler.cpp"
    break;

  case 13: /* N_ARRAY_SYMBOL_ACCESS: N_NON_ARRAY_SYMBOL_ACCESS N_ARRAY_SUBSCRIPT  */
#line 256 "compiler.ypp"
                                                {

        if ( ! (yyvsp[-1].pIdentifierLookup)->first ) {
            auto pSymbol = (yyvsp[-1].pIdentifierLookup)->second->getSymbol();
            auto pType = pSymbol->getType();
            if ( pType != nullptr ) {
                if ( pType->getName()[0] != 'A' ) {
                    (yyvsp[-1].pIdentifierLookup)->first = true;
                    error :: nonArrayTypeArrayAccess ( pSymbol->getName() );
                } else {
                    int accessedElement = pType->matchArraySubscript ( (yyvsp[0].pArraytypePair) );
                    if ( accessedElement ) {
                        (yyvsp[-1].pIdentifierLookup)->second->setSymbol ( ( reinterpret_cast < VariableEntry * > ( pSymbol ) )->getValue().arrayValue[ accessedElement ] );
                    } else {
                        (yyvsp[-1].pIdentifierLookup)->first = true;
                    }
                }
            }
        }
        (yyval.pIdentifierLookup) = (yyvsp[-1].pIdentifierLookup);
    }
#line 1440 "compiler.cpp"
    break;

  case 14: /* $@1: %empty  */
#line 279 "compiler.ypp"
                                                  {
        if ( ! (yyvsp[-1].pIdentifierLookup)->first ) {
            std :: string typeName = (yyvsp[-1].pIdentifierLookup)->second->getSymbol()->getTypeName();
            if ( typeName[0] < '0' || typeName[0] > '9' ) {
                error :: nonStructureType ( typeName.c_str() );
                (yyvsp[-1].pIdentifierLookup)->first = true;
                pCurrentScope = nullptr;
            } else {
                pCurrentScope = ( reinterpret_cast < VariableEntry * > ( (yyvsp[-1].pIdentifierLookup)->second->getSymbol() ) )->getValue().structValue;
            }
        } else {
            pCurrentScope = nullptr;
        }
    }
#line 1459 "compiler.cpp"
    break;

  case 15: /* N_VARIABLE_ACCESS: N_VARIABLE_ACCESS M_CLASS_ACCESS_SCOPE_CHANGE $@1 '.' N_SYMBOL_ACCESS  */
#line 292 "compiler.ypp"
                          { 
        if ( pCurrentScope != nullptr ) {
            if ( (yyvsp[0].pIdentifierLookup)->second->getSymbol()->getType() == nullptr ) {
                (yyvsp[0].pIdentifierLookup)->first = true;
                error :: nonExistentMember ( (yyvsp[-4].pIdentifierLookup)->second->getSymbol()->getTypeName().c_str(), (yyvsp[0].pIdentifierLookup)->second->getSymbol()->getName() );
            } else {
                (yyvsp[0].pIdentifierLookup)->second->setSymbol ( ( reinterpret_cast < VariableEntry * > ( (yyvsp[-4].pIdentifierLookup)->second->getSymbol() ) )->getValue().structValue->getSymbolTable()->lookUpSymbol ( (yyvsp[0].pIdentifierLookup)->second->getSymbol()->getName() ) );
            }
        } 
        pCurrentScope = (yyvsp[-3].pScope);
        (yyval.pIdentifierLookup) = (yyvsp[0].pIdentifierLookup);
    }
#line 1476 "compiler.cpp"
    break;

  case 16: /* N_VARIABLE_ACCESS: N_SYMBOL_ACCESS  */
#line 304 "compiler.ypp"
                    {
        if ( ! (yyvsp[0].pIdentifierLookup)->first ) {
            if ( (yyvsp[0].pIdentifierLookup)->second->getSymbol()->getType() == nullptr ) {
                (yyvsp[0].pIdentifierLookup)->first = true;
                error :: undeclaredSymbol ( (yyvsp[0].pIdentifierLookup)->second->getSymbol()->getName() );
            }
        }
        (yyval.pIdentifierLookup) = (yyvsp[0].pIdentifierLookup);
    }
#line 1490 "compiler.cpp"
    break;

  case 17: /* M_CLASS_ACCESS_SCOPE_CHANGE: %empty  */
#line 315 "compiler.ypp"
    { (yyval.pScope) = pCurrentScope; }
#line 1496 "compiler.cpp"
    break;

  case 18: /* N_PARAMETER: N_PARAMETER_LIST  */
#line 318 "compiler.ypp"
                     {
        (yyval.pParameterCallList) = (yyvsp[0].pParameterCallList);
    }
#line 1504 "compiler.cpp"
    break;

  case 19: /* N_PARAMETER: %empty  */
#line 321 "compiler.ypp"
    { (yyval.pParameterCallList) = new ParameterCallList; }
#line 1510 "compiler.cpp"
    break;

  case 20: /* N_PARAMETER_LIST: N_PARAMETER_LIST ',' N_SYMBOL_ACCESS  */
#line 324 "compiler.ypp"
                                         {
        (yyvsp[-2].pParameterCallList)->push_back ( (yyvsp[0].pIdentifierLookup)->second->getSymbol() );
        (yyval.pParameterCallList) = (yyvsp[-2].pParameterCallList);
    }
#line 1519 "compiler.cpp"
    break;

  case 21: /* N_PARAMETER_LIST: N_SYMBOL_ACCESS  */
#line 328 "compiler.ypp"
                    {
        (yyval.pParameterCallList) = new ParameterCallList;
        (yyval.pParameterCallList)->push_back ( (yyvsp[0].pIdentifierLookup)->second->getSymbol() );
    }
#line 1528 "compiler.cpp"
    break;

  case 24: /* N_EXPRESSION: N_EXPRESSION '+' N_EXPRESSION  */
#line 339 "compiler.ypp"
                                  {
        if ( (yyvsp[-2].pExpression)->second != nullptr && (yyvsp[0].pExpression)->second != nullptr ) {
            if ( (yyvsp[-2].pExpression)->second != (yyvsp[0].pExpression)->second ) {
                error :: mismatchedTypes ( (yyvsp[-2].pExpression)->second->getName(), (yyvsp[0].pExpression)->second->getName() );
            }
        }
        TreeNode ** pChildren = new TreeNode * [2];
        pChildren[0] = (yyvsp[-2].pExpression)->first;
        pChildren[1] = (yyvsp[0].pExpression)->first;
        (yyval.pExpression) = new ExpressionType {
            new TreeNode ( TreeNodeLabels :: __PLUS, 2, pChildren ),
            (yyvsp[0].pExpression)->second
        };
    }
#line 1547 "compiler.cpp"
    break;

  case 25: /* N_EXPRESSION: N_EXPRESSION '-' N_EXPRESSION  */
#line 353 "compiler.ypp"
                                  {
        if ( (yyvsp[-2].pExpression)->second != nullptr && (yyvsp[0].pExpression)->second != nullptr ) {
            if ( (yyvsp[-2].pExpression)->second != (yyvsp[0].pExpression)->second ) {
                error :: mismatchedTypes ( (yyvsp[-2].pExpression)->second->getName(), (yyvsp[0].pExpression)->second->getName() );
            }
        }
        TreeNode ** pChildren = new TreeNode * [2];
        pChildren[0] = (yyvsp[-2].pExpression)->first;
        pChildren[1] = (yyvsp[0].pExpression)->first;
        (yyval.pExpression) = new ExpressionType {
            new TreeNode ( TreeNodeLabels :: __MINUS, 2, pChildren ),
            (yyvsp[0].pExpression)->second
        };
    }
#line 1566 "compiler.cpp"
    break;

  case 26: /* N_EXPRESSION: N_EXPRESSION '*' N_EXPRESSION  */
#line 367 "compiler.ypp"
                                  {
        if ( (yyvsp[-2].pExpression)->second != nullptr && (yyvsp[0].pExpression)->second != nullptr ) {
            if ( (yyvsp[-2].pExpression)->second != (yyvsp[0].pExpression)->second ) {
                error :: mismatchedTypes ( (yyvsp[-2].pExpression)->second->getName(), (yyvsp[0].pExpression)->second->getName() );
            }
        }
        TreeNode ** pChildren = new TreeNode * [2];
        pChildren[0] = (yyvsp[-2].pExpression)->first;
        pChildren[1] = (yyvsp[0].pExpression)->first;
        (yyval.pExpression) = new ExpressionType {
            new TreeNode ( TreeNodeLabels :: __MUL, 2, pChildren ),
            (yyvsp[0].pExpression)->second
        };
    }
#line 1585 "compiler.cpp"
    break;

  case 27: /* N_EXPRESSION: N_EXPRESSION '/' N_EXPRESSION  */
#line 381 "compiler.ypp"
                                  {
        if ( (yyvsp[-2].pExpression)->second != nullptr && (yyvsp[0].pExpression)->second != nullptr ) {
            if ( (yyvsp[-2].pExpression)->second != (yyvsp[0].pExpression)->second ) {
                error :: mismatchedTypes ( (yyvsp[-2].pExpression)->second->getName(), (yyvsp[0].pExpression)->second->getName() );
            }
        }
        TreeNode ** pChildren = new TreeNode * [2];
        pChildren[0] = (yyvsp[-2].pExpression)->first;
        pChildren[1] = (yyvsp[0].pExpression)->first;
        (yyval.pExpression) = new ExpressionType {
            new TreeNode ( TreeNodeLabels :: __DIV, 2, pChildren ),
            (yyvsp[0].pExpression)->second
        };
    }
#line 1604 "compiler.cpp"
    break;

  case 28: /* N_EXPRESSION: '(' N_EXPRESSION ')'  */
#line 395 "compiler.ypp"
                         { (yyval.pExpression) = (yyvsp[-1].pExpression); }
#line 1610 "compiler.cpp"
    break;

  case 29: /* N_EXPRESSION: '-' N_EXPRESSION  */
#line 396 "compiler.ypp"
                                  { 
        TreeNode ** pChild = new TreeNode *;
        (*pChild) = (yyvsp[0].pExpression)->first;
        (yyval.pExpression) = new ExpressionType {
            new TreeNode ( TreeNodeLabels :: __UMINUS, 1, pChild ),
            (yyvsp[0].pExpression)->second
        };
    }
#line 1623 "compiler.cpp"
    break;

  case 31: /* N_EXPRESSION: N_VARIABLE_ACCESS  */
#line 405 "compiler.ypp"
                      { (yyval.pExpression) = new ExpressionType ( (yyvsp[0].pIdentifierLookup)->second, (yyvsp[0].pIdentifierLookup)->second->getSymbol()->getType() ); }
#line 1629 "compiler.cpp"
    break;

  case 34: /* N_BOOL_EXPRESSION: '!' N_BOOL_EXPRESSION  */
#line 410 "compiler.ypp"
                                     { }
#line 1635 "compiler.cpp"
    break;

  case 35: /* N_BOOL_EXPRESSION: N_CONSTANT_VALUE  */
#line 411 "compiler.ypp"
                     { }
#line 1641 "compiler.cpp"
    break;

  case 36: /* N_BOOL_EXPRESSION: N_VARIABLE_ACCESS  */
#line 412 "compiler.ypp"
                      { }
#line 1647 "compiler.cpp"
    break;

  case 37: /* N_DECLARATION: N_DECLARATION N_FUNCTION_DECLARATION  */
#line 416 "compiler.ypp"
                                         {
        TreeNode ** pChildren = new TreeNode * [2];
        pChildren[0] = (yyvsp[-1].pTreeNode);
        pChildren[1] = (yyvsp[0].pTreeNode);
        (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __STMT, 2, pChildren );
    }
#line 1658 "compiler.cpp"
    break;

  case 38: /* N_DECLARATION: N_DECLARATION N_BLOCK_SCOPE_DECLARATION ';'  */
#line 422 "compiler.ypp"
                                                { 
        TreeNode ** pChildren = new TreeNode * [2];
        pChildren[0] = (yyvsp[-2].pTreeNode);
        pChildren[1] = (yyvsp[-1].pTreeNode);
        (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __STMT, 2, pChildren );
    }
#line 1669 "compiler.cpp"
    break;

  case 39: /* N_DECLARATION: N_DECLARATION error ';'  */
#line 428 "compiler.ypp"
                            { ++ errorCount; (yyval.pTreeNode) = (yyvsp[-2].pTreeNode); }
#line 1675 "compiler.cpp"
    break;

  case 40: /* N_DECLARATION: %empty  */
#line 429 "compiler.ypp"
    { (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __STMT, 0, nullptr ); }
#line 1681 "compiler.cpp"
    break;

  case 44: /* N_VARIABLE_DECLARATION: N_MIXED_TYPE T_IDENTIFIER  */
#line 439 "compiler.ypp"
                              {
        pCurrentScope->addVariable ( (yyvsp[-1].stringValue), (yyvsp[0].stringValue) );
        (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __STMT, 0, nullptr );
    }
#line 1690 "compiler.cpp"
    break;

  case 45: /* N_VARIABLE_DECLARATION: N_MIXED_TYPE T_CONST T_IDENTIFIER  */
#line 443 "compiler.ypp"
                                      {
        error :: unitializedConstIdentifier();
        (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __STMT, 0, nullptr );
    }
#line 1699 "compiler.cpp"
    break;

  case 46: /* N_VARIABLE_DECLARATION: N_MIXED_TYPE T_IDENTIFIER N_ARRAY_SUBSCRIPT  */
#line 447 "compiler.ypp"
                                                {
        pCurrentScope->addArrayVariable ( (yyvsp[-2].stringValue), (yyvsp[-1].stringValue), (yyvsp[0].pArraytypePair)->first, (yyvsp[0].pArraytypePair)->second );
        (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __STMT, 0, nullptr );
    }
#line 1708 "compiler.cpp"
    break;

  case 47: /* N_VARIABLE_DECLARATION: N_MIXED_TYPE T_CONST T_IDENTIFIER N_ARRAY_SUBSCRIPT  */
#line 451 "compiler.ypp"
                                                        {
        error :: unitializedConstIdentifier();
        (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __STMT, 0, nullptr );
    }
#line 1717 "compiler.cpp"
    break;

  case 48: /* N_VARIABLE_DEFINITION: N_MIXED_TYPE T_IDENTIFIER '=' N_EXPRESSION  */
#line 457 "compiler.ypp"
                                               {
        auto pNewVariable = pCurrentScope->addVariable ( (yyvsp[-3].stringValue), (yyvsp[-2].stringValue) );
        if ( pNewVariable != nullptr && (yyvsp[0].pExpression)->second != nullptr ) {
            if ( pNewVariable->getType() != (yyvsp[0].pExpression)->second ) {
                error :: assignmentMismatchedTypes ( pNewVariable->getType()->getName(), (yyvsp[0].pExpression)->second->getName() );
            }
        }
        TreeNode ** pChildren = new TreeNode * [2];
        pChildren[0] = new TreeNodeIdentifier ( TreeNodeLabels :: __VAR, pNewVariable );
        pChildren[1] = (yyvsp[0].pExpression)->first;
        (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __ASG, 2, pChildren );
    }
#line 1734 "compiler.cpp"
    break;

  case 49: /* N_VARIABLE_DEFINITION: N_MIXED_TYPE T_CONST T_IDENTIFIER '=' N_EXPRESSION  */
#line 469 "compiler.ypp"
                                                       {
        auto pNewVariable = pCurrentScope->addVariable ( (yyvsp[-4].stringValue), (yyvsp[-2].stringValue) );
        pNewVariable->setConstQualifier ( true );
        if ( pNewVariable != nullptr && (yyvsp[0].pExpression)->second != nullptr ) {
            if ( pNewVariable->getType() != (yyvsp[0].pExpression)->second ) {
                error :: assignmentMismatchedTypes ( pNewVariable->getType()->getName(), (yyvsp[0].pExpression)->second->getName() );
            }
        }
        TreeNode ** pChildren = new TreeNode * [2];
        pChildren[0] = new TreeNodeIdentifier ( TreeNodeLabels :: __VAR, pNewVariable );
        pChildren[1] = (yyvsp[0].pExpression)->first;
        (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __ASG, 2, pChildren );
    }
#line 1752 "compiler.cpp"
    break;

  case 50: /* N_ARRAY_SUBSCRIPT: '[' T_INT_NUMBER ']' N_ARRAY_SUBSCRIPT  */
#line 484 "compiler.ypp"
                                           {
        char * pAux = new char;
        sprintf ( pAux, "A%d_", (yyvsp[-2].intValue) );
        strcat ( pAux, (yyvsp[0].pArraytypePair)->first );
        (yyval.pArraytypePair) = new ArraytypePair;
        (yyval.pArraytypePair)->first = pAux;
        (yyval.pArraytypePair)->second = (yyvsp[0].pArraytypePair)->second * (yyvsp[-2].intValue);
    }
#line 1765 "compiler.cpp"
    break;

  case 51: /* N_ARRAY_SUBSCRIPT: '[' T_INT_NUMBER ']'  */
#line 492 "compiler.ypp"
                         { 
        (yyval.pArraytypePair) = new ArraytypePair;
        (yyval.pArraytypePair)->first = new char;
        sprintf ( (yyval.pArraytypePair)->first, "A%d_", (yyvsp[-1].intValue) );
        (yyval.pArraytypePair)->second = (yyvsp[-1].intValue);
    }
#line 1776 "compiler.cpp"
    break;

  case 52: /* N_CLASS_DECLARATION: T_CLASS T_IDENTIFIER '{' M_BLOCK_BEGIN N_DECLARATION '}'  */
#line 504 "compiler.ypp"
        {
        auto classScope = pCurrentScope;
        pCurrentScope = pCurrentScope->getUpperScope();
        auto pNewEntry = pCurrentScope->addUserDefinedType ( (yyvsp[-4].stringValue), classScope );
        if ( pNewEntry != nullptr ) {
            pCurrentScope->setUserDefinedTypeLength ( pNewEntry );
        }
        (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __STMT, 0, nullptr );
    }
#line 1790 "compiler.cpp"
    break;

  case 53: /* M_BLOCK_BEGIN: %empty  */
#line 515 "compiler.ypp"
               { 
        auto newScope = new Scope ( pCurrentScope );
        pCurrentScope = pNonClassScope = newScope; 
    }
#line 1799 "compiler.cpp"
    break;

  case 54: /* $@2: %empty  */
#line 522 "compiler.ypp"
                                                                                                 { 
        (yyvsp[-1].pScope)->addFunction ( (yyvsp[-4].stringValue), (yyvsp[-5].stringValue), nullptr, (yyvsp[-2].pParamDeclarationList), pCurrentScope );
    }
#line 1807 "compiler.cpp"
    break;

  case 55: /* N_FUNCTION_DECLARATION: N_MIXED_TYPE T_IDENTIFIER '(' N_PARAMETER_DECLARATION M_FUNCTION_DECLARATION_BLOCK_BEGIN ')' $@2 N_FUNCTION_BLOCK  */
#line 524 "compiler.ypp"
                       {
        pCurrentScope = (yyvsp[-3].pScope);
        auto pSymbol = pCurrentScope->getSymbolTable()->lookUpSymbol ( (yyvsp[-6].stringValue) );
        ( reinterpret_cast < FunctionEntry * > ( pSymbol ) )->setFunctionBody ( (yyvsp[0].pBlock)->second );
        (yyval.pTreeNode) = new TreeNodeIdentifier ( TreeNodeLabels :: __FUNC, pSymbol );
    }
#line 1818 "compiler.cpp"
    break;

  case 56: /* N_FUNCTION_DECLARATION: N_MIXED_TYPE T_IDENTIFIER '(' N_PARAMETER_DECLARATION M_FUNCTION_DECLARATION_BLOCK_BEGIN ')'  */
#line 530 "compiler.ypp"
                                                                                                 {
        error :: functionDeclaration();
        delete pCurrentScope;
        pCurrentScope = (yyvsp[-1].pScope);
    }
#line 1828 "compiler.cpp"
    break;

  case 57: /* M_FUNCTION_DECLARATION_BLOCK_BEGIN: %empty  */
#line 535 "compiler.ypp"
                                    {
    (yyval.pScope) = pCurrentScope;
    auto pNewScope = new Scope ( pCurrentScope );
    pCurrentScope = pNewScope;
    }
#line 1838 "compiler.cpp"
    break;

  case 58: /* N_FUNCTION_BLOCK: '{' N_STATEMENT '}'  */
#line 541 "compiler.ypp"
                        {
        (yyval.pBlock) = new BlockType ( pCurrentScope, (yyvsp[-1].pTreeNode) );
    }
#line 1846 "compiler.cpp"
    break;

  case 60: /* N_PARAMETER_DECLARATION: %empty  */
#line 547 "compiler.ypp"
    { (yyval.pParamDeclarationList) = new ParameterDeclarationList; }
#line 1852 "compiler.cpp"
    break;

  case 61: /* N_PARAMETER_DECLARATION_LIST: N_PARAMETER_DECLARATION_LIST ',' N_MIXED_TYPE T_IDENTIFIER  */
#line 551 "compiler.ypp"
                                                               {
        (yyvsp[-3].pParamDeclarationList)->push_back ( new ParameterDeclarationPair { (yyvsp[-1].stringValue), (yyvsp[0].stringValue) } );
        (yyval.pParamDeclarationList) = (yyvsp[-3].pParamDeclarationList);
    }
#line 1861 "compiler.cpp"
    break;

  case 62: /* N_PARAMETER_DECLARATION_LIST: N_MIXED_TYPE T_IDENTIFIER  */
#line 555 "compiler.ypp"
                              {
        (yyval.pParamDeclarationList) = new ParameterDeclarationList;
        (yyval.pParamDeclarationList)->push_back( new ParameterDeclarationPair { (yyvsp[-1].stringValue), (yyvsp[0].stringValue) } );
    }
#line 1870 "compiler.cpp"
    break;

  case 63: /* N_BLOCK: '{' M_BLOCK_BEGIN N_STATEMENT '}'  */
#line 561 "compiler.ypp"
                                           {
        (yyval.pBlock) = new BlockType ( pCurrentScope, (yyvsp[-1].pTreeNode) );
        // debugOut << "Scope: " << pCurrentScope << '\n' << "With variables:\n";
        // for ( auto e : * pCurrentScope->getSymbolTable()->getSymbols() ) {
        //     debugOut << e << ' ' << e->getTypeName() << ' ' << e->getName();
        //     auto pVar = dynamic_cast < VariableEntry * > ( e );
        //     if ( pVar != nullptr ) {
        //         if ( * pVar->getType()->getName() >= '0' && * pVar->getType()->getName() <= '9' ) {
        //             debugOut << '\n';
        //             for ( auto f : * pVar->getValue().structValue->getSymbolTable()->getSymbols() ) {
        //                 debugOut << f->getTypeName() << ' ' << f->getName();
        //             }
        //         } else {
        //             debugOut << " with value " << pVar->getValue().intValue << '\n';
        //         }
        //     } else {
        //         debugOut << '\n';
        //     }
        // }
        // debugOut << "And types:\n";
        // for ( auto e : * pCurrentScope->getTypeTable()->getTypes() ) {
        //     debugOut << e->getName() << ' ' << e->getLength() << '\n';
        // }
        // debugOut << '\n';
        pCurrentScope = pCurrentScope->getUpperScope();
    }
#line 1901 "compiler.cpp"
    break;

  case 64: /* N_STATEMENT: N_STATEMENT N_ASSIGNMENT ';'  */
#line 590 "compiler.ypp"
                                 {
        TreeNode ** pChildren = new TreeNode * [2];
        pChildren[0] = (yyvsp[-2].pTreeNode);
        pChildren[1] = (yyvsp[-1].pTreeNode);
        (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __STMT, 2, pChildren );
    }
#line 1912 "compiler.cpp"
    break;

  case 68: /* N_STATEMENT: N_STATEMENT N_EXPRESSION ';'  */
#line 599 "compiler.ypp"
                                 {
        TreeNode ** pChildren = new TreeNode * [2];
        pChildren[0] = (yyvsp[-2].pTreeNode);
        pChildren[1] = (yyvsp[-1].pExpression)->first;
        (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __STMT, 2, pChildren );
    }
#line 1923 "compiler.cpp"
    break;

  case 69: /* N_STATEMENT: N_STATEMENT N_BLOCK_SCOPE_DECLARATION ';'  */
#line 605 "compiler.ypp"
                                              {
        TreeNode ** pChildren = new TreeNode * [2];
        pChildren[0] = (yyvsp[-2].pTreeNode);
        pChildren[1] = (yyvsp[-1].pTreeNode);
        (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __STMT, 2, pChildren ); 
    }
#line 1934 "compiler.cpp"
    break;

  case 70: /* N_STATEMENT: N_STATEMENT error ';'  */
#line 611 "compiler.ypp"
                          { ++ errorCount; }
#line 1940 "compiler.cpp"
    break;

  case 71: /* N_STATEMENT: N_STATEMENT N_BLOCK  */
#line 612 "compiler.ypp"
                        {
        TreeNode ** pChildren = new TreeNode * [2];
        pChildren[0] = (yyvsp[-1].pTreeNode);
        pChildren[1] = (yyvsp[0].pBlock)->second;
        (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __STMT, 2, pChildren );
    }
#line 1951 "compiler.cpp"
    break;

  case 72: /* N_STATEMENT: %empty  */
#line 618 "compiler.ypp"
    { (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __STMT, 0, nullptr ); }
#line 1957 "compiler.cpp"
    break;

  case 73: /* N_ASSIGNMENT: N_VARIABLE_ACCESS '=' N_EXPRESSION  */
#line 622 "compiler.ypp"
                                       {
        if ( reinterpret_cast < VariableEntry * > ( (yyvsp[-2].pIdentifierLookup)->second->getSymbol() )->getConstQualifier() )  {
            error :: constIdentifierAssigned ( (yyvsp[-2].pIdentifierLookup)->second->getSymbol()->getName() );
        }
        if ( (yyvsp[-2].pIdentifierLookup)->second->getSymbol()->getType() != nullptr && (yyvsp[0].pExpression)->second != nullptr ) {
            if ( (yyvsp[-2].pIdentifierLookup)->second->getSymbol()->getType() != (yyvsp[0].pExpression)->second ) {
                error :: assignmentMismatchedTypes ( (yyvsp[-2].pIdentifierLookup)->second->getSymbol()->getType()->getName(), (yyvsp[0].pExpression)->second->getName() );
            }
        }
        TreeNode ** pChildren = new TreeNode * [2];
        pChildren[0] = (yyvsp[-2].pIdentifierLookup)->second;
        pChildren[1] = (yyvsp[0].pExpression)->first;
        (yyval.pTreeNode) = new TreeNode ( TreeNodeLabels :: __ASG, 2, pChildren );
    }
#line 1976 "compiler.cpp"
    break;

  case 74: /* N_IF_STATEMENT: T_IF '(' N_BOOL_EXPRESSION ')' N_BLOCK  */
#line 639 "compiler.ypp"
                                           { }
#line 1982 "compiler.cpp"
    break;

  case 75: /* N_WHILE_STATEMENT: T_WHILE '(' N_BOOL_EXPRESSION ')' N_BLOCK  */
#line 643 "compiler.ypp"
                                              { }
#line 1988 "compiler.cpp"
    break;

  case 76: /* N_FOR_STATEMENT: T_FOR '(' ',' ',' ')' N_BLOCK  */
#line 647 "compiler.ypp"
                                  { }
#line 1994 "compiler.cpp"
    break;


#line 1998 "compiler.cpp"

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

#line 649 "compiler.ypp"
