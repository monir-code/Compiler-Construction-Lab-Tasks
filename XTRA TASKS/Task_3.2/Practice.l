%option noyywrap
%option yylineno

%{
	#include<stdio.h>
	#include<string.h>
// this is a simple flex program
	void printHello();
	int cnt = 0 ;
%}

%%
[^\n]*(\n)  {
				int i , cnt = 0;
				for(i = 0 ; i<strlen(yytext) ; i++){
					if(yytext[i] == 'a') cnt++;
				}
				yytext[strlen(yytext) - 1] = '\0';
				printf("%4d => %s --> %d\n" , yylineno-1 , yytext , cnt);
			}
.        {printf("MISSED\n");}

%%

	int main()
	{
		//printHello();
		yylex();
		return 0;
	}
	
	void printHello()
	{
		printf("Hello\n");
	}