%{
#include<stdlib.h>
void yyerror(char *);
#include "Yacc1.h"
%}
%option noyywrap

%%
[0-9]+ {yylval = atoi(yytext); return INT;}
[+] return *yytext;
[\n] return 0;
[ \t];
. yyerror("invalid chracter");
%%
