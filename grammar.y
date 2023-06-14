%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include <stdbool.h>
#define MAX_RADIO_BUTTONS 50
#define MAX_USED_IDS 100  // Change this to the maximum number of IDs you expect
#define MAX_ID_LENGTH 100 // Change this to the maximum length of ID you expect


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
//char 


/*Specific Functions*/
void yyerror(const char *message);
bool isValidHexColor(const char* color);
bool isValidResource(const char* resource);
bool isValidPadding(const char* padding);
bool isValidID(const char* id);
bool containsDash(const char* str);
int dq_string_to_int(const char* str);
int is_valid_radio_button(const char* id); 
// int isIdUsed(int id);
// void addUsedId(int id); 
int isIdUsed(char* id);
void addUsedId(char* id);
void addUsedIdInt(int id);

%}

%define parse.error verbose

%union{
   int intval;
   float floatval;
   char charval;
   char *strval;
}


/*Keywords*/
%token<strval> T_LINEAR_LAYOUT
%token<strval> T_RELATIVE_LAYOUT
%token<strval> T_TEXT_VIEW
%token<strval> T_IMAGE_VIEW
%token<strval> T_BUTTON
%token<strval> T_RADIO_BUTTON
%token<strval> T_RADIO_GROUP
%token<strval> T_PROGRESS_BAR
%token<strval> T_END_TAG

%token<strval> T_END_LINEAR_LAYOUT
%token<strval> T_END_RELATIVE_LAYOUT
%token<strval> T_END_TEXT_VIEW
%token<strval> T_END_IMAGE_VIEW
%token<strval> T_END_BUTTON
%token<strval> T_END_RADIO_BUTTON
%token<strval> T_END_RADIO_GROUP
%token<strval> T_END_PROGRESS_BAR

%token<strval> T_ANDROID_LAYOUT_WIDTH
%token<strval> T_ANDROID_LAYOUT_HEIGHT
%token<strval> T_ANDROID_ID
%token<strval> T_ANDROID_TEXT
%token<strval> T_ANDROID_ORIENTATION
%token<strval> T_ANDROID_SRC
%token<strval> T_ANDROID_PADDING
%token<strval> T_ANDROID_TEXTCOLOR
%token<strval> T_ANDROID_CHECKEDBUTTON
%token<strval> T_ANDROID_PROGRESS
%token<strval> T_ANDROID_MAX

%token<strval> T_COMMENT_OPEN
%token<strval> T_COMMENT_CLOSE

%token<strval> T_STRING
%token<strval> T_STRING_SINGLE_QUOTE
%token<strval> T_POSITIVE_INTEGER
%token<strval> T_SLASH_END_TAG
%token<strval> T_STRING_DQ_SPACE
//dika moy tokens kikis


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
%type  program relativelayout2 linearlayout linearlayoutattributes  relativelayout relativelayoutattributes      
%type  textview textviewattributes  imageview imageviewattributes                                          
%type  button buttonattributes  radiogroup radiogroupattributes           
%type  src android_id  textColor padding checkedButton progress max android_orientation                        
%type  radiobutton  radiobuttonattributes   progressbar progressbarattributes                        
%type  text content contentempty element                                                                     
                                                                                  
%type <strval> layout_width layout_height  //to allaksa edw

%start program

%%

/*Grammar Rules*/

program :                 T_LINEAR_LAYOUT linearlayout2 
                        | T_RELATIVE_LAYOUT relativelayout2   //gia na min psaxnei duo fores to <Relative paei sto relativelayout2 poy exei kateuthian ta attributes
                        ;
                            
linearlayout:              T_LINEAR_LAYOUT linearlayoutattributes T_END_TAG element T_END_LINEAR_LAYOUT
                        |  T_LINEAR_LAYOUT linearlayoutattributes T_END_TAG element  T_END_LINEAR_LAYOUT linearlayout
                        ;
                              
linearlayout2:              linearlayoutattributes T_END_TAG element  T_END_LINEAR_LAYOUT
                        |   linearlayoutattributes T_END_TAG element  T_END_LINEAR_LAYOUT linearlayout
                        |   linearlayoutattributes T_END_TAG element element T_END_LINEAR_LAYOUT
                        ;                      
                        

linearlayoutattributes:       layout_width layout_height element 
                            | layout_width layout_height android_id element 
                            | layout_width layout_height android_orientation element 
                            | layout_width layout_height android_id android_orientation element comment 
                            ;

