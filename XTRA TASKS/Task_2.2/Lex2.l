%option noyywrap

%{
// this is a simple flex program
%}

%%
A  printf("Z");
.|\n  ECHO;


%%
	int main()
	{
		yylex();
		return 0;
	}
