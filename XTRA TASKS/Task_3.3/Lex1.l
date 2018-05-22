%option noyywrap
%option yylineno

%{
// this is a simple flex program
%}

%%


%%
	int main(int argc, char *argv[])
	{
		yyin = fopen(argv[1], "r");
		yyout = fopen(argv[2], "w");
		yylex();
		fclose(yyin);
		fclose(yyout);
	}	