layout_width:               T_ANDROID_LAYOUT_WIDTH  T_STRING //for strings "android:layout_width=" 
                           {  
                            if (strcmp($1, "android:layout_width=") == 0 || flag==1) {  //ama to flag exei ginei 1 exei mpei hdh mia fora kai einai swsto to android opote meta tha pairnei to string apla
                                  //printf("EDW TO FLAG :\t%d\t",flag);
                                  flag=1;
                               if (strcmp($2, "\"match_parent\"") == 0 || strcmp($2, "\"wrap_content\"") == 0){   //|| strcmp($2, T_DIMENSION) == 0 || strcmp($2, T_PERCENTAGE) == 0) {
                                  //printf("%s = %s\n", $1, $2);
                                  valueflag=1;
                                } 
                                 
                                }
                            else 
                              yyerror("Expected android:layout_width=");

                            if(valueflag==0) //an ta string != value poy prepei na exoyn
                                  {
                                    printf("Invalid value for android:layout_width: %s\n", $2);
                                  } 
                           }

                           | T_ANDROID_LAYOUT_WIDTH T_QUESTION_MARK
                           {
                            printf("\nWrong!\n");
                           }

                           |T_ANDROID_LAYOUT_WIDTH T_POSITIVE_INTEGER{
                            
                            flag=0;
                            if(strcmp($1, "android:layout_width=") == 0 || flag == 1){
                               flag=1;
                               pos_number=atoi($2);
                               //printf("%s = %d\n", $1, pos_number);
                               }
                            else yyerror("Expected android:layout_width=");
                           }
                           ;

                            

layout_height:               T_ANDROID_LAYOUT_HEIGHT  T_STRING //  "android:layout_height=" 
                            {   flag=0;
                            if (strcmp($1, "android:layout_height=") == 0 || flag == 1) {\
                                flag=1;
                               if (strcmp($2, "\"match_parent\"") == 0 || strcmp($2, "\"wrap_content\"") == 0){ // || strcmp($2, T_DIMENSION) == 0 || strcmp($2, T_PERCENTAGE) == 0) {
                                  //printf("%s = %s\n", $1, $2);
                                } else 
                                   printf("Invalid value for android:layout_height: %s\n", $2);
                                }
                            else 
                              yyerror("Expected android:layout_height=");
                            }
                           |T_ANDROID_LAYOUT_HEIGHT T_POSITIVE_INTEGER{
                            flag=0;
                            if(strcmp($1, "android:layout_height=") == 0 || flag==1){
                                flag=1;
                               pos_number=atoi($2);
                               //printf("%s = %d\n", $1, pos_number);
                               }
                            else yyerror("Expected android:layout_height=");
                            }
                            ;
                            


/* android_id:                      T_ANDROID_ID T_POSITIVE_INTEGER
                                {
                                flag = 0;
                                if (strcmp($1, "android:id=") == 0 || flag == 1) {
                                    flag = 1;
                                    pos_number = dq_string_to_int($2);
                                    printf("%s = %d\n", $1, pos_number);

                                    if (isIdUsed(pos_number)) {
                                        yyerror("The android:id value is not unique.");
                                    } else {
                                        addUsedId(pos_number);
                                    }
                                } else {
                                    yyerror("Expected android:id=");
                                }
                            }
                            | T_ANDROID_ID T_STRING
                            {
                                flag = 0;
                                if (strcmp($1, "android:id=") == 0 || flag == 1) {
                                    flag = 1;
                                    printf("%s = %s\n", $1, $2);
                                    textid=$2;
                                    if(isIdUsed(textid)){
                                        yyerror("The android:id value is not unique.");
                                    }else{
                                        addUsedId(textid);
                                    }
                                } else {
                                    yyerror("Expected android:id=");
                                }
                            }
                            ; */


android_id:                     T_ANDROID_ID T_POSITIVE_INTEGER
                                    {
                                    flag = 0;
                                    if (strcmp($1, "android:id=") == 0 || flag == 1) {
                                        flag = 1;
                                        pos_number = dq_string_to_int($2);
                                        printf("%s = %d\n", $1, pos_number);
                                        char pos_number_str[20];  // Buffer to hold the string representation of pos_number
                                        snprintf(pos_number_str, sizeof(pos_number_str), "%d", pos_number);

                                        if (isIdUsed(pos_number_str)) {
                                            yyerror("The android:id value is not unique.");
                                        } else {
                                            addUsedId(pos_number_str);
                                        }
                                    } else {
                                        yyerror("Expected android:id=");
                                    }
                                }
                            | T_ANDROID_ID T_STRING
                            {
                                flag = 0;
                                if (strcmp($1, "android:id=") == 0 || flag == 1) {
                                    flag = 1;
                                    printf("%s = %s\n", $1, $2);
                                
                                    if(isIdUsed($2)){
                                        yyerror("The android:id value is not unique.");
                                    }else{
                                        addUsedId($2);
                                    }
                                } else {
                                    yyerror("Expected android:id=");
                                }
                            }
                            ;




                                


