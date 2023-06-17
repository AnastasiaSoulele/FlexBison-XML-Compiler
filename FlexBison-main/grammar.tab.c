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
#line 1 "grammar.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include <stdbool.h>
#define MAX_RADIO_BUTTONS 100
#define MAX_USED_IDS 100  
#define MAX_ID_LENGTH 100 
#define MAX_IDS 100


/** Extern from Flex **/
extern int lineno, 
           line_init;

extern char str_buf[256];    
extern char* str_buf_ptr;


/*Flex and bison*/
  extern int yylex();
  extern char *yytext;
  extern FILE *yyin;
  

  extern void yyterminate();

/* Variables for error handling and saving */
int error_count=0; 
int flag_err_type=0; // 0: Token Error (YYTEXT) || 1: String Error (STRBUF)
int scope=0;
int pos_number=0;
int flag=0;  //flag gia to token ean einai swsto to android
int valueflag=0;
char* strint;
char valid_radio_buttons[MAX_RADIO_BUTTONS][50];  // Array to store valid radio button ids
int valid_radio_button_count = 0;
int max_value = 0;  // Variable to store android:max values
char used_ids[MAX_USED_IDS][MAX_ID_LENGTH];  // Array to store used IDs
int used_id_count = 0;
int child_count = 0;  // Counter for child elements within <RadioGroup>    ///3
// char temp_checked_button;
char radio_button_ids[MAX_IDS][MAX_ID_LENGTH];    
int radio_button_id_count = 0;
char temp_checked_button[MAX_ID_LENGTH];
char* checked_button_id = NULL;  // New variable
char* removeQuotes(const char* input);
char used_checkb[MAX_USED_IDS][MAX_ID_LENGTH];
char check_radiob[MAX_USED_IDS][MAX_ID_LENGTH];
int flag_radio_button=0;
//char 


/*Specific Functions*/
void yyerror(const char *message);
bool isValidHexColor(const char* color);
bool isValidResource(const char* resource);
bool isValidPadding(const char* padding);
bool isValidID(const char* id);
bool containsDash(const char* str);
int dq_string_to_int(const char* str);
int isIdUsed(char* id);
void addUsedId(char* id);
void addUsedIdInt(int id);
///////////////////gia to 3o erwthma
void increment_child_count();
void check_radio_group_child_count(int expected_count);
/////////////////// gia to checkedButton
int is_valid_radio_button(const char* id);  
void addRadioButtonId(char* id);
int isIdUsedInRadioButtons(char* id);
int checkRadioButtonId();
void printRadioButtonIds();
void save_checked_button_id(char* id);
void checkRadioBId(char* id);
void check_values();

#line 150 "grammar.tab.c"

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

