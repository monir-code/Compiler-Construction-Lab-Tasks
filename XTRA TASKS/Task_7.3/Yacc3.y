%{
#include<stdio.h>
int yylex(void);
void yyerror(char *);
%}

%union{
	float f;
	int i;
}

%token <f> FLT
%token <i> INT
%type  <f> E T F

%%
prog: prog E '\n' 			{printf("%f\n" , $2);}
	|;
E: E '+' T   {$$ = $1 + $3;}
		|E '-' T   {$$ = $1 - $3;}
		|T         {$$ = $1;}
T: T '*' F   {$$ = $1 * $3;}
		|T '/' F   {$$ = $1 / $3;}
		|F         {$$ = $1;}
F: FLT {$$ = $1;}
	|INT {$$ = $1;};
%%

void yyerror(char *s){
	fprintf(stderr , "%s\n" , s);
}

int main(void){
	yyparse();
	return 0;
}