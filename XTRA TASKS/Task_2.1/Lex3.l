%option noyywrap

%{
// this is a simple flex program
%}

%%



%%
	int main()
	{
		yylex();
		return 0;
	}