#include "grammar.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_LINEAR_LAYOUT = 3,            /* T_LINEAR_LAYOUT  */
  YYSYMBOL_T_RELATIVE_LAYOUT = 4,          /* T_RELATIVE_LAYOUT  */
  YYSYMBOL_T_TEXT_VIEW = 5,                /* T_TEXT_VIEW  */
  YYSYMBOL_T_IMAGE_VIEW = 6,               /* T_IMAGE_VIEW  */
  YYSYMBOL_T_BUTTON = 7,                   /* T_BUTTON  */
  YYSYMBOL_T_RADIO_BUTTON = 8,             /* T_RADIO_BUTTON  */
  YYSYMBOL_T_RADIO_GROUP = 9,              /* T_RADIO_GROUP  */
  YYSYMBOL_T_PROGRESS_BAR = 10,            /* T_PROGRESS_BAR  */
  YYSYMBOL_T_END_TAG = 11,                 /* T_END_TAG  */
  YYSYMBOL_T_END_LINEAR_LAYOUT = 12,       /* T_END_LINEAR_LAYOUT  */
  YYSYMBOL_T_END_RELATIVE_LAYOUT = 13,     /* T_END_RELATIVE_LAYOUT  */
  YYSYMBOL_T_END_TEXT_VIEW = 14,           /* T_END_TEXT_VIEW  */
  YYSYMBOL_T_END_IMAGE_VIEW = 15,          /* T_END_IMAGE_VIEW  */
  YYSYMBOL_T_END_BUTTON = 16,              /* T_END_BUTTON  */
  YYSYMBOL_T_END_RADIO_BUTTON = 17,        /* T_END_RADIO_BUTTON  */
  YYSYMBOL_T_END_RADIO_GROUP = 18,         /* T_END_RADIO_GROUP  */
  YYSYMBOL_T_END_PROGRESS_BAR = 19,        /* T_END_PROGRESS_BAR  */
  YYSYMBOL_T_ANDROID_LAYOUT_WIDTH = 20,    /* T_ANDROID_LAYOUT_WIDTH  */
  YYSYMBOL_T_ANDROID_LAYOUT_HEIGHT = 21,   /* T_ANDROID_LAYOUT_HEIGHT  */
  YYSYMBOL_T_ANDROID_ID = 22,              /* T_ANDROID_ID  */
  YYSYMBOL_T_ANDROID_TEXT = 23,            /* T_ANDROID_TEXT  */
  YYSYMBOL_T_ANDROID_ORIENTATION = 24,     /* T_ANDROID_ORIENTATION  */
  YYSYMBOL_T_ANDROID_SRC = 25,             /* T_ANDROID_SRC  */
  YYSYMBOL_T_ANDROID_PADDING = 26,         /* T_ANDROID_PADDING  */
  YYSYMBOL_T_ANDROID_TEXTCOLOR = 27,       /* T_ANDROID_TEXTCOLOR  */
  YYSYMBOL_T_ANDROID_CHECKEDBUTTON = 28,   /* T_ANDROID_CHECKEDBUTTON  */
  YYSYMBOL_T_ANDROID_PROGRESS = 29,        /* T_ANDROID_PROGRESS  */
  YYSYMBOL_T_ANDROID_MAX = 30,             /* T_ANDROID_MAX  */
  YYSYMBOL_T_COMMENT_OPEN = 31,            /* T_COMMENT_OPEN  */
  YYSYMBOL_T_COMMENT_CLOSE = 32,           /* T_COMMENT_CLOSE  */
  YYSYMBOL_T_STRING = 33,                  /* T_STRING  */
  YYSYMBOL_T_STRING_SINGLE_QUOTE = 34,     /* T_STRING_SINGLE_QUOTE  */
  YYSYMBOL_T_POSITIVE_INTEGER = 35,        /* T_POSITIVE_INTEGER  */
  YYSYMBOL_T_SLASH_END_TAG = 36,           /* T_SLASH_END_TAG  */
  YYSYMBOL_T_STRING_DQ_SPACE = 37,         /* T_STRING_DQ_SPACE  */
  YYSYMBOL_T_DOT = 38,                     /* T_DOT  */
  YYSYMBOL_39_ = 39,                       /* "."  */
  YYSYMBOL_T_COMMA = 40,                   /* T_COMMA  */
  YYSYMBOL_41_ = 41,                       /* ","  */
  YYSYMBOL_T_ASSIGN = 42,                  /* T_ASSIGN  */
  YYSYMBOL_43_ = 43,                       /* "="  */
  YYSYMBOL_T_COLON = 44,                   /* ":"  */
  YYSYMBOL_T_LBRACK = 45,                  /* T_LBRACK  */
  YYSYMBOL_46_ = 46,                       /* "["  */
  YYSYMBOL_T_RBRACK = 47,                  /* T_RBRACK  */
  YYSYMBOL_48_ = 48,                       /* "]"  */
  YYSYMBOL_T_SLASH = 49,                   /* "/"  */
  YYSYMBOL_T_EXCLAMATION = 50,             /* "!"  */
  YYSYMBOL_T_DASH = 51,                    /* "-"  */
  YYSYMBOL_T_LBRACES = 52,                 /* "{"  */
  YYSYMBOL_T_RBRACES = 53,                 /* "}"  */
  YYSYMBOL_T_AT = 54,                      /* T_AT  */
  YYSYMBOL_55_ = 55,                       /* "@"  */
  YYSYMBOL_T_QUESTION_MARK = 56,           /* "?"  */
  YYSYMBOL_T_UNDERSCORE = 57,              /* "_"  */
  YYSYMBOL_T_HASH = 58,                    /* "#"  */
  YYSYMBOL_T_SQUOTES = 59,                 /* "'"  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_linearlayout = 62,              /* linearlayout  */
  YYSYMBOL_linearlayout2 = 63,             /* linearlayout2  */
  YYSYMBOL_linearlayoutattributes = 64,    /* linearlayoutattributes  */
  YYSYMBOL_layout_width = 65,              /* layout_width  */
  YYSYMBOL_layout_height = 66,             /* layout_height  */
  YYSYMBOL_android_id = 67,                /* android_id  */
  YYSYMBOL_android_orientation = 68,       /* android_orientation  */
  YYSYMBOL_text = 69,                      /* text  */
  YYSYMBOL_textColor = 70,                 /* textColor  */
  YYSYMBOL_checkedButton = 71,             /* checkedButton  */
  YYSYMBOL_progress = 72,                  /* progress  */
  YYSYMBOL_padding = 73,                   /* padding  */
  YYSYMBOL_max = 74,                       /* max  */
  YYSYMBOL_src = 75,                       /* src  */
  YYSYMBOL_relativelayout = 76,            /* relativelayout  */
  YYSYMBOL_relativelayout2 = 77,           /* relativelayout2  */
  YYSYMBOL_relativelayoutattributes = 78,  /* relativelayoutattributes  */
  YYSYMBOL_textview = 79,                  /* textview  */
  YYSYMBOL_textviewattributes = 80,        /* textviewattributes  */
  YYSYMBOL_imageview = 81,                 /* imageview  */
  YYSYMBOL_imageviewattributes = 82,       /* imageviewattributes  */
  YYSYMBOL_radiogroup = 83,                /* radiogroup  */
  YYSYMBOL_radio_start = 84,               /* radio_start  */
  YYSYMBOL_radio_end = 85,                 /* radio_end  */
  YYSYMBOL_radiogroupattributes = 86,      /* radiogroupattributes  */
  YYSYMBOL_radiobutton = 87,               /* radiobutton  */
  YYSYMBOL_radiobuttonattributes = 88,     /* radiobuttonattributes  */
  YYSYMBOL_progressbar = 89,               /* progressbar  */
  YYSYMBOL_progressbarattributes = 90,     /* progressbarattributes  */
  YYSYMBOL_comment = 91,                   /* comment  */
  YYSYMBOL_element = 92                    /* element  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   174,   174,   175,   178,   179,   182,   183,   184,   188,
     189,   190,   191,   194,   215,   221,   235,   247,   259,   279,
     304,   315,   324,   333,   356,   364,   381,   396,   407,   417,
     418,   419,   420,   421,   422,   425,   426,   427,   431,   432,
     433,   434,   437,   440,   441,   442,   445,   448,   449,   450,
     451,   462,   465,   470,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   519,   520,   523,   524,   525,   529,
     532,   533,   534,   535,   539,   557,   558,   559,   560,   561,
     562,   563,   564,   565
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_LINEAR_LAYOUT",
  "T_RELATIVE_LAYOUT", "T_TEXT_VIEW", "T_IMAGE_VIEW", "T_BUTTON",
  "T_RADIO_BUTTON", "T_RADIO_GROUP", "T_PROGRESS_BAR", "T_END_TAG",
  "T_END_LINEAR_LAYOUT", "T_END_RELATIVE_LAYOUT", "T_END_TEXT_VIEW",
  "T_END_IMAGE_VIEW", "T_END_BUTTON", "T_END_RADIO_BUTTON",
  "T_END_RADIO_GROUP", "T_END_PROGRESS_BAR", "T_ANDROID_LAYOUT_WIDTH",
  "T_ANDROID_LAYOUT_HEIGHT", "T_ANDROID_ID", "T_ANDROID_TEXT",
  "T_ANDROID_ORIENTATION", "T_ANDROID_SRC", "T_ANDROID_PADDING",
  "T_ANDROID_TEXTCOLOR", "T_ANDROID_CHECKEDBUTTON", "T_ANDROID_PROGRESS",
  "T_ANDROID_MAX", "T_COMMENT_OPEN", "T_COMMENT_CLOSE", "T_STRING",
  "T_STRING_SINGLE_QUOTE", "T_POSITIVE_INTEGER", "T_SLASH_END_TAG",
  "T_STRING_DQ_SPACE", "T_DOT", "\".\"", "T_COMMA", "\",\"", "T_ASSIGN",
  "\"=\"", "\":\"", "T_LBRACK", "\"[\"", "T_RBRACK", "\"]\"", "\"/\"",
  "\"!\"", "\"-\"", "\"{\"", "\"}\"", "T_AT", "\"@\"", "\"?\"", "\"_\"",
  "\"#\"", "\"'\"", "$accept", "program", "linearlayout", "linearlayout2",
  "linearlayoutattributes", "layout_width", "layout_height", "android_id",
  "android_orientation", "text", "textColor", "checkedButton", "progress",
  "padding", "max", "src", "relativelayout", "relativelayout2",
  "relativelayoutattributes", "textview", "textviewattributes",
  "imageview", "imageviewattributes", "radiogroup", "radio_start",
  "radio_end", "radiogroupattributes", "radiobutton",
  "radiobuttonattributes", "progressbar", "progressbarattributes",
  "comment", "element", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      95,   -13,   -13,    23,   -24,   -67,     6,    12,    12,   -67,
      27,   -67,   -67,   -67,   -67,   157,    17,   109,   119,   157,
     -13,   -13,   -13,   -13,   -67,   -13,    13,   -67,   157,   157,
     157,   157,   157,   -67,   130,   -67,   -67,    25,    16,   140,
     157,   -67,   -67,   -67,    40,    84,    12,    18,    12,    26,
      12,    28,   -13,    12,    30,   -67,   -67,   -67,   -67,   -67,
     -67,    69,    64,   -67,   -67,   -67,   157,   -67,   -67,   -67,
     157,   157,    67,    71,    78,   -67,    55,   -67,    78,    74,
      12,    85,    81,   -67,   -13,   -67,   -67,    75,   147,    40,
     157,    97,   -27,    82,   -67,    77,   -14,    82,   -67,   -67,
      63,    74,    86,   100,    87,   -67,   -67,   108,   -67,   113,
     -13,   -67,   -67,   103,   -67,    73,   106,   -67,   115,    -4,
     -67,   115,   -67,   124,   125,   157,   137,   158,   -67,   159,
     139,   -67,   -67,   -67,   -67,    11,   -67,   -67,   155,   -67,
     141,   -67,   162,   -67,   -67,   -67,   -67,    74,   -67,   -67,
     -67,    69,   -67,   -67
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    41,     0,     0,     2,     0,     0,     0,     3,
       0,     1,    13,    15,    14,    83,     0,    83,    38,    83,
      41,     0,     0,     0,    52,     0,     0,    82,    83,    83,
      80,    83,    83,    81,     0,    16,    17,     0,     0,    83,
      83,     9,    39,    40,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    78,    75,    79,    76,
      77,     6,     0,    19,    18,    20,    83,    10,    11,    36,
      83,     0,     0,     0,     0,    42,     0,    46,     0,    64,
       0,     0,    70,    69,     0,     7,     8,     0,     0,     0,
      83,     0,     0,     0,    43,     0,    47,     0,    66,    65,
      54,     0,    71,     0,     0,    12,    29,     0,    31,     0,
       0,    21,    22,    44,    28,     0,    48,    50,    67,    55,
      56,    57,    53,     0,    72,    83,     0,    30,    32,     0,
       0,    45,    26,    49,    68,    59,    61,    58,     0,    27,
       0,    73,     0,    74,    34,    33,    23,    60,    62,    51,
      25,     4,    63,     5
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,    29,   -67,    93,    -1,    -5,   -17,   142,   -23,
     -67,   -62,   -67,    62,   -67,   -67,   -42,   -67,   -15,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -66,   -67,    88,
      72,   -67,    -3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    85,     5,     6,     8,    17,    39,    40,    94,
     131,    27,   141,   117,   124,    96,    28,     9,    10,    29,
      47,    30,    49,    31,    52,   138,    81,    32,    51,    33,
      54,   105,    34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       7,    42,    69,    18,    23,    45,   111,     4,    37,    12,
     112,    13,   115,    99,    41,    43,    44,    15,    37,    23,
      46,    48,    50,    11,    53,    56,    57,    58,    59,    60,
      72,    62,    14,    16,   121,   122,    67,    68,   120,    26,
      19,    74,    73,    76,    20,    78,    55,   108,    82,    65,
      35,    80,    36,   136,    75,    98,   134,    93,    63,   137,
      64,    97,    77,    87,    79,   102,    83,    88,    89,   148,
     113,    23,    84,   147,   118,   100,    86,   119,    90,   116,
      95,   152,    23,     7,    91,   107,    92,   109,    20,    21,
      22,    26,    23,    24,    25,    70,   101,    71,     1,     2,
      37,    92,   135,    37,     4,    92,   104,    25,   132,    53,
     114,   125,    26,    20,    21,    22,   123,    23,    24,    25,
     126,   127,   142,    20,    21,    22,   128,    23,    24,    25,
     130,    37,   115,    38,    20,    21,    22,    26,    23,    24,
      25,    37,    61,    26,    20,    21,    22,    26,    23,    24,
      25,    20,    21,    22,   140,    23,    24,    25,    26,   139,
     106,    20,    21,    22,    38,    23,    24,    25,    26,   143,
     144,   145,   146,   149,   151,    26,   150,   103,   133,   110,
     153,    66,   129,     0,     0,    26
};

static const yytype_int16 yycheck[] =
{
       1,    18,    44,     8,     8,    20,    33,    20,    22,    33,
      37,    35,    26,    79,    17,    18,    19,    11,    22,     8,
      21,    22,    23,     0,    25,    28,    29,    30,    31,    32,
      45,    34,    56,    21,   100,   101,    39,    40,   100,    28,
      13,    46,    45,    48,     4,    50,    33,    89,    53,    33,
      33,    52,    35,   119,    36,    78,   118,    74,    33,   121,
      35,    78,    36,    66,    36,    82,    36,    70,    71,   135,
      93,     8,     3,   135,    97,    80,    12,   100,    11,    96,
      25,   147,     8,    84,    13,    88,    23,    90,     4,     5,
       6,    28,     8,     9,    10,    11,    11,    13,     3,     4,
      22,    23,   119,    22,    20,    23,    31,    10,    35,   110,
      33,    11,    28,     4,     5,     6,    30,     8,     9,    10,
      33,    13,   125,     4,     5,     6,    13,     8,     9,    10,
      27,    22,    26,    24,     4,     5,     6,    28,     8,     9,
      10,    22,    12,    28,     4,     5,     6,    28,     8,     9,
      10,     4,     5,     6,    29,     8,     9,    10,    28,    35,
      13,     4,     5,     6,    24,     8,     9,    10,    28,    32,
      12,    12,    33,    18,    12,    28,    35,    84,   116,    91,
     151,    39,   110,    -1,    -1,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    61,    20,    63,    64,    65,    65,    77,
      78,     0,    33,    35,    56,    11,    21,    66,    66,    13,
       4,     5,     6,     8,     9,    10,    28,    71,    76,    79,
      81,    83,    87,    89,    92,    33,    35,    22,    24,    67,
      68,    92,    67,    92,    92,    78,    65,    80,    65,    82,
      65,    88,    84,    65,    90,    33,    92,    92,    92,    92,
      92,    12,    92,    33,    35,    33,    68,    92,    92,    76,
      11,    13,    78,    92,    66,    36,    66,    36,    66,    36,
      65,    86,    66,    36,     3,    62,    12,    92,    92,    92,
      11,    13,    23,    67,    69,    25,    75,    67,    69,    87,
      66,    11,    67,    64,    31,    91,    13,    92,    76,    92,
      89,    33,    37,    69,    33,    26,    67,    73,    69,    69,
      71,    87,    87,    30,    74,    11,    33,    13,    13,    90,
      27,    70,    35,    73,    71,    67,    87,    71,    85,    35,
      29,    72,    92,    32,    12,    12,    33,    71,    87,    18,
      35,    12,    87,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    63,    63,    63,    64,
      64,    64,    64,    65,    65,    65,    66,    66,    67,    67,
      68,    69,    69,    70,    71,    72,    73,    74,    75,    76,
      76,    76,    76,    76,    76,    77,    77,    77,    78,    78,
      78,    78,    79,    80,    80,    80,    81,    82,    82,    82,
      82,    83,    84,    85,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    87,    87,    88,    88,    88,    89,
      90,    90,    90,    90,    91,    92,    92,    92,    92,    92,
      92,    92,    92,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     5,     6,     4,     5,     5,     3,
       4,     4,     6,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     5,
       6,     5,     6,     7,     7,     3,     4,     3,     2,     3,
       3,     0,     3,     3,     4,     5,     3,     3,     4,     5,
       4,     7,     0,     0,     2,     3,     3,     3,     4,     4,
       5,     4,     5,     6,     3,     4,     3,     4,     5,     3,
       2,     3,     4,     5,     3,     2,     2,     2,     2,     2,
       1,     1,     1,     0
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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

  if (yychar <= T_EOF)
    {
      yychar = T_EOF;
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
  case 13: /* layout_width: T_ANDROID_LAYOUT_WIDTH T_STRING  */
