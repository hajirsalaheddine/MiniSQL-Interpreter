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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
int yylex();
void yyerror(const char *s);

#define MAX_TABLES 100
#define MAX_COLUMNS 64

typedef struct {
    char *name;
    int col_count;
    char *col_names[MAX_COLUMNS];
} TableEntry;

TableEntry tables[MAX_TABLES];
int table_count = 0;

char *current_col_names[MAX_COLUMNS];
int current_col_count = 0;

char *current_select_cols[MAX_COLUMNS];
int current_select_col_count = 0;
int last_select_used_star = 0;

int current_table_idx_for_condition = -1;
char *current_table_name = NULL;

char *current_insert_cols[MAX_COLUMNS];
int current_insert_col_count = 0;

void reset_current_select_cols(void) { current_select_col_count = 0; last_select_used_star = 0; }
void add_current_select_col(char *name) { current_select_cols[current_select_col_count++] = name; }

void reset_current_insert_columns(void) { current_insert_col_count = 0; }
void add_current_insert_column(char *name) { current_insert_cols[current_insert_col_count++] = name; }

int find_column_in_table(int table_idx, const char *colname) {
    for (int j = 0; j < tables[table_idx].col_count; j++)
        if (strcmp(tables[table_idx].col_names[j], colname) == 0) return j;
    return -1;
}

void reset_current_columns(void) { current_col_count = 0; }
void add_current_column(char *name) { current_col_names[current_col_count++] = name; }

int find_table(const char *name) {
    for (int i = 0; i < table_count; i++)
        if (strcmp(tables[i].name, name) == 0) return i;
    return -1;
}

int add_table(const char *name) {
    if (find_table(name) != -1) return -1;
    tables[table_count].name = strdup(name);
    tables[table_count].col_count = current_col_count;
    for (int i = 0; i < current_col_count; i++)
        tables[table_count].col_names[i] = current_col_names[i];
    table_count++;
    return 0;
}

int drop_table_entry(const char *name) {
    int idx = find_table(name);
    if (idx == -1) return -1;
    free(tables[idx].name);
    for (int j = 0; j < tables[idx].col_count; j++)
        free(tables[idx].col_names[j]);
    for (int i = idx; i < table_count - 1; i++)
        tables[i] = tables[i + 1];
    table_count--;
    return 0;
}

