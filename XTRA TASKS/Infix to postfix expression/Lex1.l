%{
#include<stdlib.h>
#include<string.h>
void yyerror(char *);
#include "Yacc1.h"
%}
%option noyywrap

%%
[0-9]+[ ]* { strcpy(yylval.str , yytext) ; return INT;}
[+] return *yytext;
[-] return *yytext;
[*] return *yytext;
[/] return *yytext;
[\n] return *yytext;
[ \t];
. yyerror("invalid chracter");
%%