#line 195 "grammar.y"
                           {  
                            if (strcmp((yyvsp[-1].strval), "android:layout_width=") == 0 || flag==1) {  //ama to flag exei ginei 1 exei mpei hdh mia fora kai einai swsto to android opote meta tha pairnei to string apla
                                  //printf("EDW TO FLAG :\t%d\t",flag);
                                  flag=1;
                               if (strcmp((yyvsp[0].strval), "\"match_parent\"") == 0 || strcmp((yyvsp[0].strval), "\"wrap_content\"") == 0){   //|| strcmp($2, T_DIMENSION) == 0 || strcmp($2, T_PERCENTAGE) == 0) {
                                  //printf("%s = %s\n", $1, $2);
                                  valueflag=1;
                                } 
                                 
                                }
                            else 
                              yyerror("Expected android:layout_width=");

                            if(valueflag==0 ) //an ta string != value poy prepei na exoyn
                                  {
                                    printf("Invalid value for android:layout_width: %s\n", (yyvsp[0].strval));
                                    yyerror("Invalid value.");
                                  } 
                           }
#line 1641 "grammar.tab.c"
    break;

  case 14: /* layout_width: T_ANDROID_LAYOUT_WIDTH "?"  */
#line 216 "grammar.y"
                           {
                            printf("\nWrong!\n");
                            yyerror("Invalid value.");
                           }
