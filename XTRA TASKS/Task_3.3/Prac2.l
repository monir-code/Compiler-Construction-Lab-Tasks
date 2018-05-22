%option noyywrap
%option yylineno

%{
	#include<stdio.h>
	#include<string.h>
%}

%%

((if)|(else)|(while)|(for)|(switch)|(case))[ \t\n]      				{printf("KEY: %s" , yytext);}
[a-zA-Z_]+[a-zA-Z_0-9]*[ \t\n]   	{printf("ID: %s" , yytext);}
[0-9]+[ \t\n]						{printf("INT: %s" , yytext);}
[+-/*][ \t\n]						{printf("OP: %s" , yytext);}
[0-9]+((\.)[0-9]+)?[ \t\n]			{printf("FLT: %s" , yytext);}
[^ \t\n]*                          		{printf("NOT_RECOGNIZED %s " , yytext);}


%%

	int main(int argc , char *argv[])
	{
		yyin = fopen(argv[1] , "r");
		yyout = fopen(argv[2] , "w");
		yylex();
		return 0;
	}