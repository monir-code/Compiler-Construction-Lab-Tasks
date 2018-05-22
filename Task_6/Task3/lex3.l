%option noyywrap
%option yylineno

FILE *ff,*fr;

%%

\n ECHO;
 

%%

int main(int argc, char *argv[]){

	ff = fopen(argv[1], "r+");
	fr = fopen("out.txt", "w+");
	yyin = ff;
	yylex();

	return 0;
}