#line 1650 "grammar.tab.c"
    break;

  case 15: /* layout_width: T_ANDROID_LAYOUT_WIDTH T_POSITIVE_INTEGER  */
#line 221 "grammar.y"
                                                                     {
                            
                            flag=0;
                            if(strcmp((yyvsp[-1].strval), "android:layout_width=") == 0 || flag == 1){
                               flag=1;
                               pos_number=atoi((yyvsp[0].strval));
                               //printf("%s = %d\n", $1, pos_number);
                               }
                            else yyerror("Expected android:layout_width=");
                           }
#line 1665 "grammar.tab.c"
    break;

  case 16: /* layout_height: T_ANDROID_LAYOUT_HEIGHT T_STRING  */
#line 236 "grammar.y"
                            {   flag=0;
                            if (strcmp((yyvsp[-1].strval), "android:layout_height=") == 0 || flag == 1) {\
                                flag=1;
                               if (strcmp((yyvsp[0].strval), "\"match_parent\"") == 0 || strcmp((yyvsp[0].strval), "\"wrap_content\"") == 0){ // || strcmp($2, T_DIMENSION) == 0 || strcmp($2, T_PERCENTAGE) == 0) {
                                  //printf("%s = %s\n", $1, $2);
                                } else 
                                   printf("Invalid value for android:layout_height: %s\n", (yyvsp[0].strval));
                                }
                            else 
                              yyerror("Expected android:layout_height=");
                            }
