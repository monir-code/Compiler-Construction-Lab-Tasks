%option noyywrap
%option yylineno

%{
// this is a simple flex program
%}

%%
[ \t\n]                     ECHO;
[a-zA-z_][a-zA-z0-9_]*    	{fprintf(yyout , "ID:%s[%d]" , yytext , yyleng);}
[^ \t\n]+                   fprintf(yyout , "NOT_RECOGNIZED");

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