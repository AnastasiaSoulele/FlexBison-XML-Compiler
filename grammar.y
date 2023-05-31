
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int pos_number=0;
char 


/*Specific Functions*/
void yyerror(const char *message);
%}

%define parse.error verbose

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
%token <strval> T_STRING 
%token <intval> T_POSITIVE_INTEGER  //to allaksa edw
%token <strval> T_LAYOUT_WIDTH
%token <strval> T_LAYOUT_HEIGHT


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
%token <strval> T_EOF          0           "end of file"

/*Non-Terminal*/
%type  program linearlayout linearlayoutattributes linearlayoutattribute relativelayout relativelayoutattributes relativelayoutattribute     
%type  textview textviewattributes textviewattribute imageview imageviewattributes imageviewattribute                                         
%type  button buttonattributes buttonattribute radiogroup radiogroupattributes radiogroupattribute          
%type  android   src id orientation textColor padding checkedButton progress max                         
%type  radiobutton  radiobuttonattributes radiobuttonattribute  progressbar progressbarattributes progressbarnattribute                       
%type  layout_value text content contentempty element empty_content comment                                                                       
                                                                                             
%type <strval> layout_width layout_height  //to allaksa edw

%start program

%%

/*Grammar Rules*/

program :                 linearlayout 
                        | relativelayout
                        ;

linearlayout:            T_START_TAG T_LINEAR_LAYOUT linearlayoutattributes T_END_TAG
                        |T_START_TAG T_LINEAR_LAYOUT linearlayoutattributes T_END_TAG linearlayout
                        ;
                        

linearlayoutattributes:      layout_width layout_height element
                            | layout_width layout_height android_id element
                            | layout_width layout_height android_orientation element
                            | layout_width layout_height android_id android_orientation element
                            ;

layout_width:                T_STRING T_ASSIGN T_STRING //for positive numbers
                                 {if(strcmp($1, "android:layout_width") == 0){
                                    pos_number=atoi($3);
                                    printf("%s = ''%d''\n", $1, pos_number);}
                                  else yyerror("Expected android:layout_width");  //exei thema me to yyerror poy toy vazw string kai exei conflict me
                                 }                                                //ayto poy exei orisei h soylele.Genika alliws 0 errors grammatika
                            |T_STRING T_ASSIGN T_STRING //for strings
                                {if(strcmp($1, "android:layout_width") == 0){
                                    printf("%s = %s\n",$1 ,$3);}
                                 else yyerror("Expected android:layout_width"); 
                                }
                            


layout_height:              T_STRING T_ASSIGN  T_STRING //for positive numbers
                                 {if(strcmp($1, "android:layout_height") == 0){
                                    pos_number=atoi($3);
                                    printf("%s = ''%d''\n", $1, pos_number);}
                                  else yyerror("Expected android:layout_height"); 
                                 }  
                            |T_STRING T_ASSIGN T_STRING //for strings
                                {if(strcmp($1, "android:layout_height") == 0){
                                    printf("%s = %s\n",$1,$3);}
                                 else yyerror("Expected android:layout_height"); 
                                }
                            


android_id:                      T_STRING T_ASSIGN T_STRING 
                                 { 
                                 if(strcmp($1, "android:id")==0)
                                    {
                                        pos_number=atoi($3);
                                        printf("%s = ''%d''\n", $1, pos_number);
                                    }
                                else
                                    yyerror("Expected android:id");
                                }
                                ;

android_orientation:              T_STRING T_ASSIGN  T_STRING 
                                 {if(strcmp($1, "android:orientation") == 0){
                                    printf("%s = %s\n", $1, $3);}
                                 else yyerror("Expected android:orientation"); 
                                 }

text:                            T_STRING T_ASSIGN T_STRING 
                                 {if(strcmp($1, "android:text") == 0){
                                    printf("%s = %s\n", $1, $3);}
                                 else yyerror("Expected android:text"); 
                                }

textColor:                      T_STRING T_ASSIGN T_STRING //xreiazetai  kai to hex
                                 {if(strcmp($1, "android:textColor") == 0){
                                    printf("%s = %s\n", $1, $3);}
                                 else yyerror("Expected android:textColor"); 
                                }

 
checkedButton:                      T_STRING T_ASSIGN T_STRING 
                                 {if(strcmp($1, "android:checkedButton") == 0){
                                    printf("%s = %s\n", $1, $3);}
                                 else yyerror("Expected android:checkedButton"); 
                                }                               

