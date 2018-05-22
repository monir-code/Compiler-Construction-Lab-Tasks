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
%type  <f> E F

%left '+' '-'
%left '*' '/'

%%
prog: prog E '\n' 			{printf("%f\n" , $2);}
	|;
E: E E '+'  {$$ = $1 + $2;}
		|E E '-'  {$$ = $1 - $2;}
		|E E '*'   {$$ = $1 * $2;}
		|E E '/'   {$$ = $1 / $2;}
		|F ;
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