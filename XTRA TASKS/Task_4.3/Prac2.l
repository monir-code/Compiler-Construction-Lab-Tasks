%option noyywrap
%option yylineno

%{
	#include<stdio.h>
	#include<string.h>
%}

%%
	
"//"[^\n]*(\n)          {	
							yytext[strlen(yytext) - 1] = '\0';
							fprintf(yyout , "SCM: %s[%d]\n" , yytext , yyleng);
						}

"/*"([^*]|((\*)+[^/]))*"*/"   	{
									fprintf(yyout , "MCM: %s[%d] MCM-END\n" , yytext , yyleng);
								}
	
%%

	int main(int argc , char *argv[])
	{
		yyin = fopen(argv[1] , "r");
		yyout = fopen(argv[2] , "w");
		yylex();
		return 0;
	}