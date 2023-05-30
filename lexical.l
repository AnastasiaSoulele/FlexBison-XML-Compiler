%{
/* libraries */
#include "grammar.tab.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>


extern int flag_err_type;
extern void yyerror(char *message);

/*Define variables and functions*/
int lineno=1; 
int line_init=-1; 

/*Κρατάμε το πόσα errors έχουν προκύψει*/
int error_count =0;
char str_buf[256];
char* str_buf_ptr;



%}


%option noyywrap 
%option case-sensitive 
%option yylineno

/* Initial States */
%x STATE_COMMENT
%x STATE_INLINE_COMMENT
%x STATE_STRING

/*Sublexical analyze*/
%x STRING



/*Keywords*/
LETTER              [a-zA-Z]
LETTERS             [LETTER]+
DIGIT               [0-9]
NZDIGIT             [1-9]{DIGIT}*
ALPHANUM            ({LETTER}|{DIGIT})
ALPHANUM_           ({ALPHANUM}|_)
ASCII               [ !"#$%&'()*+,-./:;<=>?@\[\\\]^_`{|}~]
WHITESPACE          [ \t]

%%

"<"[a-zA-Z_][a-zA-Z0-9_]*">"                  { token_print("START_TAG"); return T_START_TAG;}
"</"[a-zA-Z_][a-zA-Z0-9_]*">"                 { token_print("END_TAG"); return T_END_TAG;}
"<""/>"                                     { token_print("EMPTY_TAG"); return T_EMPTY_TAG;}
"<"[a-zA-Z_][a-zA-Z0-9_]*"/>"                 { token_print("SELF_CLOSING_TAG"); return T_SELF_CLOSING_TAG;}
"[a-zA-Z_][a-zA-Z0-9_]*"=\"[^\"]+\"           { token_print("ATTRIBUTE"); return T_ATTRIBUTE;}
"[a-zA-Z_][a-zA-Z0-9_]*"="\"[^\"]+\""         { token_print("ATTRIBUTE_VALUE"); return T_ATTRIBUTE_VALUE;}
"<\!\[CDATA\["                                { token_print("CDATA_SECTION"); return T_CDATA_SECTION;}
"<\?xml"                                      { token_print("XML_DECLARATION"); return T_XML_DECLARATION;}
"<\?"[a-zA-Z_][a-zA-Z0-9_]*                   { token_print("PROCESING_INSTRUCTION"); return T_PROCESING_INSTRUCTION;}
"NAMESPACE"                                   { token_print("NAMESPACE"); return T_NAMESPACE;}
"<!--"                                        { token_print("COMMENT_OPEN"); return T_COMMENT_OPEN;}
"-->"                                         { token_print("COMMENT_CLOSE"); return T_COMMENT_CLOSE;}
"LinearLayout"                                { token_print("LINEAR_LAYOUT"); return T_LINEAR_LAYOUT;}
"RelativeLayout"                              { token_print("RELATIVE_LAYOUT"); return T_RELATIVE_LAYOUT;}
"TextView"                                    { token_print("TEXT_VIEW"); return T_TEXT_VIEW;}
"ImageView"                                   { token_print("IMAGE_VIEW"); return T_IMAGE_VIEW;}
"Button"                                      { token_print("BUTTON");  return T_BUTTON;}
"RadioButton"                                 { token_print("RADIO_BUTTON"); return T_RADIO_BUTTON;}
"RadioGroup"                                  { token_print("RADIO_GROUP");  return T_RADIO_GROUP;}
"ProgressBar"                                 { token_print("PROGRESS_BAR");  return T_PROGRESS_BAR;}
"[^<>]+"                                      { yylval.strval = strdup(yytext); return T_TEXT_CONTENT;}
\"[a-zA-Z0-9_\-\.]*\"                         { yylval.strval = strdup(yytext); return T_STRING;}
\'[a-zA-Z0-9_\-\.]*\'                         { yylval.strval = strdup(yytext); return T_STRING;}
[1-9][0-9]*                                   { yylval.intval = atoi(yytext); return T_POSITIVE_INTEGER;}
                                            


"."                                           { token_print(T_DOT); return T_DOT;}
","                                           { token_print(T_COMMA); return T_COMMA;}
"="                                           { token_print(T_ASSIGN); return T_ASSIGN;}
":"                                           { token_print(T_COLON); return T_COLON;}
"["                                           { token_print(T_LBRACK); return T_LBRACK;}
"]"                                           { token_print(T_RBRACK); return T_RBRACK;}
"/"                                           { token_print(T_SLASH); return T_SLASH;}
"!"                                           { token_print(T_EXCLAMATION); return T_EXCLAMATION ;}
"-"                                           { token_print(T_DASH); return T_DASH;}
"{"                                           { token_print(T_LBRACES); return T_LBRACES;}
"}"                                           { token_print(T_RBRACES); return T_RBRACES;}
"@"                                           { token_print(T_AT); return T_AT;}
"?"                                           { token_print(T_QUESTION_MARK); return T_QUESTION_MARK ;}
"_"                                           { token_print(T_UNDERSCORE); return T_UNDERSCORE;}
"#"                                           { token_print(T_HASH); return T_HASH;}
"'"                                           { token_print(T_SQUOTES); return T_SQUOTES;}

[ \t]                                         {   } /*Αναγνώριση κενών */


<INITIAL><<EOF>>                              { return T_EOF;}



%% 


void token_print(int token_id){
    if(FLEX_DEBUG && SHOW_TOKENS){
        printf("TOKEN FOUND: %s | TOKEN NUMBER: %d | LINE: %d\n", yytext, token_id, lineno);
    }    
}

    
    
    
