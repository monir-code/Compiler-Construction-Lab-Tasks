%{
#include<stdio.h>
int yylex(void);
void yyerror(char *);
#define YYSTYPE float
%}

%token FLT
%%
prog: prog E '\n' 			{printf("%f\n" , $2);}
	|;
E: E '+' T   {$$ = $1 + $3;}
		|E '-' T   {$$ = $1 - $3;}
		|T         {$$ = $1;}
T: T '*' F   {$$ = $1 * $3;}
		|T '/' F   {$$ = $1 / $3;}
		|F         {$$ = $1;}
F: FLT {$$ = $1;};
%%

void yyerror(char *s){
	fprintf(stderr , "%s\n" , s);
}

int main(void){
	yyparse();
	return 0;
}