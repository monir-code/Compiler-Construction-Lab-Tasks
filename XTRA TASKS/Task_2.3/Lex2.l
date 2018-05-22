%option noyywrap

%{
// this is a simple flex program
%}

%%
([x]*(yxxx)*)*    	printf("Recognized\n");
.* ;             		printf("Not Recognized\n");


%%
	int main()
	{
		yylex();
		return 0;
	}
