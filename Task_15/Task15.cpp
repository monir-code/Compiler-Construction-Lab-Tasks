#include <bits/stdc++.h>
using namespace std;

struct TAC{
    string normal_stmt;
    string condi_uncondi_stmt;
    int target;
    bool leader_ck;
} codes[20]; // 20 ta statement

vector <int> Blocks;

int cnt,len,ck,ind = 1,ck1;
string str;

void pre_processing(int num_code){

    while(num_code--){

        getline(cin, str);

        len = str.size();

        int pos;
        pos = str.find("goto");

        int num = 0;
        if(pos != -1){
            for(int i=pos+5; i<len; i++){
                if(str[i] >= '0' && str[i] <= '9'){
                    num *= 10;
                    num += (str[i] - '0');
                }
                //printf("--> %c\n",str[i]);
            }
            printf("--> Target index:   %d\n",num);
            codes[ind].target = num;
            codes[ind].condi_uncondi_stmt = str;
            codes[ind+1].leader_ck = true;
            codes[num].leader_ck = true;
            codes[ind].normal_stmt = "null";
            ind++ ;
            continue;
        }

        if(ind == 1){
            codes[ind].leader_ck = true;
        }
        codes[ind].target = -1;
        codes[ind].normal_stmt = str;
        codes[ind].condi_uncondi_stmt = "null";

        ind++ ;
    }
}

int main(){

    printf("Enter Number of Three Address Codes: ");
    cin >> cnt;
    getchar();

    pre_processing(cnt);


    int block=0;
    printf("\n\nBasic Blocks:\n");
    int ck_cnt = 0, first;

    for(int i=1; i<=cnt; i++){

        if( codes[i].leader_ck == true && (codes[i].condi_uncondi_stmt != "null" || codes[i].normal_stmt != "null") ){
            Blocks.push_back(i);   /// store: i th TAC hocce first code of the basic block 'block'
            ++block;
            printf("\nBlock %d:\n",block);
            //cout << " ==> Leader index: " << i << endl;
        }
        if(codes[i].condi_uncondi_stmt == "null"){
            cout << codes[i].normal_stmt << endl;
        }
        if(codes[i].normal_stmt == "null"){
            cout << codes[i].condi_uncondi_stmt << endl;
        }
    }

//    for(int i=0; i<Blocks.size(); i++){
//        cout << " Block values: " << Blocks[i] << endl;
//    }

    int ara[100] = {0};

    for(int i=0; i<block; i++){
        if(i == block-1){
            for(int j=Blocks[i]; j<=cnt; j++){
                ara[j] = i+1;
            }
            continue;
        }
        if(i != block-1){
        for(int j=Blocks[i]; j<=Blocks[i+1]-1; j++){
            ara[j] = i+1;
        }}
    }

    for(int i=1; i<=cnt; i++){
        printf("%d TAC %d no. block er under a \n",i,ara[i]);
    }

    printf("\n\n\nFlow Graph:\n");
    printf("\nEdges:\n");

    printf("Start --> B1\n");

    for(int i=0; i<block; i++){
        if(i < block-1){
            printf("B%d --> B%d\n",i+1,i+2);
            int tar = -1;
            for(int j=Blocks[i]; j<=Blocks[i+1]-1; j++){
                //cout << "TAC: " << codes[j].normal_stmt << " or, " << codes[j].condi_uncondi_stmt << " No: " << j << " target: " << codes[j].target << endl;
                if(codes[j].target != -1 && codes[j].target <= cnt){
                    tar = codes[j].target;
                    //printf("==> tar: %d\n",tar);
                }
            }
            if(tar != -1){
                if(tar != i+2){
                    printf("B%d --> B%d\n",i+1,ara[tar]);
                }
            }
        }
        if(i == block-1){
            int tar = -1;
            for(int j=Blocks[i]; j<=cnt; j++){
                if(codes[j].target != -1 && codes[j].target <= cnt){
                    tar = codes[j].target;
                }
            }
            if(tar != -1){
                printf("B%d --> B%d\n",i+1,ara[tar]);
            }
        }
    }
    printf("B%d --> End\n",block);

//    for(int i=0; i<block; i++){
//        if(i < block-1){
//            printf("Block %d: %d to %d\n",i+1, Blocks[i], Blocks[i+1]-1);
//        }
//    }

    return 0;
}




/**

9
i = 0;
if i<=10 goto(4)
goto(10)
t1 = i*1;
t2 = i*4;
t3 = b + t2
*t3 = t1
i = i + 1
goto(2)


5
i = 0;
if i<=10 goto(3)
t1 = i*1;
goto(2)
goto(6)

7
t1 = a + b
t2 = c + d
t3 = t1 * t2
t4= a + b
t5 = t4 + c
t6 = t3 - t5
t7 = t6


**/
