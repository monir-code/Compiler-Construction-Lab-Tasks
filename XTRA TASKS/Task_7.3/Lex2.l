%{
#include<stdlib.h>
void yyerror(char *);
#include "Yacc2.h"
%}
%option noyywrap

%%
[0-9]*\.[0-9]* {yylval.f = atof(yytext); return FLT;}
[+] return *yytext;
[-] return *yytext;
[*] return *yytext;
[/] return *yytext;
[\n] return *yytext;
[ \t];
. yyerror("invalid chracter");
%%
