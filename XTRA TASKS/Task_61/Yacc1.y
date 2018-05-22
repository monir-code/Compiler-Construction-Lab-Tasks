%{
#include<stdio.h>
int yylex(void);
void yyerror(char *);
%}

%token INT
%%
prog: expr 			{printf("%d\n" , $1);}
expr: expr '+' term   {$$ = $1 + $3;}
					| term {$$ = $1;};
term: INT;
%%

void yyerror(char *s){
	fprintf(stderr , "%s\n" , s);
}

int main(void){
	yyparse();
	return 0;
}