#line 149 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SELECT = 3,                     /* SELECT  */
  YYSYMBOL_FROM = 4,                       /* FROM  */
  YYSYMBOL_WHERE = 5,                      /* WHERE  */
  YYSYMBOL_INSERT = 6,                     /* INSERT  */
  YYSYMBOL_INTO = 7,                       /* INTO  */
  YYSYMBOL_VALUES = 8,                     /* VALUES  */
  YYSYMBOL_CREATE = 9,                     /* CREATE  */
  YYSYMBOL_TABLE_ = 10,                    /* TABLE_  */
  YYSYMBOL_UPDATE = 11,                    /* UPDATE  */
  YYSYMBOL_SET = 12,                       /* SET  */
  YYSYMBOL_DELETE = 13,                    /* DELETE  */
  YYSYMBOL_DROP = 14,                      /* DROP  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_INT_ = 18,                      /* INT_  */
  YYSYMBOL_FLOAT_ = 19,                    /* FLOAT_  */
  YYSYMBOL_VARCHAR = 20,                   /* VARCHAR  */
  YYSYMBOL_BOOL_ = 21,                     /* BOOL_  */
  YYSYMBOL_TRUE_ = 22,                     /* TRUE_  */
  YYSYMBOL_FALSE_ = 23,                    /* FALSE_  */
  YYSYMBOL_INT_CONST = 24,                 /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 25,               /* FLOAT_CONST  */
  YYSYMBOL_STRING_CONST = 26,              /* STRING_CONST  */
  YYSYMBOL_IDENTIFIER = 27,                /* IDENTIFIER  */
  YYSYMBOL_GEQ = 28,                       /* GEQ  */
  YYSYMBOL_LEQ = 29,                       /* LEQ  */
  YYSYMBOL_NEQ = 30,                       /* NEQ  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_GT = 32,                        /* GT  */
  YYSYMBOL_LT = 33,                        /* LT  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 35,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 36,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 37,                    /* RPAREN  */
  YYSYMBOL_STAR = 38,                      /* STAR  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_input = 40,                     /* input  */
  YYSYMBOL_requete = 41,                   /* requete  */
  YYSYMBOL_create_table = 42,              /* create_table  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_champs = 44,                    /* champs  */
  YYSYMBOL_champ = 45,                     /* champ  */
  YYSYMBOL_type = 46,                      /* type  */
  YYSYMBOL_insert_into = 47,               /* insert_into  */
  YYSYMBOL_48_2 = 48,                      /* $@2  */
  YYSYMBOL_valeurs = 49,                   /* valeurs  */
  YYSYMBOL_valeur = 50,                    /* valeur  */
  YYSYMBOL_select_stmt = 51,               /* select_stmt  */
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_select_body = 53,               /* select_body  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_liste_champs = 55,              /* liste_champs  */
  YYSYMBOL_liste_ident = 56,               /* liste_ident  */
  YYSYMBOL_condition = 57,                 /* condition  */
  YYSYMBOL_condition_term = 58,            /* condition_term  */
  YYSYMBOL_condition_factor = 59,          /* condition_factor  */
  YYSYMBOL_update_stmt = 60,               /* update_stmt  */
  YYSYMBOL_61_5 = 61,                      /* $@5  */
  YYSYMBOL_modifications = 62,             /* modifications  */
  YYSYMBOL_modification = 63,              /* modification  */
  YYSYMBOL_delete_stmt = 64,               /* delete_stmt  */
  YYSYMBOL_65_6 = 65,                      /* $@6  */
  YYSYMBOL_drop_table = 66                 /* drop_table  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   100

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   107,   107,   108,   109,   113,   114,   115,   116,   117,
     118,   122,   122,   133,   134,   138,   142,   143,   144,   145,
     146,   150,   160,   160,   181,   182,   186,   187,   188,   189,
     190,   194,   194,   199,   206,   205,   217,   218,   219,   223,
     224,   228,   229,   233,   234,   238,   239,   240,   241,   242,
     243,   244,   249,   248,   262,   263,   267,   272,   271,   282,
     292
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
  "\"end of file\"", "error", "\"invalid token\"", "SELECT", "FROM",
  "WHERE", "INSERT", "INTO", "VALUES", "CREATE", "TABLE_", "UPDATE", "SET",
  "DELETE", "DROP", "AND", "OR", "NOT", "INT_", "FLOAT_", "VARCHAR",
  "BOOL_", "TRUE_", "FALSE_", "INT_CONST", "FLOAT_CONST", "STRING_CONST",
  "IDENTIFIER", "GEQ", "LEQ", "NEQ", "EQ", "GT", "LT", "COMMA",
  "SEMICOLON", "LPAREN", "RPAREN", "STAR", "$accept", "input", "requete",
  "create_table", "$@1", "champs", "champ", "type", "insert_into", "$@2",
  "valeurs", "valeur", "select_stmt", "$@3", "select_body", "$@4",
  "liste_champs", "liste_ident", "condition", "condition_term",
  "condition_factor", "update_stmt", "$@5", "modifications",
  "modification", "delete_stmt", "$@6", "drop_table", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -76,     4,   -76,   -29,   -76,     2,     6,    -7,    10,    11,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -19,     7,
       8,   -76,    12,    31,     3,   -76,   -76,    34,    51,   -76,
      48,    26,    28,   -19,    35,    29,    30,    32,    37,   -76,
      62,   -76,   -76,    38,    27,    42,    43,    40,    67,    41,
       5,   -76,    69,   -76,   -76,   -76,   -76,   -76,    39,    44,
      45,    46,    36,    47,    52,    27,     5,    37,    15,     5,
     -13,    65,   -76,     5,    50,    27,    42,    73,   -76,   -76,
      53,   -76,   -76,    55,    43,   -76,    -5,   -76,    27,    27,
      27,    27,    27,    27,   -14,     5,   -76,     5,    -4,   -76,
     -76,   -76,    56,    58,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,    65,   -76,   -76,    27,    54,    57,
     -76,    60,   -76
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,    31,     0,     0,     0,     0,     0,
       3,     5,     6,     7,     8,     9,    10,     4,     0,     0,
       0,    52,     0,     0,    37,    36,    32,     0,    22,    11,
       0,    57,     0,     0,     0,     0,     0,     0,     0,    59,
       0,    60,    38,    34,     0,     0,     0,     0,     0,    54,
       0,    33,     0,    29,    30,    26,    27,    28,     0,    24,
      39,     0,     0,     0,    13,     0,     0,     0,     0,     0,
       0,    42,    44,     0,     0,     0,     0,     0,    16,    17,
      18,    20,    15,     0,     0,    56,     0,    55,     0,     0,
       0,     0,     0,     0,     0,     0,    58,     0,     0,    21,
      25,    40,     0,     0,    12,    14,    53,    48,    49,    50,
      45,    46,    47,    51,    41,    43,    35,     0,     0,     0,
      19,     0,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   -76,   -76,   -76,     9,   -76,   -76,   -76,   -76,
     -75,   -64,   -76,   -76,   -76,   -76,    63,     1,   -33,    -8,
      -9,   -76,   -76,    33,   -76,   -76,   -76,   -76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    10,    11,    37,    63,    64,    82,    12,    36,
      58,    59,    13,    18,    26,    52,    27,    61,    70,    71,
      72,    14,    30,    48,    49,    15,    40,    16
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
     100,    85,    95,    95,     2,     3,    17,     4,    24,    19,
       5,    95,    95,     6,    22,     7,    20,     8,     9,    25,
      21,    23,    96,   113,   107,   108,   109,   110,   111,   112,
     106,   116,    68,    86,    28,    29,    94,    33,    34,    31,
      98,    69,   119,    88,    89,    90,    91,    92,    93,    53,
      54,    55,    56,    57,    78,    79,    80,    81,    32,    35,
      38,    39,    43,    41,    47,    44,    45,    50,    46,    60,
      62,    65,    66,    51,    73,    67,    74,   101,    75,    76,
      97,   102,   118,    77,    83,    99,    84,   114,   115,   103,
     104,   120,   117,   105,   121,   122,    42,     0,     0,     0,
      87
};

static const yytype_int8 yycheck[] =
{
      75,    65,    16,    16,     0,     1,    35,     3,    27,     7,
       6,    16,    16,     9,     4,    11,    10,    13,    14,    38,
      27,    10,    35,    37,    88,    89,    90,    91,    92,    93,
      35,    35,    27,    66,    27,    27,    69,    34,     4,    27,
      73,    36,   117,    28,    29,    30,    31,    32,    33,    22,
      23,    24,    25,    26,    18,    19,    20,    21,    27,     8,
      12,    35,    27,    35,    27,    36,    36,     5,    36,    27,
      27,    31,     5,    35,     5,    34,    37,    76,    34,    34,
      15,     8,    24,    37,    37,    35,    34,    95,    97,    36,
      35,    37,    36,    84,    37,    35,    33,    -1,    -1,    -1,
      67
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    40,     0,     1,     3,     6,     9,    11,    13,    14,
      41,    42,    47,    51,    60,    64,    66,    35,    52,     7,
      10,    27,     4,    10,    27,    38,    53,    55,    27,    27,
      61,    27,    27,    34,     4,     8,    48,    43,    12,    35,
      65,    35,    55,    27,    36,    36,    36,    27,    62,    63,
       5,    35,    54,    22,    23,    24,    25,    26,    49,    50,
      27,    56,    27,    44,    45,    31,     5,    34,    27,    36,
      57,    58,    59,     5,    37,    34,    34,    37,    18,    19,
      20,    21,    46,    37,    34,    50,    57,    62,    28,    29,
      30,    31,    32,    33,    57,    16,    35,    15,    57,    35,
      49,    56,     8,    36,    35,    44,    35,    50,    50,    50,
      50,    50,    50,    37,    58,    59,    35,    36,    24,    49,
      37,    37,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    40,    41,    41,    41,    41,    41,
      41,    43,    42,    44,    44,    45,    46,    46,    46,    46,
      46,    47,    48,    47,    49,    49,    50,    50,    50,    50,
      50,    52,    51,    53,    54,    53,    55,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    61,    60,    62,    62,    63,    65,    64,    64,
      66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     3,     1,     1,     1,     1,     1,
       1,     0,     8,     1,     3,     2,     1,     1,     1,     4,
       1,     8,     0,    12,     1,     3,     1,     1,     1,     1,
       1,     0,     3,     4,     0,     7,     1,     1,     3,     1,
       3,     3,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     0,     8,     1,     3,     3,     0,     7,     4,
       4
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
  case 4: /* input: input error SEMICOLON  */
