#include<stdio.h>
#include<string.h>

int nState , nAlpha , nFinal ;
int isFinal[11];
int table[15][30];

char str[10010];
int path[10010] , pIn;

int main()
{
    FILE *fp;
    fp = fopen("InputDFA.txt" , "r");
    //freopen("InputDFA.txt" , "r" , stdin);
    memset(table , -1 , sizeof(table));
    memset(isFinal , 0 , sizeof(isFinal));
    fscanf(fp , "%d", &nState);
    fscanf(fp , "%d", &nAlpha);

    printf("%d %d\n" , nState , nAlpha);

    int i , j , k , l;
    for(i = 0 ; i<nState ; i++){
        for(j = 0 ; j<nAlpha ; j++){
            fscanf(fp , "%d" , &table[i][j]);
        }
    }
    fscanf(fp , "%d" , &nFinal);
    for(i = 0 ; i<nFinal ; i++){
        fscanf(fp , "%d" , &k);
        isFinal[k] = 1;
    }
    fclose(fp);

    while(scanf(" %s" , str) == 1){
        //printf("str == %s\n" ,str);
        int len , id;
        char ch;
        len = strlen(str);
        pIn = 0;
        path[pIn++] = 0;
        int curr = 0 , flag = 1;
        for(i = 0 ; i<len ; i++){
            ch = str[i];
            id = ch - 'a';
            if(table[curr][id] == -1){
                flag = 0;
                printf(" ===> Invalid Input\n");
                break;
            }
            curr = table[curr][id];
            path[pIn++] = curr;
        }
        if(flag == 1 && isFinal[curr] == 0) flag = 0;

        for(i = 0 ; i<pIn ; i++){
            if(i > 0) printf(",");
            printf("%d" , path[i]);
        }
        printf(" ");
        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
/**
4
2
1 0
1 2
1 3
1 0
1
3

4
3
1 0 0
1 2 0
0 0 3
1 0 0
1
3

*/
