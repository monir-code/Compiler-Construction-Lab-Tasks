%{
#include<stdlib.h>
void yyerror(char *);
#include "Yacc1.h"
%}
%option noyywrap

%%
[0-9]*\.[0-9]*[ ] {yylval.f = atof(yytext); return FLT;}
[0-9]+[ ] {yylval.i = atoi(yytext); return INT;}
[+] return *yytext;
[-] return *yytext;
[*] return *yytext;
[/] return *yytext;
[\n] return *yytext;
[ \t];
. yyerror("invalid chracter");
%%