#line 109 "parser.y"
                            { yyerrok; yyclearin; }
#line 1279 "parser.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 122 "parser.y"
                             { reset_current_columns(); }
#line 1285 "parser.tab.c"
    break;

  case 12: /* create_table: CREATE TABLE_ IDENTIFIER $@1 LPAREN champs RPAREN SEMICOLON  */
#line 124 "parser.y"
    {
        if (add_table((yyvsp[-5].sval)) == -1)
            printf("ERREUR : table '%s' existe deja.\n", (yyvsp[-5].sval));
        else
            printf("CREATE TABLE detecte : %s\n", (yyvsp[-5].sval));
    }
#line 1296 "parser.tab.c"
    break;

  case 15: /* champ: IDENTIFIER type  */
#line 138 "parser.y"
                    { add_current_column((yyvsp[-1].sval)); }
#line 1302 "parser.tab.c"
    break;

  case 21: /* insert_into: INSERT INTO IDENTIFIER VALUES LPAREN valeurs RPAREN SEMICOLON  */
#line 151 "parser.y"
    {
        int idx = find_table((yyvsp[-5].sval));
        if (idx == -1) printf("ERREUR : table '%s' inexistante.\n", (yyvsp[-5].sval));
        else if ((yyvsp[-2].ival) != tables[idx].col_count)
            printf("ERREUR : %d valeurs mais table '%s' a %d colonnes.\n",
                   (yyvsp[-2].ival), (yyvsp[-5].sval), tables[idx].col_count);
        else
            printf("INSERT INTO %s : %d valeurs\n", (yyvsp[-5].sval), (yyvsp[-2].ival));
    }
