%option noyywrap

%{
// this is a simple flex program
%}

%%
A ;
.  ECHO;


%%
	int main()
	{
		yylex();
		return 0;
	}
