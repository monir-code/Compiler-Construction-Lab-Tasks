%option noyywrap
%option yylineno

%{
// this is a simple flex program
	int countA = 0;
	int countB = 0;
	int countC = 0;
%}

%%
[A]              countA++ ; ECHO;
[B]              countB++ ; ECHO;
[C]              countC++ ; ECHO;
\n               fprintf(yyout , " %6d[A = %d , B = %d , C = %d]\n" , yylineno-1 , countA , countB , countC); countA = 0; countB = 0; countC = 0;
<<EOF>>          fprintf(yyout , " %6d[A = %d , B = %d , C = %d]\n" , yylineno , countA , countB , countC); countA = 0; countB = 0; countC = 0;yyterminate();

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