#line 1316 "parser.tab.c"
    break;

  case 22: /* $@2: %empty  */
#line 160 "parser.y"
                           { reset_current_insert_columns(); }
#line 1322 "parser.tab.c"
    break;

  case 23: /* insert_into: INSERT INTO IDENTIFIER $@2 LPAREN liste_ident RPAREN VALUES LPAREN valeurs RPAREN SEMICOLON  */
#line 162 "parser.y"
    {
        int idx = find_table((yyvsp[-9].sval));
        if (idx == -1) printf("ERREUR : table '%s' inexistante.\n", (yyvsp[-9].sval));
        else if ((yyvsp[-6].ival) != (yyvsp[-2].ival))
            printf("ERREUR : %d colonnes listees mais %d valeurs.\n", (yyvsp[-6].ival), (yyvsp[-2].ival));
        else {
            int ok = 1;
            for (int i = 0; i < (yyvsp[-6].ival); i++)
                if (find_column_in_table(idx, current_insert_cols[i]) == -1) {
                    printf("ERREUR : colonne '%s' inexistante.\n", current_insert_cols[i]);
                    ok = 0;
                }
            if (ok)
                printf("INSERT INTO %s : %d colonnes OK\n", (yyvsp[-9].sval), (yyvsp[-6].ival));
        }
    }
#line 1343 "parser.tab.c"
    break;

  case 24: /* valeurs: valeur  */
#line 181 "parser.y"
             { (yyval.ival) = 1; }
#line 1349 "parser.tab.c"
    break;

  case 25: /* valeurs: valeur COMMA valeurs  */
#line 182 "parser.y"
                           { (yyval.ival) = 1 + (yyvsp[0].ival); }
#line 1355 "parser.tab.c"
    break;

  case 31: /* $@3: %empty  */
#line 194 "parser.y"
           { reset_current_select_cols(); }
#line 1361 "parser.tab.c"
    break;

  case 33: /* select_body: liste_champs FROM IDENTIFIER SEMICOLON  */
#line 200 "parser.y"
    {
        int idx = find_table((yyvsp[-1].sval));
        if (idx == -1) printf("ERREUR : table '%s' inexistante.\n", (yyvsp[-1].sval));
        else printf("SELECT simple, table=%s\n", (yyvsp[-1].sval));
    }
#line 1371 "parser.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 206 "parser.y"
    { current_table_idx_for_condition = find_table((yyvsp[0].sval)); current_table_name = (yyvsp[0].sval); }
#line 1377 "parser.tab.c"
    break;

  case 35: /* select_body: liste_champs FROM IDENTIFIER $@4 WHERE condition SEMICOLON  */
