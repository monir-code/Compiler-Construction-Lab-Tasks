%option noyywrap
%option yylineno

%{
// this is a simple flex program
%}

%%
[ \t\n]                     ECHO;
[a-zA-z_][a-zA-z0-9_]*    	fprintf(yyout , "NOT_RECOGNIZED ");
[-+]?([0-9]*)\.([0-9]+)([eE]([-+]?[0-9]+))?    		{fprintf(yyout , "FLT:%s[%d] " , yytext , yyleng);}
[-+]?([0-9]+)\.(([0-9]+)([eE]([-+]?[0-9]+))?)?    	{fprintf(yyout , "FLT:%s[%d] " , yytext , yyleng);}
[^ \t\n]+                   fprintf(yyout , "NOT_RECOGNIZED ");

%%
	int main(int argc, char *argv[])
	{
		yyin = fopen(argv[1], "r");
		yyout = fopen(argv[2], "w");
		yylex();
		
		//[-+]?([0-9]*)\.([0-9]+)    	{fprintf(yyout , "FLT:%s[%d] " , yytext , yyleng);}
		//[-+]?([0-9]+)\.(([0-9]+)([eE]([-+]?[0-9]+))?)?    	{fprintf(yyout , "FLT:%s[%d] " , yytext , yyleng);}
		fclose(yyin);
		fclose(yyout);
		return 0;
	}	
	