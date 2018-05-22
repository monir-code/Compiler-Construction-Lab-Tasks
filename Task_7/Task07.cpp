#include <bits/stdc++.h>
using namespace std;

string keywords[100]= {"auto", "bool", "break", "case", "catch", "char", "class", "const_cast", "continue",
                       "default", "delete", "do", "double", "else", "enum","dynamic_cast", "extern", "false", "float",
                       "for", "union", "unsigned", "using", "friend", "goto", "if", "inline", "int", "long",
                       "mutable", "virtual", "namespace", "new", "operator", "private", "protected",	"public", "register", "void",
                       "reinterpret_cast",	"return",	"short",	"signed",	"sizeof",
                       "static",	"static_cast"
                      };

string operato[]= {"+-/*^="};

char input[1000];
char comment[20][1000];

vector<string>key;
vector<char>op;

int main()
{
    freopen("input.c","r",stdin);
    freopen("keywords.txt","w",stdout);
    int k=0;
    while(gets(input)) {

        string st="";
         int ck=0;

        for(int i=0; i<strlen(input); i++)
        {
            if(ck==1)
            {
                for(int j=i; j<strlen(input); j++)
                {
                    comment[k][j-i]=input[j];
                }
                k++;
                i=strlen(input);
            }
            if(input[i]=='/'&&input[i+1]=='/')ck=1,i++;
            else if(input[i]==' '||input[i]==','||input[i]=='.'||input[i]=='+' ||input[i]=='-' ||input[i]=='*' ||input[i]=='/' ||input[i]=='=')
            {
                if(input[i]=='+' ||input[i]=='-' ||input[i]=='*' ||input[i]=='/'||input[i]=='=')op.push_back(input[i]);
                for(int j=0; j<=44; j++)
                    if(st==keywords[j])key.push_back(st);
                st="";
            }

            else if(i==strlen(input)-1)
            {
                st=st+input[i];
                for(int j=0; j<=44; j++)
                    if(st==keywords[j])key.push_back(st);
            }

            else st=st+input[i];
        }

    }
    printf("Keywords:\n\n");
    for(int i=0; i<key.size(); i++)cout<<key[i]<<endl;
    printf("\nComments:\n");
    for(int i=0; i<k; i++)puts(comment[i]);
    printf("\nOperators:\n");
    for(int i=0; i<op.size(); i++)cout<<op[i]<<endl;

    return 0;
}










