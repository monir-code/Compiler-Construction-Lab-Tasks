%option noyywrap
%option yylineno

%{
// this is a simple flex program
%}

%%
[ \t\n]                     ECHO;
if                          						{fprintf(yyout , "KEY:%s[%d]" , yytext , yyleng);}
else                            					{fprintf(yyout , "KEY:%s[%d]" , yytext , yyleng);}
switch                          					{fprintf(yyout , "KEY:%s[%d]" , yytext , yyleng);}
case                            					{fprintf(yyout , "KEY:%s[%d]" , yytext , yyleng);}
while                           					{fprintf(yyout , "KEY:%s[%d]" , yytext , yyleng);}
for                             					{fprintf(yyout , "KEY:%s[%d]" , yytext , yyleng);}

[a-zA-z_][a-zA-z0-9_]*    							{fprintf(yyout , "ID:%s[%d]" , yytext , yyleng);}
[-+]?[0-9]+    	            						{fprintf(yyout , "INT:%s[%d]" , yytext , yyleng);}
[-+]?([0-9]*)\.([0-9]+)([eE]([-+]?[0-9]+))?    		{fprintf(yyout , "FLT:%s[%d] " , yytext , yyleng);}
[-+]?([0-9]+)\.(([0-9]+)([eE]([-+]?[0-9]+))?)?    	{fprintf(yyout , "FLT:%s[%d] " , yytext , yyleng);}
[\+\-\*\/]                      					{fprintf(yyout , "OP:%s[%d]" , yytext , yyleng);}
[^ \t\n]+                   						fprintf(yyout , "NOT_RECOGNIZED");

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