%option noyywrap
%option yylineno

%{
// this is a simple flex program
%}

%%
\/\/(.)*                   {fprintf(yyout , "SCM:[%d]" , yyleng);}
(\/\*)(.)*(\*\/)					{fprintf(yyout , "MCM:[%d]" , yytext , yyleng);}
(\.)*                        ECHO;

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