%option main
%option yylineno

%{
	int cnt = 0;
%}

%%
[a]  cnt++; printf("a");
\n   printf("%6d[A = %d]\n",yylineno-1 , cnt); cnt = 0;
%%