#line 1681 "grammar.tab.c"
    break;

  case 17: /* layout_height: T_ANDROID_LAYOUT_HEIGHT T_POSITIVE_INTEGER  */
#line 247 "grammar.y"
                                                                      {
                            flag=0;
                            if(strcmp((yyvsp[-1].strval), "android:layout_height=") == 0 || flag==1){
                                flag=1;
                               pos_number=atoi((yyvsp[0].strval));
                               //printf("%s = %d\n", $1, pos_number);
                               }
                            else yyerror("Expected android:layout_height=");
                            }
#line 1695 "grammar.tab.c"
    break;

  case 18: /* android_id: T_ANDROID_ID T_POSITIVE_INTEGER  */
#line 260 "grammar.y"
                {
                    flag = 0;
                    if (strcmp((yyvsp[-1].strval), "android:id=") == 0 || flag == 1) {
                        flag = 1;
                        pos_number = dq_string_to_int((yyvsp[0].strval));
                        printf("%s = %d\n", (yyvsp[-1].strval), pos_number);
                        char pos_number_str[20];  // Buffer to hold the string representation of pos_number
                        snprintf(pos_number_str, sizeof(pos_number_str), "%d", pos_number);

                        if (isIdUsed(pos_number_str)) {
                            yyerror("The android:id value is not unique.");
                        } else {
                            addUsedId(pos_number_str);
                            addRadioButtonId(pos_number_str); // Add the radio button ID
                        }
                    } else {
                        yyerror("Expected android:id=");
                    }
                }
#line 1719 "grammar.tab.c"
    break;

  case 19: /* android_id: T_ANDROID_ID T_STRING  */
#line 280 "grammar.y"
                {
                    flag = 0;
                    if (strcmp((yyvsp[-1].strval), "android:id=") == 0 || flag == 1) {
                        flag = 1;
                        printf("%s = %s\n", (yyvsp[-1].strval), (yyvsp[0].strval));

                        if(flag_radio_button==1){
                            checkRadioBId((yyvsp[0].strval));
                        }

                        if(isIdUsed((yyvsp[0].strval))){
                            yyerror("The android:id value is not unique.");
                        }else{
                            addUsedId((yyvsp[0].strval));
                           // addRadioButtonId($2); // Add the radio button ID
                        }
                    } else {
                        yyerror("Expected android:id=");
                    }
                }
#line 1744 "grammar.tab.c"
    break;

  case 20: /* android_orientation: T_ANDROID_ORIENTATION T_STRING  */
