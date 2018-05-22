%option noyywrap

%{
// this is a simple flex program
%}

%%
[.]*[A-Zc-z0-9][.]*   printf("Not Recognized\n");
[ab]*abbb[ab]*    	printf("Recognized\n");
.* ;             		printf("Not Recognized\n");


%%
	int main()
	{
		yylex();
		return 0;
	}
