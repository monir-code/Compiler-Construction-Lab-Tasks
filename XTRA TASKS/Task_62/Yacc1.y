%{
#include<stdio.h>
int yylex(void);
void yyerror(char *);
%}

%token INT
%%
prog: prog expr '\n' 			{printf("%d\n" , $2);}
	|;
expr: expr '+' term   {$$ = $1 + $3;}
		|expr '-' term   {$$ = $1 - $3;}
		|term {$$ = $1;};
term: INT;
%%

void yyerror(char *s){
	fprintf(stderr , "%s\n" , s);
}

int main(void){
	yyparse();
	return 0;
}