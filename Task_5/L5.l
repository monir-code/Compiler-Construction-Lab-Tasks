%option noyywrap

digit [0-9]
letter_ [A-Za-z_]
op [+*/-]
dot [.]
%%
CSE|EEE|IPE|FET|ARC|CEE|CEP|MEE|PME|SWE|GEB|BMB|PHY|MAT|STA|CHE|GEE|OCG|ANP|BNG|ECO|ENG|PSS|PAD|SOC|SCW {
	ECHO;
	printf("\n");
	}

. ;
\n ;
%%

int main(){
	yylex();
	return 0;
}