#line 305 "grammar.y"
                                 {  flag=0;
                                 if(strcmp((yyvsp[-1].strval), "android:orientation=") == 0 || flag==1){
                                        flag=1;
                                    if(strcmp((yyvsp[0].strval), "\"horizontal\"") == 0 || strcmp((yyvsp[0].strval), "\"vertical\"") == 0)
                                    printf("%s = %s\n", (yyvsp[-1].strval), (yyvsp[0].strval));
                                    }
                                 else yyerror("Expected android:orientation="); 
                                 }
#line 1757 "grammar.tab.c"
    break;

  case 21: /* text: T_ANDROID_TEXT T_STRING  */
#line 316 "grammar.y"
                                 {  
                                    flag=0;
                                    if(strcmp((yyvsp[-1].strval), "android:text=") == 0 || flag==1){
                                        flag=1;
                                    printf("%s = %s\n", (yyvsp[-1].strval), (yyvsp[0].strval));}
                                 else yyerror("Expected android:text="); 
                                }
#line 1769 "grammar.tab.c"
    break;

  case 22: /* text: T_ANDROID_TEXT T_STRING_DQ_SPACE  */
#line 325 "grammar.y"
                                {flag=0;
                                    if(strcmp((yyvsp[-1].strval), "android:text=") == 0 || flag==1){
                                        flag=1;
                                    printf("%s = %s\n", (yyvsp[-1].strval), (yyvsp[0].strval));}
                                 else yyerror("Expected android:text="); 
                                }
#line 1780 "grammar.tab.c"
    break;

  case 23: /* textColor: T_ANDROID_TEXTCOLOR T_STRING  */
#line 334 "grammar.y"
                                  { flag=0;
                                    if(strcmp((yyvsp[-1].strval), "android:textColor=") == 0 || flag==1){
                                        flag=1;
                                    printf("%s = %s\n", (yyvsp[-1].strval), (yyvsp[0].strval));}
                                    else yyerror("Expected android:textColor=");    
                                  }
#line 1791 "grammar.tab.c"
    break;

  case 24: /* checkedButton: T_ANDROID_CHECKEDBUTTON T_STRING  */
#line 357 "grammar.y"
                    {
                    save_checked_button_id((yyvsp[0].strval));
                    printf("%s = %s\n", (yyvsp[-1].strval), (yyvsp[0].strval));                    
                    }
#line 1800 "grammar.tab.c"
    break;

  case 25: /* progress: T_ANDROID_PROGRESS T_POSITIVE_INTEGER  */
#line 365 "grammar.y"
                                        {
                                            if (strcmp((yyvsp[-1].strval), "android:progress=") == 0 || flag == 1) {
                                                flag = 1;
                                                int progress = dq_string_to_int((yyvsp[0].strval));
                                                if (progress >= 0 && progress <= max_value) {
                                                    printf("%s = %d\n", (yyvsp[-1].strval), progress);
                                                } else {
                                                    yyerror("Invalid android:progress value");
                                                }
                                            } else {
                                                yyerror("Expected android:progress=");
                                            }
                                        }
#line 1818 "grammar.tab.c"
    break;

  case 26: /* padding: T_ANDROID_PADDING T_POSITIVE_INTEGER  */
#line 382 "grammar.y"
                            { flag=0;
                            if(strcmp((yyvsp[-1].strval), "android:padding=") == 0 || flag ==1) {
                                flag=1;
                                pos_number = atoi((yyvsp[0].strval));
                                    if (pos_number < 0) {
                                      yyerror("Invalid progress value. It should be a positive integer.");
                                    }
                                    printf("%s = ''%d''\n", (yyvsp[-1].strval), pos_number);}
                             else {
                                yyerror("Expected android:padding=");
                                  }
                            }
#line 1835 "grammar.tab.c"
    break;

  case 27: /* max: T_ANDROID_MAX T_POSITIVE_INTEGER  */
#line 397 "grammar.y"
                            {
                                if (strcmp((yyvsp[-1].strval), "android:max=") == 0) {
                                    max_value = dq_string_to_int((yyvsp[0].strval));
                                    printf("%s = %d\n", (yyvsp[-1].strval), max_value);
                                } else {
                                    yyerror("Expected android:max=");
                                }
                            }
#line 1848 "grammar.tab.c"
    break;

  case 28: /* src: T_ANDROID_SRC T_STRING  */
#line 408 "grammar.y"
                                {   flag=0;
                                    if(strcmp((yyvsp[-1].strval), "android:src=") == 0|| flag==1){
                                        flag=1;
                                    printf("%s = %s\n", (yyvsp[-1].strval), (yyvsp[0].strval));}
                                 else yyerror("Expected android:src="); 
                                }
#line 1859 "grammar.tab.c"
    break;

  case 52: /* radio_start: %empty  */
#line 466 "grammar.y"
                        {
                        flag_radio_button =1;
                        }
#line 1867 "grammar.tab.c"
    break;

  case 53: /* radio_end: %empty  */
#line 471 "grammar.y"
                        {
                        flag_radio_button =0;
                        check_values();
                        int i;
                        for(i=0;i<3;i++){
                            printf("\n VVVVVVVVVVVVVVVV Checked Button value:\n %s",used_checkb[i]);
                        }
                        
                        for(i=0;i<3;i++){
                            printf("\n AAAAAAAAAAAAAAAAAA Radio Button id value:\n %s",check_radiob[i]);
                        } 
                        }
#line 1884 "grammar.tab.c"
    break;

  case 74: /* comment: T_COMMENT_OPEN T_STRING T_COMMENT_CLOSE  */
