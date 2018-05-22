#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char production[100][100];
    int i = 0;

    //printf("Productions of a Grammar G are: \n");

    while(gets(production[i++]))
    {
        ;
    }

    printf("The Grammar after left recursion elimination: \n\n");

    int f = i-1;

    for(i=0; i<=f; i++)
    {
        char n_t;
        char beta;
        int num;
        int index=3;
        char alpha[10];
        n_t=production[i][0];
        if(n_t==production[i][index])
        {
            //alpha=pr[i][index+1];
            int k = 0;
            for(int j = index+1; j < strlen(production[i]); j++)
            {
                if(production[i][j]=='|')
                    break;
                alpha[k++] = production[i][j];
            }
            alpha[k]='\0';

            while(production[i][index]!=0 && production[i][index]!='|')
            {
                index++;
            }
            if(production[i][index]!=0)
            {
                beta=production[i][index+1];

                printf("%c->%c%c\'",n_t,beta,n_t);
                printf("\n%c\'->",n_t);
                for(int x = 0; x < strlen(alpha); x++)
                {
                    printf("%c", alpha[x]);
                }
                printf("%c\'|\356\0",n_t);
                printf("\n");
            }
        }
        else
            puts(production[i]);
        index=3;
    }
}

/**

E->E+T|T
T->T*F|F
F->(E)|id

**/

