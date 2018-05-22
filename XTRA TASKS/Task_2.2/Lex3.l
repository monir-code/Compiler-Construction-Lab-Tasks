%option noyywrap

%{
// this is a simple flex program
%}

%%
CSE  printf("Computer Science & Engineering");
.|\n  ECHO;


%%
	int main()
	{
		yylex();
		return 0;
	}
