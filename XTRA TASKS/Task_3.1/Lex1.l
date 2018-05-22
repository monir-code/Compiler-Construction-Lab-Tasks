%option noyywrap
%option yylineno

%{
// this is a simple flex program
%}

%%
[a-zA-z_]+[a-zA-z0-9_]*\n     yytext[yyleng-1] = '\0' ; fprintf(yyout , "ID:%s[%d]\n" , yytext , yyleng); yytext[0] = '\0';
[0-9]* 				fprintf(yyout , "NOT_RECOGNIZED\n");
.*\n                fprintf(yyout , "NOT_RECOGNIZED\n");

%%
	int main(int argc, char *argv[])
	{
		yyin = fopen(argv[1], "r");
		yyout = fopen(argv[2], "w");
		yylex();
		//fprintf(yyout , " %6d\n" , yylineno);
		fclose(yyin);
		fclose(yyout);
		return 0;
	}	