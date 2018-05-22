%option noyywrap
%option yylineno

%{
	#include<stdio.h>
	#include<string.h>
	
	int cntA , cntB , cntC;
	void printArg(char *str);
%}

%%

A			{cntA++;}
B			{cntB++;}
C			{cntC++;}
\n          {
				fprintf(yyout , "%6d ==> A:%d , B:%d , C:%d\n" , yylineno-1 , cntA , cntB , cntC);
				cntA = cntB = cntC = 0;
			}
.           {}

%%

	int main(int argc , char *argv[])
	{
		//printArg(argv[0]);
		yyin = fopen(argv[1] , "r");
		yyout = fopen(argv[2] , "w");
		yylex();
		return 0;
	}
	
	void printArg(char *str)
	{
		printf(" ===> %s\n" , str);
	}