#line 539 "grammar.y"
                                                                {
                             if (strcmp((yyvsp[-2].strval), "<!--")==0 && strcmp((yyvsp[0].strval), "-->")==0 && !containsDash((yyvsp[-1].strval))) {
                                    printf("%s %s %s\n", (yyvsp[-2].strval), (yyvsp[-1].strval), (yyvsp[0].strval));
                            } else 
                                    yyerror("Invalid comment");
                            }
#line 1895 "grammar.tab.c"
    break;


#line 1899 "grammar.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= T_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == T_EOF)
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 571 "grammar.y"


int main(int argc, char *argv[]){
    int token;

    /*Διάβασμα του αρχείου*/



    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if (yyin == NULL){
            perror ("Error opening file"); 
            return -1;
        }
    }

    /*Κάνε συνατικτική ανάλυση*/
    yyparse();


   if(error_count > 0){
        printf("Syntax Analysis failed due to %d errors\n", error_count);
        printRadioButtonIds();

      }
        
   else{
        printf("Syntax Analysis completed successfully.\n");
      }

    return 0;
    yyrestart(yyin);
    fclose(yyin);
}

bool isValidHexColor(const char* color) {
    if (color[0] == '#' && strlen(color) == 7) {
        for (int i = 1; i < 7; i++) {
            if (!isxdigit(color[i])) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool isValidResource(const char* resource) {
    if (resource[0] != '@') 
        return false;


    if (resource[1] == '+') 
        resource++;


    if (strncmp(resource, "@id/", 4) != 0) 
        return false;


    for (int i = 4; resource[i] != '\0'; i++) {
        if (!isalnum(resource[i]) && resource[i] != '_') {
            return false;
        }
    }

    return true;
}

bool isValidPadding(const char* padding) {
    int len = strlen(padding);
    if(len == 0) {
        return false;
    }
    // check for dimension
    if(padding[len-2] == 'd' && padding[len-1] == 'p') {
        for(int i = 0; i < len-2; i++) {
            if(!isdigit(padding[i])) {
                return false;
            }
        }
        return true;
    }
    // check for pixel
    if(padding[len-2] == 'p' && padding[len-1] == 'x') {
        for(int i = 0; i < len-2; i++) {
            if(!isdigit(padding[i])) {
                return false;
            }
        }
        return true;
    }
    // check for positive integer
    for(int i = 0; i < len; i++) {
        if(!isdigit(padding[i])) {
            return false;
        }
    }
    return true;
}

bool isValidID(const char* id) {
    int len = strlen(id);
    for(int i = 0; i < len; i++) {
        if (!(isalnum(id[i]) || id[i] == '@' || id[i] == '+' || id[i] == '_' || id[i] == '.')) {
            return false;
        }
    }
    return true;
}

bool containsDash(const char* str) {
    return strchr(str, '-') != NULL;
}



void yyerror(const char *message)
{
    error_count++;
    
    if(flag_err_type==0){
        printf("-> ERROR at line %d caused by %s : %s\n", lineno, yytext, message);
    }else if(flag_err_type==1){
        *str_buf_ptr = '\0'; 
        printf("-> ERROR at line %d near \"%s\": %s\n", lineno, str_buf, message);
    }

    flag_err_type = 0; 
    if(MAX_ERRORS <= 0) return;
    if(error_count == MAX_ERRORS){
        printf("Max errors (%d) detected. ABORTING...\n", MAX_ERRORS);
        exit(-1);
    }
}


int dq_string_to_int(const char* str) {
    if (str[0] == '"' && str[strlen(str)-1] == '"') {
        char* new_str = malloc(strlen(str) - 1);
        strncpy(new_str, str + 1, strlen(str) - 2); 
        new_str[strlen(str) - 2] = '\0'; 

        int result = atoi(new_str); 
        free(new_str); 
        return result;
    } else {
        
        return 0;
    }
}

int is_valid_radio_button(const char* id) {
    for (int i = 0; i < valid_radio_button_count; i++) {
        if (strcmp(valid_radio_buttons[i], id) == 0) {
            return 1;  // Valid radio button id found
        }
    }
    return 0;  // Invalid radio button id
}

int isIdUsed(char* id) {
    for (int i = 0; i < used_id_count; i++) {
        if (strcmp(used_ids[i], id) == 0) {
            return 1;  // ID is already used
        }
    }
    return 0;  // ID is not used
}


void addUsedId(char* id) {
    strncpy(used_ids[used_id_count++], id, MAX_ID_LENGTH - 1);
    used_ids[used_id_count - 1][MAX_ID_LENGTH - 1] = '\0';  // Ensure null-termination
}

void addUsedIdInt(int id) {
    char id_string[MAX_ID_LENGTH];
    snprintf(id_string, sizeof(id_string), "%d", id);
    addUsedId(id_string);
}

//////////////////////////////////////////////////////////////////////////////// 3o erwthma /////////////////////////////////////////////////////////////

/* void increment_child_count() {
    child_count++;
}

// Function to check the number of children for <RadioGroup> 
void check_radio_group_child_count(int expected_count) {
    if (child_count != expected_count) {
        char error_message[100];
        sprintf(error_message, "Invalid number of children. Expected %d children for <RadioGroup>.", expected_count);
        yyerror(error_message);
    }
    // Reset child count for the next <RadioGroup>
    child_count = 0;
} */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* void addRadioButtonId(char* id) {
    strncpy(radio_button_ids[radio_button_id_count++], id, MAX_ID_LENGTH - 1);
    radio_button_ids[radio_button_id_count - 1][MAX_ID_LENGTH - 1] = '\0';  // Ensure null-termination
} */

////////////////////////////////////////////////////////

/* void addRadioButtonId(char* id) {
    strncpy(radio_button_ids[radio_button_id_count++], id, MAX_ID_LENGTH - 1);
    radio_button_ids[radio_button_id_count - 1][MAX_ID_LENGTH - 1] = '\0';  // Ensure null-termination
} */

void addRadioButtonId(char* id) {
    strncpy(radio_button_ids[radio_button_id_count++], id, MAX_ID_LENGTH - 1);
    radio_button_ids[radio_button_id_count - 1][MAX_ID_LENGTH - 1] = '\0';  // Ensure null-termination
    printf("Added RadioButton id: %s\n", id);
}


int checkRadioButtonId() {
    if (checked_button_id != NULL) {
        for(int i = 0; i < radio_button_id_count; i++) {
            if(strcmp(radio_button_ids[i], checked_button_id) == 0) {
                return 1;
            }
        }
        char error_message[100];
        sprintf(error_message, "CHECKED BUTTON VALUE '%s' ISN'T IN THE USED RadioButton IDs LISSSSSSST", checked_button_id);
        yyerror(error_message);
        return 0;
    }
    return 1;
}

void printRadioButtonIds() {
    printf("\n\nRadioButton IDs:\n");
    for (int i = 0; i < radio_button_id_count; i++) {
        printf("%s\n", radio_button_ids[i]);
    }
}

char* removeQuotes(const char* input) {
    size_t len = strlen(input);
    if (len < 2) return NULL; // the input is too short to contain quotes

    // Check if the input string is quoted
    if (input[0] != '"' || input[len-1] != '"') return NULL; // the input is not quoted

    // Allocate memory for output string, with extra space for null-terminator
    char* output = (char*) malloc(len-1);

    if (output == NULL) return NULL; // allocation failed

    // Copy the input string to output string, without the first and last character
    strncpy(output, input + 1, len - 2);

    // Null-terminate the output string
    output[len - 2] = '\0';

    return output;
}

void save_checked_button_id(char* id){
  static int k = 0;
  size_t len = strlen(id);

     strncpy(used_checkb[k], id, len);
     k++;
     
     for(int i=0;i<k;i++){
        //printf("\n%s\n",used_checkb[i]);
     }

}

void checkRadioBId(char* id){
      static int k = 0;
      size_t len = strlen(id);

     strncpy(check_radiob[k], id, len);
     k++;
     
     for(int i=0;i<k;i++){
     printf("\n%s\n",check_radiob[i]);
//printf("\n\n\n\n\n:RADIO BUTTON IDS: %s",check_radiob[i]);         // edw ginetai save se kathe button id kanonika topika 
     }
    
    //printf("%s KKKKKKKKKKKKKKKKKKKKK \n",check_radiob[k-1]);

}

/* void check_values(){
    int i,j;
    int check_flag=0;
    int counter=0;

    for(i=0;i<5;i++){
        for(j=0;j<i+1;j++){
            if(strcmp(used_checkb[i],check_radiob[j])==0){             ///////////// flag 
                check_flag=1;
                counter++;
               // printf("\n CCCCCCC %s, BBBBBBBBB %s ", used_checkb[i],check_radiob[j]);
            }
        }
    //printf("\n Counter: %d\n", counter);
    }

    printf("\n\n FLAGGGGGGGGGG: \n %d \n", check_flag);

    if(check_flag==0){
        char error_message[100];
            sprintf(error_message, "CHECKED BUTTON VALUE ISN'T IN THE USED RadioButton IDs LIST");
            yyerror(error_message);  
            //printf("\n FSHDFSHNEFJEFEN \n");
    }else{
    printf("The values are the same!\n\n");
    }

            /* for(i=0;i<3;i++){
                printf("\nChecked Button value:\n %s",used_checkb[i]);
            }
            
            for(i=0;i<3;i++){
                printf("\nRadio Button id value:\n %s",check_radiob[i]);
            } */

              /* printf("\n RRRRRRRRRRRRRRRRRRRR :\n %s",check_radiob[0]);
              printf("\n RRRRRRRRRRRRRRRRRRRR :\n %s",check_radiob[1]);
              printf("\n RRRRRRRRRRRRRRRRRRRR :\n %s",used_checkb[0]); */


/* }  */

void check_values() {
    int i, j;
    int check_flag = 0;
    int counter = 0;

    for (i = 0; i < 5; i++) {
        int match_found = 0; // Variable to track if a match is found for each used_checkb value
        for (j = 0; j < 5; j++) {
            if (strcmp(used_checkb[i], check_radiob[j]) == 0) {
                match_found = 1; // Match found, set the flag
                counter++;
                 printf("\n CCCCCCC %s, BBBBBBBBB %s ", used_checkb[i],check_radiob[j]);
                break; // No need to continue the inner loop once a match is found
            }
        }
        if (match_found == 0) {
            check_flag = 1; // No match found, set the flag to indicate mismatch
            break; // No need to continue the outer loop if a mismatch is found
        }
    }

    printf("\n\n FLAGGGGGGGGGG: \n %d \n", check_flag);

    if (check_flag == 1) {
        char error_message[100];
        sprintf(error_message, "CHECKED BUTTON VALUE ISN'T IN THE USED RadioButton IDs LIST");
        yyerror(error_message);
        // printf("\n FSHDFSHNEFJEFEN \n");
    }
    else {
        printf("The values are the same!\n\n");
    }
}
