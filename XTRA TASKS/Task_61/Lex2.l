%{
#include<stdlib.h>
void yyerror(char *);
#include "Yacc2.h"
%}
%option noyywrap

%%
[0-9]+ {yylval = atoi(yytext); return INT;}
[+] return *yytext;
[-] return *yytext;
[\n] return 0;
[ \t];
. yyerror("invalid chracter");
%%
