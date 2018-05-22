#include<stdio.h>
#include<string.h>

int nState , nAlpha , nFinal ;
int isFinal[11];
int table[15][30][15];

char str[10010] , inp;
int path[10010][15] , pIn , epsln[15][15];
int e_closure[15][15] , now[15];

void buildE_closure(int root , int node)
{
    if(e_closure[root][node] == 1) return;
    e_closure[root][node] = 1;
    int i;
    for(i = 0 ; i<nState ; i++){
        if(epsln[node][i] == 1) buildE_closure(root , i);
    }
}

int main()
{
    FILE *fp;
    fp = fopen("InputNFA.txt" , "r");
    //freopen("InputDFA.txt" , "r" , stdin);
    memset(table , 0 , sizeof(table));
    memset(isFinal , 0 , sizeof(isFinal));
    memset(epsln , 0 , sizeof(epsln));
    memset(e_closure , 0 , sizeof(e_closure));
    memset(path , 0 , sizeof(path));

    fscanf(fp , "%d", &nState);
    fscanf(fp , "%d", &nAlpha);

    //printf("%d %d\n" , nState , nAlpha);

    int i , j , k , l;
    for(i = 0 ; i<nState ; i++){
        for(j = 0 ; j<nAlpha ; j++){
            fscanf(fp , "%s" , str);
            int len = strlen(str);
            //printf(" ===> %s\n" , str);
            if(str[0] == 'f') continue;

            for(l = 0 ; l<len ; l++) {
                table[i][j][str[l]-'0'] = 1;
                printf("%d %d %d\n" , i , j , str[l]-'0');
            }
        }
        fscanf(fp , "%s" , str);
        int len = strlen(str);
        if(str[0] == 'f') continue;
        for(l = 0 ; l<len ; l++) epsln[i][str[l]-'0'] = 1;
    }
    fscanf(fp , "%d" , &nFinal);
    for(i = 0 ; i<nFinal ; i++){
        fscanf(fp , "%d" , &k);
        isFinal[k] = 1;
    }
    fclose(fp);

    for(i = 0 ; i<nState ; i++) buildE_closure(i , i);
    for(i = 0 ; i<nState ; i++){
        printf("%d ==> " , i);
        for(j = 0 ; j<nAlpha ; j++) {
            printf("%c = ", 'a' + j);
            for(k = 0 ; k<nState ; k++){
                if(table[i][j][k] == 1) printf("%d" , k);
            }
            printf(" ");
        }
        printf(" >>> ");
        for(j = 0 ; j<nState ; j++) if(e_closure[i][j] == 1) printf("%d " , j);
        printf("\n");
    }

    //printf(" ==========> %d\n" , table[1][0][2]);

    while(scanf(" %s" , str) == 1){
        //printf("str == %s\n" ,str);
        memset(path , 0 , sizeof(path));

        int len , id;
        char ch;
        len = strlen(str);
        pIn = 0;
        path[pIn][0] = 1;
        for(i = 0 ; i<nState ; i++) if(e_closure[0][i] == 1) path[pIn][i] = 1;
        int curr = 0 , prv;
        pIn++;
        for(i = 0 ; i<len ; i++){
            memset(now , 0 , sizeof(now));
            ch = str[i];
            id = ch - 'a';
            for(prv = 0 ; prv < nState ; prv++){
                if(path[pIn-1][prv] == 1){
                    for(j = 0 ; j<nState ; j++) {
                        if(table[prv][id][j]) {
                            now[j] = 1;
                            for(k = 0 ; k<nState ; k++) if(e_closure[j][k] == 1) path[pIn][k] = 1;
                        }
                    }
                }
            }
            pIn++;
        }

        for(i = 0 ; i<pIn ; i++){
            if(i > 0) printf(",");
            for(j = 0 ; j<nState ; j++) if(path[i][j] == 1) printf("%d" , j);
        }

        int flag = 0;
        for(i = 0 ; i<nState ; i++){
            if(path[pIn-1][i] != 1) continue;
            if(isFinal[i] == 1) {
                flag = 1;
                break;
            }
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
01   0   f
f    2   f
f    3   f
f    f   f
1
3

3
2
 f f 1
13 1 f
 f f f
 1
 2

10
2
f f 1
f f 24
3 f f
f f 6
f 5 f
f f 6
7 f 1
f 8 f
f 9 f
f f f
1
9

*/