android_orientation:              T_ANDROID_ORIENTATION  T_STRING 
                                 {  flag=0;
                                 if(strcmp($1, "android:orientation=") == 0 || flag==1){
                                        flag=1;
                                    if(strcmp($2, "\"horizontal\"") == 0 || strcmp($2, "\"vertical\"") == 0)
                                    printf("%s = %s\n", $1, $2);
                                    }
                                 else yyerror("Expected android:orientation="); 
                                 }
                                 ;

text:                            T_ANDROID_TEXT T_STRING 
                                 {  
                                    flag=0;
                                    if(strcmp($1, "android:text=") == 0 || flag==1){
                                        flag=1;
                                    printf("%s = %s\n", $1, $2);}
                                 else yyerror("Expected android:text="); 
                                }

                               |T_ANDROID_TEXT T_STRING_DQ_SPACE  //periptwsi na einai 2 lekseis me keno metaksu toys kai "" sta akra
                                {flag=0;
                                    if(strcmp($1, "android:text=") == 0 || flag==1){
                                        flag=1;
                                    printf("%s = %s\n", $1, $2);}
                                 else yyerror("Expected android:text="); 
                                }
                                ;

textColor:                        T_ANDROID_TEXTCOLOR T_STRING 
                                  { flag=0;
                                    if(strcmp($1, "android:textColor=") == 0 || flag==1){
                                        flag=1;
                                    printf("%s = %s\n", $1, $2);}
                                    else yyerror("Expected android:textColor=");    
                                  } 
                                  
                                  ;

 
/* checkedButton:                 T_ANDROID_CHECKEDBUTTON T_STRING
                                { flag=0;
                                  if (strcmp($1, "android:checkedButton=") == 0 || flag == 1) {
                                    flag=1;
                                    printf("%s = %s\n", $1, $2);
                                        } else 
                                         {
                                        yyerror("Expected android:checkedButton=");
                                         }
                                }
                                ;        */

                                
checkedButton:                  T_ANDROID_CHECKEDBUTTON T_STRING
                                {
                                    if (strcmp($1, "android:checkedButton=") == 0 || flag == 1) {
                                        flag = 1;
                                        if (is_valid_radio_button($2)) {
                                            printf("%s = %s\n", $1, $2);
                                        } else {
                                            yyerror("Invalid android:checkedButton value");
                                        }
                                    } else {
                                        yyerror("Expected android:checkedButton=");
                                    }
                                }
                                ;
                    

//progress max kai padding einai arithmoi giauto vazw to atoi gia na kanw to string noymero
progress:                            T_ANDROID_PROGRESS T_POSITIVE_INTEGER
                                        {
                                            if (strcmp($1, "android:progress=") == 0 || flag == 1) {
                                                flag = 1;
                                                int progress = dq_string_to_int($2);
                                                if (progress >= 0 && progress <= max_value) {
                                                    printf("%s = %d\n", $1, progress);
                                                } else {
                                                    yyerror("Invalid android:progress value");
                                                }
                                            } else {
                                                yyerror("Expected android:progress=");
                                            }
                                        }
                                        ;


padding:                   T_ANDROID_PADDING T_POSITIVE_INTEGER
                            { flag=0;
                            if(strcmp($1, "android:padding=") == 0 || flag ==1) {
                                flag=1;
                                pos_number = atoi($2);
                                    if (pos_number < 0) {
                                      yyerror("Invalid progress value. It should be a positive integer.");
                                    }
                                    printf("%s = ''%d''\n", $1, pos_number);}
                             else {
                                yyerror("Expected android:padding=");
                                  }
                            };


max:                        T_ANDROID_MAX T_POSITIVE_INTEGER
                            {
                                if (strcmp($1, "android:max=") == 0) {
                                    max_value = dq_string_to_int($2);
                                    printf("%s = %d\n", $1, max_value);
                                } else {
                                    yyerror("Expected android:max=");
                                }
                            }
                            ;

src:                            T_ANDROID_SRC T_STRING
                                {   flag=0;
                                    if(strcmp($1, "android:src=") == 0|| flag==1){
                                        flag=1;
                                    printf("%s = %s\n", $1, $2);}
                                 else yyerror("Expected android:src="); 
                                }
                                ;


