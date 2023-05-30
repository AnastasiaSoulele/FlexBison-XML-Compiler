
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtbl.h"
#include "token.h"



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

HASHTBL *hashtbl;

/*Specific Functions*/
void yyerror(const char *message);
%}

%error-verbose

%union{
   int intval;
   float floatval;
   char charval;
   char *strval;
}


/*Keywords*/
%token <strval> T_START_TAG               
%token <strval> T_END_TAG                 
%token <strval> T_EMPTY_TAG               
%token <strval> T_SELF_CLOSING_TAG        
%token <strval> T_ATTRIBUTE               
%token <strval> T_ATTRIBUTE_VALUE 
%token <strval> T_CDATA_SECTION    
%token <strval> T_XML_DECLARATION  
%token <strval> T_TEXT_CONTENT            
%token <strval> T_NAMESPACE               
%token <strval> T_PROCESING_INSTRUCTION   
%token <strval> T_COMMENT_OPEN            
%token <strval> T_COMMENT_CLOSE          
%token T_LINEAR_LAYOUT T_RELATIVE_LAYOUT T_TEXT_VIEW T_IMAGE_VIEW T_BUTTON T_RADIO_BUTTON T_RADIO_GROUP T_PROGRESS_BAR
%token T_STRING 
%token T_POSITIVE_INTEGER


/*Other tokens*/
%left  <strval> T_DOT                      "."
%left  <strval> T_COMMA                    ","
%right <strval> T_ASSIGN                   "="
%token <strval> T_COLON                    ":"
%left  <strval> T_LBRACK                   "["
%left  <strval> T_RBRACK                   "]"
%token <strval> T_SLASH                    "/"
%token <strval> T_EXCLAMATION              "!"
%token <strval> T_DASH                     "-"
%token <strval> T_LBRACES                  "{"
%token <strval> T_RBRACES                  "}"
%left  <strval> T_AT                       "@"
%token <strval> T_QUESTION_MARK            "?"
%token <strval> T_UNDERSCORE               "_"
%token <strval> T_HASH                     "#"
%token <strval> T_SQUOTES                  "'"

/*EOF*/
%token <strval> T_EOF            0         "end of file"

/*Non-Terminal*/
%type  program linearlayout linearlayoutattributes linearlayoutattribute relativelayout relativelayoutattributes relativelayoutattribute     
%type  textview textviewattributes textviewattribute imageview imageviewattributes imageviewattribute                                         
%type  button buttonattributes buttonattribute radiogroup radiogroupattributes radiogroupattribute          
%type  android layout_width layout_height src                                   
%type  radiobutton  radiobuttonattributes radiobuttonattribute  progressbar progressbarattributes progressbarnattribute                       
%type  layout_value text content contentempty element empty_content                                                                          
                                                                                             


%start program

%%

/*Grammar Rules*/

program :                 linearlayout 
                        | relativelayout
                        ;

linearlayout:             T_START_TAG T_LINEAR_LAYOUT linearlayoutattributes T_END_TAG content T_START_TAG T_SLASH T_LINEAR_LAYOUT T_END_TAG
                        ;

linearlayoutattributes:   linearlayoutattribute
                        | linearlayoutattribute linearlayoutattributes
                        ;

linearlayoutattribute:     android T_COLON layout_width T_ASSIGN layout_value
                        |  android T_COLON layout_height T_ASSIGN layout_value
                        |  android T_COLON T_ATTRIBUTE T_ASSIGN T_ATTRIBUTE_VALUE
                        ;


relativelayout:             T_START_TAG T_RELATIVE_LAYOUT relativelayoutattributes T_END_TAG contentempty T_START_TAG T_SLASH T_LINEAR_LAYOUT T_END_TAG
                        ;

relativelayoutattributes:   relativelayoutattribute
                         |  relativelayoutattribute relativelayoutattributes
                         ;

relativelayoutattribute:     android T_COLON layout_width T_ASSIGN layout_value
                         |   android T_COLON layout_height T_ASSIGN layout_value
                         |   android T_COLON T_ATTRIBUTE T_ASSIGN T_ATTRIBUTE_VALUE
                         ;



textview:                 T_START_TAG T_TEXT_VIEW textviewattributes T_END_TAG empty_content T_START_TAG T_SLASH T_TEXT_VIEW T_END_TAG
                        ;

textviewattributes:       textviewattribute
                        | textviewattribute textviewattributes
                        ;
 
textviewattribute:        android T_COLON layout_width T_ASSIGN layout_value
                        | android T_COLON layout_height T_ASSIGN layout_value
                        | android T_COLON text T_ASSIGN T_STRING
                        | android T_COLON T_ATTRIBUTE T_ASSIGN T_ATTRIBUTE_VALUE
                        ;


