%{
#include<stdio.h>
int yylex(void);
void yyerror(char *);
%}

%token INT
%%
prog: prog E '\n' 			{printf("END\n");}
	|;
E: E '+' T   {printf("E -> E + T\n");}
		|E '-' T   {printf("E -> E - T\n");}
		|T         {printf("E -> T\n");}
T: T '*' F   {printf("T -> T * F\n");}
		|T '/' F   {printf("T -> T / F\n");}
		|F         {printf("T -> F\n");}
F: INT {printf("F->INT\n");};
%%

void yyerror(char *s){
	//fprintf(stderr , "%s\n" , s);
}

int main(void){
	yyparse();
	return 0;
}