//progress max kai padding einai arithmoi giauto vazw to atoi gia na kanw to string noymero
progress:                  T_STRING T_ASSIGN  T_STRING 
                                 {if(strcmp($1, "android:progress") == 0){
                                    int pos_number = atoi($3);
                                    if (pos_number < 0) {
                                      yyerror("Invalid progress value. It should be a positive integer.");
                                    }
                                    printf("%s = ''%d''\n", $1, pos_number);}
                                 else yyerror("Expected android:progress"); 
                                 }  


padding:                   T_STRING T_ASSIGN  T_STRING 
                                 {if(strcmp($1, "android:padding") == 0){
                                    int pos_number = atoi($3);
                                    if (pos_number < 0) {
                                      yyerror("Invalid padding value. It should be a positive integer.");
                                    }
                                    printf("%s = ''%d''\n", $1, pos_number);}
                                 else yyerror("Expected android:padding"); 
                                 }  


max:                       T_STRING T_ASSIGN  T_STRING 
                                 {if(strcmp($1, "android:max") == 0){
                                    int pos_number = atoi($3);
                                    if (pos_number < 0) {
                                      yyerror("Invalid max value. It should be a positive integer.");
                                    }
                                    printf("%s = ''%d''\n", $1, pos_number);}
                                 else yyerror("Expected android:max"); 
                                 }  




relativelayout:          T_START_TAG T_RELATIVE_LAYOUT  relativelayoutattributes T_END_TAG element
                        |T_START_TAG T_RELATIVE_LAYOUT  relativelayoutattributes T_END_TAG element relativelayout
                        ;


relativelayoutattributes:   layout_width layout_height 
                         |  layout_width layout_height android_id 
                         | %empty   
                         ;

textview:                 T_START_TAG T_TEXT_VIEW textviewattributes T_END_TAG empty_content T_START_TAG T_SLASH T_TEXT_VIEW T_END_TAG
                        ;

textviewattributes:      layout_width layout_height text
                        |layout_width layout_height text android_id
                        |layout_width layout_height text android_id textColor
                        ;

imageview:                T_START_TAG T_IMAGE_VIEW imageviewattributes T_END_TAG empty_content T_START_TAG T_SLASH T_IMAGE_VIEW T_END_TAG
                        ;

imageviewattributes:     layout_width layout_height src
                        |layout_width layout_height src android_id 
                        |layout_width layout_height src android_id padding
                        ;

button:                   T_START_TAG T_BUTTON buttonattributes T_END_TAG empty_content T_START_TAG T_SLASH T_BUTTON T_END_TAG
                        ;

buttonattributes:        layout_width layout_height text
                        |layout_width layout_height text android_id 
                        |layout_width layout_height text android_id padding
                        ;

radiogroup:               T_START_TAG T_RADIO_GROUP radiogroupattributes T_END_TAG radiobutton T_START_TAG T_SLASH T_RADIO_GROUP T_END_TAG
                        ;

radiogroupattributes:    layout_width layout_height text
                        |layout_width layout_height text android_id
                        |layout_width layout_height text android_id checkedButton
                        ;


radiobutton:              T_START_TAG T_RADIO_BUTTON radiobuttonattributes T_END_TAG empty_content T_START_TAG T_SLASH T_RADIO_BUTTON T_END_TAG
                        ;

radiobuttonattributes:    layout_width layout_height text
                        | layout_width layout_height text android_id 
                        ;

radiobuttonattribute:     android T_COLON layout_width T_ASSIGN layout_value layout_height T_ASSIGN layout_value text T_ASSIGN T_STRING
                        | android T_COLON id T_ASSIGN T_STRING

                        ;


progressbar:             T_START_TAG T_PROGRESS_BAR progressbarattributes T_END_TAG empty_content T_START_TAG T_SLASH T_PROGRESS_BAR T_END_TAG
                        ;

progressbarattributes:    layout_width layout_height
                        | layout_width layout_height android_id
                        | layout_width layout_height android_id max
                        | layout_width layout_height android_id max progress
                        ;

                 


comment:                   T_COMMENT_OPEN T_STRING T_COMMENT_CLOSE
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

element:                                 /*ebgala to linear kai to relativelayout*/
                        | textview
                        | radiogroup
                        | radiobutton
                        | relativelayout
                        | imageview
                        |empty_content
                        ;

empty_content:          %empty {}
                        ;



%%

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