relativelayout:          T_RELATIVE_LAYOUT  relativelayoutattributes T_END_TAG element T_END_RELATIVE_LAYOUT
                        |T_RELATIVE_LAYOUT  relativelayoutattributes T_END_TAG element element T_END_RELATIVE_LAYOUT
                        |T_RELATIVE_LAYOUT  relativelayoutattributes T_END_RELATIVE_LAYOUT element relativelayout
                        |T_RELATIVE_LAYOUT  relativelayoutattributes relativelayoutattributes T_END_TAG element T_END_RELATIVE_LAYOUT
                        |T_RELATIVE_LAYOUT  relativelayoutattributes element T_END_RELATIVE_LAYOUT progressbar progressbarattributes T_END_LINEAR_LAYOUT
                        |T_RELATIVE_LAYOUT  relativelayoutattributes T_END_TAG element element T_END_RELATIVE_LAYOUT T_END_LINEAR_LAYOUT
                        ;

relativelayout2:           relativelayoutattributes T_END_RELATIVE_LAYOUT element
                        |  relativelayoutattributes T_END_RELATIVE_LAYOUT element relativelayout   //exei idi diavastei to ena <RelativeLayout den theloyme 2o
                        |  relativelayoutattributes T_END_RELATIVE_LAYOUT element 
                        ;


relativelayoutattributes:   layout_width layout_height 
                         |  layout_width layout_height android_id 
                         |  layout_width layout_height element
                         | %empty   
                         ;

textview:                 T_TEXT_VIEW  textviewattributes T_SLASH_END_TAG   
                        ;

textviewattributes:      layout_width layout_height text
                        |layout_width layout_height android_id text
                        |layout_width layout_height android_id text textColor
                        ;

imageview:                T_IMAGE_VIEW  imageviewattributes T_SLASH_END_TAG 
                        ;

imageviewattributes:     layout_width layout_height src
                        |layout_width layout_height src android_id 
                        |layout_width layout_height src android_id padding
                        |layout_width layout_height src padding 
                        ;

button:                   T_BUTTON  buttonattributes T_END_BUTTON 
                        ;

buttonattributes:        layout_width layout_height text
                        |layout_width layout_height text android_id 
                        |layout_width layout_height text android_id padding
                        ;

radiogroup:               T_RADIO_GROUP   radiogroupattributes T_END_TAG radiobutton T_END_RADIO_GROUP   //<RadioGroup radiogroupattributes> radiobutton </Radiogroup>
                        ;

radiogroupattributes:     layout_width layout_height
                        | layout_width layout_height text
                        | layout_width layout_height text android_id
                        | layout_width layout_height text android_id checkedButton
                        | layout_width layout_height text radiobutton
                        | layout_width layout_height text android_id radiobutton
                        | layout_width layout_height text android_id checkedButton radiobutton
                        ;


radiobutton:               T_RADIO_BUTTON  radiobuttonattributes T_SLASH_END_TAG 
                          |T_RADIO_BUTTON  radiobuttonattributes T_SLASH_END_TAG radiobutton 
                        ;

radiobuttonattributes:    layout_width layout_height text
                        | layout_width layout_height android_id text  
                        | layout_width layout_height android_id text checkedButton
                        ;


progressbar:              T_PROGRESS_BAR  progressbarattributes T_SLASH_END_TAG
                        ;

progressbarattributes:    layout_width layout_height
                        | layout_width layout_height android_id
                        | layout_width layout_height android_id max
                        | layout_width layout_height android_id max progress
                        ;
                 

comment:                 T_COMMENT_OPEN T_STRING T_COMMENT_CLOSE{
                             if (strcmp($1, "<!--")==0 && strcmp($3, "-->")==0 && !containsDash($2)) {
                                    printf("%s %s %s\n", $1, $2, $3);
                            } else 
                                    yyerror("Invalid comment");
                            }
                            ;


content:                  element
                        | element content
                        //| T_TEXT_CONTENT
                        ;

contentempty:            element
                        | element content
                        //| T_TEXT_CONTENT
                        | %empty
                        ;

element:                  textview element
                        | radiogroup element
                        | radiobutton element
                        | relativelayout element
                        | imageview element  
                        | imageview 
                        | progressbar 
                        | checkedButton                  
                        |%empty
                        ;                /*ebgala to linear*/
                       



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

/* int isIdUsed(int id) {
    for (int i = 0; i < used_id_count; i++) {
        if (used_ids[i] == id) {
            return 1;  // ID is already used
        }
    }
    return 0;  // ID is not used
}

void addUsedId(int id) {
    used_ids[used_id_count++] = id;
} */

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