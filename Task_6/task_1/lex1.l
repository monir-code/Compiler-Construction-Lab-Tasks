%option noyywrap

digit [0-9]
letter_ [A-Za-z_]
op [+*/]
dot [.]

%%

letter_(digit)*(op)dot ECHO;
 

%%

int main(){
	yylex();
	return 0;
}