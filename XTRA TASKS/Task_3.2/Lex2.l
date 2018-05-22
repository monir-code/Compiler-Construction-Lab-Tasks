%option main
%option yylineno
%%
[a-zA-Z0-9]+ printf("AlNum[%d]",yyleng);
\n   printf("%6d\n",yylineno-1);
%%