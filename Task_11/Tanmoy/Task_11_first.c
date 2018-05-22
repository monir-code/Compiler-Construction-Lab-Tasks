#include<stdio.h>
#include<string.h>
int n=0,m=0,p,i=0,j=0,t=0;
char a[10][10],f[10];
void follow(char c);
void first(char c);

int main()
{

    int x = 0,tx=0,ty=0,xi,yi,k,ii,jc;
    FILE *f_input,*f_out;
    char buf[1000],buf2[1000],terminal[1000],non_terminal[1000],string[1000] ;

    f_input =fopen("inputgrammar.txt","r");

    f_out =fopen("First.txt","w");
    if (!f_input)
        return 1;

    while (fgets(buf,1000, f_input)!= NULL)
    {
        for(i=0; i<strlen(buf); i++)
        {
            buf2[x] = buf[i];
            x++;

        }
    }

    int start = 0;

    for(i=0; i<=strlen(buf2); i++)
    {

        if(buf2[i]!='\n')
        {
            string[start] = buf2[i];
            start++;

        }
        if(buf2[i]=='\n'||i==strlen(buf2))
        {
            string[start] = '\0';

            for(ii=0; ii<strlen(string); ii++)
            {
                a[t][ii] = string[ii];
            }
            string[0]= '\0';
            start = 0 ;
            n++;
            t++;
        }
    }
    for(i=0; i<n; i++)
    {
        fprintf(f_out,"%s\n",a[i]);
    }

    for(i=0; i<x; i++)
    {
        if(buf2[i] >= 'a' && buf2[i] <='z' || buf2[i] <='+' || buf2[i] <='*'
                || buf2[i] <='-'|| buf2[i] <='#')
        {
            terminal[tx] = buf2[i] ;
            tx++;
        }

        else if(buf2[i] >= 'A' && buf2[i] <='Z')
        {
            for(xi=0; xi<=ty; xi++)
            {
                if(non_terminal[xi] == buf2[i])
                    break;
            }
            if(xi==ty+1)
            {
                non_terminal[ty] = buf2[i] ;
                ty++;
            }
        }
    }

    for(xi=0; xi<ty; xi++)
    {
        m=0;
        first(non_terminal[xi]);
        fprintf(f_out,"FIRST(%c) = { ",non_terminal[xi]);
        for(yi=0; yi<m; yi++)
            fprintf(f_out,"%c ",f[yi]);
        fprintf(f_out," }\n");
    }

    fprintf(f_out,"\n");

    for(xi=0; xi<ty; xi++)
    {
        m=0;
        follow(non_terminal[xi]);

        for(yi=0; yi<m; yi++)
           ;
    }

    fclose(f_input);
    fclose(f_out);
}
void follow(char c)
{

    if(a[0][0]==c)f[m++]='$';
    for(i=0; i<n; i++)
    {
        for(j=3; j<strlen(a[i]); j++)
        {
            if(a[i][j]==c)
            {
                if(a[i][j+1]!='\0')fl_first(a[i][j+1]);

                if(a[i][j+1]=='\0'&&c!=a[i][0])
                    follow(a[i][0]);

            }
        }
    }
}


void fl_first(char c)
{
    int k;
    if(!(isupper(c)))f[m++]=c;
    for(k=0; k<n; k++)
    {
        if(a[k][0]==c)
        {
            if(a[k][3]=='#')follow(a[i][0]);
            else if(islower(a[k][3]))f[m++]=a[k][3];
            else fl_first(a[k][3]);
        }
    }
}

void first(char c)
{

//    printf("FT %c:\n",c);

    for(i=0; i<n+1; i++)
        if(a[i][0]==c)
            ft_first(a[i][3],4);

}


void ft_first(char c,int xx)
{
  //  printf("ft_first(%c,%d) ",c,xx);
    int k;
    if(!(isupper(c)))
    {
        f[m++]=c;
    //    printf("--> %c\n",c);
        return ;
    }
    for(k=0; k<n; k++)
    {
        if(a[k][0]==c)
        {
            if(a[k][3]=='#')
            {

                if(a[i][xx]!='\0')
                    ft_first(a[i][xx],xx+1);
                else
                {
                    f[m++]='#';
      //              printf("--> %c\n",'#');
                }

            }
            else if(islower(a[k][3]))
            {
                f[m++]=a[k][3];
        //        printf("--> %c\n",a[k][3]);
            }
            else ft_first(a[k][3],4);
        }
    }
}