#line 208 "parser.y"
    {
        if (current_table_idx_for_condition == -1)
            printf("ERREUR : table '%s' inexistante.\n", (yyvsp[-4].sval));
        else
            printf("SELECT avec WHERE table=%s\n", (yyvsp[-4].sval));
    }
#line 1388 "parser.tab.c"
    break;

  case 36: /* liste_champs: STAR  */
#line 217 "parser.y"
           { last_select_used_star = 1; (yyval.ival) = 1; }
#line 1394 "parser.tab.c"
    break;

  case 37: /* liste_champs: IDENTIFIER  */
#line 218 "parser.y"
                 { add_current_select_col((yyvsp[0].sval)); (yyval.ival) = 1; }
#line 1400 "parser.tab.c"
    break;

  case 38: /* liste_champs: IDENTIFIER COMMA liste_champs  */
#line 219 "parser.y"
                                    { add_current_select_col((yyvsp[-2].sval)); (yyval.ival) = 1 + (yyvsp[0].ival); }
#line 1406 "parser.tab.c"
    break;

  case 39: /* liste_ident: IDENTIFIER  */
#line 223 "parser.y"
                 { add_current_insert_column((yyvsp[0].sval)); (yyval.ival) = 1; }
#line 1412 "parser.tab.c"
    break;

  case 40: /* liste_ident: IDENTIFIER COMMA liste_ident  */
#line 224 "parser.y"
                                   { add_current_insert_column((yyvsp[-2].sval)); (yyval.ival) = 1 + (yyvsp[0].ival); }
#line 1418 "parser.tab.c"
    break;

  case 52: /* $@5: %empty  */
#line 249 "parser.y"
    {
        current_table_idx_for_condition = find_table((yyvsp[0].sval));
        if (current_table_idx_for_condition == -1)
            printf("ERREUR : table '%s' inexistante.\n", (yyvsp[0].sval));
    }
#line 1428 "parser.tab.c"
    break;

  case 53: /* update_stmt: UPDATE IDENTIFIER $@5 SET modifications WHERE condition SEMICOLON  */
#line 255 "parser.y"
    {
        if (current_table_idx_for_condition != -1)
            printf("UPDATE table=%s\n", (yyvsp[-6].sval));
    }
#line 1437 "parser.tab.c"
    break;

  case 54: /* modifications: modification  */
#line 262 "parser.y"
                   { (yyval.ival) = 1; }
#line 1443 "parser.tab.c"
    break;

  case 55: /* modifications: modification COMMA modifications  */
#line 263 "parser.y"
                                       { (yyval.ival) = 1 + (yyvsp[0].ival); }
#line 1449 "parser.tab.c"
    break;

  case 57: /* $@6: %empty  */
#line 272 "parser.y"
    {
        current_table_idx_for_condition = find_table((yyvsp[0].sval));
        if (current_table_idx_for_condition == -1)
            printf("ERREUR : table '%s' inexistante.\n", (yyvsp[0].sval));
    }
#line 1459 "parser.tab.c"
    break;

  case 58: /* delete_stmt: DELETE FROM IDENTIFIER $@6 WHERE condition SEMICOLON  */
#line 278 "parser.y"
    {
        if (current_table_idx_for_condition != -1)
            printf("DELETE conditionnel table=%s\n", (yyvsp[-4].sval));
    }
#line 1468 "parser.tab.c"
    break;

  case 59: /* delete_stmt: DELETE FROM IDENTIFIER SEMICOLON  */
#line 283 "parser.y"
    {
        if (find_table((yyvsp[-1].sval)) == -1)
            printf("ERREUR : table '%s' inexistante.\n", (yyvsp[-1].sval));
        else
            printf("DELETE total table=%s\n", (yyvsp[-1].sval));
    }
#line 1479 "parser.tab.c"
    break;

  case 60: /* drop_table: DROP TABLE_ IDENTIFIER SEMICOLON  */
#line 293 "parser.y"
    {
        if (drop_table_entry((yyvsp[-1].sval)) == -1)
            printf("ERREUR : table '%s' inexistante.\n", (yyvsp[-1].sval));
        else
            printf("DROP TABLE %s\n", (yyvsp[-1].sval));
    }
#line 1490 "parser.tab.c"
    break;


#line 1494 "parser.tab.c"

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

#line 301 "parser.y"


void yyerror(const char *s){
    fprintf(stderr, "Erreur syntaxique ligne %d : %s\n", yylineno, s);
}
