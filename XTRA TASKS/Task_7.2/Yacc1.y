%{
#include<stdio.h>
int yylex(void);
void yyerror(char *);
%}

%token INT

%left '+' '-'
%left '*' '/'

%%
prog: prog expr '\n' 			{printf("%d\n" , $2);}
	|;
expr: expr '+' expr   {$$ = $1 + $3;}
		|expr '-' expr   {$$ = $1 - $3;}
		|expr '*' expr   {$$ = $1 * $3;}
		|expr '/' expr   {$$ = $1 / $3;}
		|INT ;
%%

void yyerror(char *s){
	fprintf(stderr , "%s\n" , s);
}

int main(void){
	yyparse();
	return 0;
}