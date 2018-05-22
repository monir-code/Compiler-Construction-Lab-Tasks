#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;
int main()
{
    char fin[10][20],st[10][20],ft[20][20],fol[20][20];
    int a=0,e,i,t,b,c,n,k,l=0,j,s,m,p;
//clrscr();
    printf("enter the no. of coordinates\n");
    scanf("%d",&n);
    printf("enter the productions in a grammar\n");
    for(i=0; i<n; i++)
        scanf("%s",st[i]);
    for(i=0; i<n; i++)
        fol[i][0]='\0';
    for(s=0; s<n; s++)
    {
        for(i=0; i<n; i++)
        {
            j=3;
            l=0;
            a=0;
l1:
            if(!((st[i][j]>64)&&(st[i][j]<91)))
            {
                for(m=0; m<l; m++)
                {
                    if(ft[i][m]==st[i][j])
                        goto s1;
                }
                ft[i][l]=st[i][j];
                l=l+1;
s1:
                j=j+1;
            }
            else
            {
                if(s>0)
                {
                    while(st[i][j]!=st[a][0])
                    {
                        a++;
                    }
                    b=0;
                    while(ft[a][b]!='\0')
                    {
                        for(m=0; m<l; m++)
                        {
                            if(ft[i][m]==ft[a][b])
                                goto s2;
                        }
                        ft[i][l]=ft[a][b];
                        l=l+1;
s2:
                        b=b+1;
                    }
                }
            }
            while(st[i][j]!='\0')
            {
                if(st[i][j]=='|')
                {
                    j=j+1;
                    goto l1;
                }
                j=j+1;
            }
            ft[i][l]='\0';
        }
    }
    printf("first pos\n");
    for(i=0; i<n; i++)
        printf("FIRS[%c]=%s\n",st[i][0],ft[i]);
}
/*
input
2
S->CC
C->eC|d

output:

First pos
FIRS[S] = ed
FIRS[C] = ed
*/
