#include <bits/stdc++.h>
using namespace std;

char fin[10][20],st[10][20],ft[20][20],fol[20][20];
int a=0,e,i,t,b,c,n,k,l=0,j,s,m,p;

int main()
{


    //clrscr();
    printf("enter the no. of coordinates\n");
    scanf("%d",&n);
    printf("enter the productions in a grammar\n");
    getchar();
    for(i=0; i<2; i++){
        gets(st[i]);
    }

    printf("enter the first in grammars\n");

    for(i=0; i<n; i++)
        scanf("%s",ft[i]);
    printf("enter the follow in grammars\n");
    for(i=0; i<n; i++)
        scanf("%s",fol[i]);
//printf("--1a\n");
    s=0;
    for(i=0; i<n; i++)
    {

        j=3;
                //cout<<"----"<<st[i]<<endl;

        while(st[i][j]!='\0')
        {
           // printf("--1b\n");

            if((st[i][j-1]=='|')||(j==3))
            {
                for(p=0; p<=2; p++)
                {
                    fin[s][p]=st[i][p];
                }
                t=j;
                for(p=3; ((st[i][j]!='|')&&(st[i][j]!='\0')); p++)
                {
                    fin[s][p]=st[i][j];
                    j++;
                }
                fin[s][p]='\0';
                if(st[i][k]=='@')
                {
                    b=0;
                    a=0;
                    while(st[a][0]!=st[i][0])
                    {
                        a++;
                    }
                    while(fol[a][b]!='\0')
                    {
                        printf("M[%c,%c]=%s\n",st[i][0],fol[a][b],fin[s]);
                        b++;
                    }
                }
                else if(!((st[i][t]>64)&&(st[i][t]<91)))
                    printf("M[%c,%c]=%s\n",st[i][0],st[i][t],fin[s]);
                else
                {
                    b=0;
                    a=0;
                    while(st[a][0]!=st[i][3])
                    {
                        a++;
                    }
                    while(ft[a][b]!='\0')
                    {
                        printf("M[%c,%c]=%s\n",st[i][0],ft[a][b],fin[s]);
                        b++;
                    }
                }
                s++;
            }
            if(st[i][j]=='|')
                j++;
        }
    }
//    getch();
}
/*
input:
2
S->CC
C->eC | d
ed
ed
$
ed$

output:
M [S, e] =S->CC
M [S, d] =S->CC
M [C, e] =C->eC
M [C, d] =C->d

*/
