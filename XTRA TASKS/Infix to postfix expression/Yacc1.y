%{
#include<stdio.h>
#include<string.h>
int yylex(void);
void yyerror(char *);
%}

%union{
	char str[100];
}

%token <str> INT
%type  <str> E T


%%
prog: prog E '\n'			{printf("%s\n" , $2);}
	|;
E: E '+' T  {strcat($1 , " ") ; strcat($1 , $3) ; strcat($1 , " +") ; strcpy($$ , $1);}
		|E '-' T   {strcat($1 , " ") ; strcat($1 , $3) ; strcat($1 , " -") ; strcpy($$ , $1);}
		|T         {strcpy($$ , $1)};
T: INT {strcpy($$ , $1)};
%%

void yyerror(char *s){
	fprintf(stderr , "%s\n" , s);
}

int main(void){
	yyparse();
	return 0;
}