imageview:                T_START_TAG T_IMAGE_VIEW imageviewattributes T_END_TAG empty_content T_START_TAG T_SLASH T_IMAGE_VIEW T_END_TAG
                        ;

imageviewattributes:      imageviewattribute
                        | imageviewattribute imageviewattributes
                        ;

imageviewattribute:       android T_COLON layout_width T_ASSIGN layout_value
                        | android T_COLON layout_height T_ASSIGN layout_value 
                        | android T_COLON src T_ASSIGN T_STRING
                        | android T_COLON T_ATTRIBUTE T_ASSIGN T_ATTRIBUTE_VALUE



button:                   T_START_TAG T_BUTTON buttonattributes T_END_TAG empty_content T_START_TAG T_SLASH T_BUTTON T_END_TAG
                        ;

buttonattributes:         buttonattribute
                        | buttonattribute buttonattributes
                        ;


buttonattribute:          android T_COLON layout_width T_ASSIGN layout_value
                        | android T_COLON layout_height T_ASSIGN layout_value
                        | android T_COLON text T_ASSIGN T_STRING
                        | android T_COLON T_ATTRIBUTE T_ASSIGN T_ATTRIBUTE_VALUE
                        ;


radiogroup:               T_START_TAG T_RADIO_GROUP radiogroupattributes T_END_TAG radiobutton T_START_TAG T_SLASH T_RADIO_GROUP T_END_TAG
                        ;

radiogroupattributes:     radiogroupattribute
                        | radiogroupattribute radiogroupattributes
                        ;

radiogroupattribute:      android T_COLON layout_width T_ASSIGN layout_value
                        | android T_COLON layout_height T_ASSIGN layout_value
                        | android T_COLON text T_ASSIGN T_STRING
                        | android T_COLON T_ATTRIBUTE T_ASSIGN T_ATTRIBUTE_VALUE
                        ;


radiobutton:              T_START_TAG T_RADIO_BUTTON radiobuttonattributes T_END_TAG empty_content T_START_TAG T_SLASH T_RADIO_BUTTON T_END_TAG
                        ;

radiobuttonattributes:    radiobuttonattribute
                        | radiobuttonattribute radiobuttonattributes
                        ;

radiobuttonattribute:     android T_COLON layout_width T_ASSIGN layout_value
                        | android T_COLON layout_height T_ASSIGN layout_value
                        | android T_COLON text T_ASSIGN T_STRING
                        | android T_COLON T_ATTRIBUTE T_ASSIGN T_ATTRIBUTE_VALUE
                        ;


progressbar:             T_START_TAG T_PROGRESS_BAR radiobuttonattributes T_END_TAG empty_content T_START_TAG T_SLASH T_PROGRESS_BAR T_END_TAG
                        ;

progressbarattributes:    radiobuttonattribute
                        | radiobuttonattribute radiobuttonattributes
                        ;

progressbarnattribute:    android T_COLON layout_width T_ASSIGN layout_value
                        | android T_COLON layout_height T_ASSIGN layout_value
                        | android T_COLON T_ATTRIBUTE T_ASSIGN T_ATTRIBUTE_VALUE
                        ;


android:                 T_STRING
                        ;


layout_height:             T_STRING
                        |  T_POSITIVE_INTEGER
                        ;

layout_width:             T_STRING
                        | T_POSITIVE_INTEGER
                        ;

src:                      T_STRING
                        ;


layout_value:              T_STRING
                        |  T_POSITIVE_INTEGER
                        ;

text:                      T_TEXT_CONTENT
                        ;


content:                  element
                        | element content
                        | T_TEXT_CONTENT
                        ;

contentempty:            element
                        | element content
                        | T_TEXT_CONTENT
                        | empty_content
                        ;

element:                  linearlayout
                        | relativelayout
                        | textview
                        | radiogroup
                        | radiobutton
                        | relativelayout
                        | imageview
                        ;

empty_content:          %empty {}
                        ;



%%

int main(int argc, char *argv[]){
    int token;

    /*Διάβασμα του αρχείου*/

   if(!(hashtbl = hashtbl_create(10, NULL))) {
        fprintf(stderr, "ERROR: hashtbl_create() failed!\n");
        exit(EXIT_FAILURE);
    }


    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if (yyin == NULL){
            perror ("Error opening file"); 
            return -1;
        }
    }

    /*Κάνε συνατικτική ανάλυση*/
    yyparse();

    hashtbl_get(hashtbl, scope); // Retrieve the last table (Scope 0);
    hashtbl_destroy(hashtbl);
    fclose(yyin);
    

   if(error_count > 0){
        printf("Syntax Analysis failed due to %d errors\n", error_count);
      }
        
   else{
        printf("Syntax Analysis completed successfully.\n");
      }

    return 0;
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