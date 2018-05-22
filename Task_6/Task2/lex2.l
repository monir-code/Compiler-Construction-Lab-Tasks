%option noyywrap
%option yylineno


%%

^\n printf("--> %4d\n", yylineno-1);
(.*) printf("==> %4d\t%s", yylineno, yytext);
\n ECHO;
 

%%

int main(){
	yylex();
	return 0;
}