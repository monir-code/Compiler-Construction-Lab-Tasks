#include <bits/stdc++.h>
using namespace std;

struct TAC{
    char op;
    string opar1;
    string opar2;
} codes[20];

map <string, int> mp1;
map <int, string> mp2;

int cnt,len,ck,ind = 1,ck1;
string str;

void pre_processing(int num_code){

    while(num_code--){

        getline(cin, str);

        string temp = ""; ck = 0; ck1 = 0;

        str.erase( remove( str.begin(), str.end(), ' ' ), str.end() );
        len = str.size();

        for(int i=0; i<len; i++){

            if(str[i] != '=' && ck == 0){
                temp += str[i];
            }
            if(str[i] == '='){ // startng symbol
                mp1[temp] = ind;
                mp2[ind] = temp;
                temp = "";
                ck = 1;

                if(i+1 == len){
                    codes[ind].op = '=';  // .....................................
                    codes[ind].opar2 = "";
                    break;
                }
                continue;
            }

            if( ck == 1 && ck1 == 0 && str[i] != '+' && str[i] != '-' && str[i] != '*' ){
                temp += str[i];
            }
            if(str[i] == '+' || str[i] == '-' || str[i] == '*'){
                codes[ind].op = str[i];
                codes[ind].opar1 = temp;
                temp = "";
                ck1 = 1;

                if(i+1 == len){
                    codes[ind].opar2 = "";
                    break;
                }
                continue;
            }

            if(ck1 == 1){
                temp += str[i];
                if(i+1 == len){
                    codes[ind].opar2 = temp;
                }
            }

            if(ck1 == 0 && i+1 == len){
                codes[ind].op = '=';
                codes[ind].opar1 = temp;
                codes[ind].opar2 = "";
            }
        }

        ind++ ;
//        cout << str << endl;
    }


}

int main(){

    cin >> cnt;
    getchar();

    pre_processing(cnt);

//    for(int i=1; i<=cnt; i++){
//        cout << " --> " << mp2[i] << " = " << codes[i].opar1 << " " << codes[i].op << " " << codes[i].opar2 << endl;
//    }

    printf("\n\nQuadruples:\n");
    printf("Op\tArg1\tArg2\tResult\n");

    for(int i=1; i<=cnt; i++){
        cout << codes[i].op << "\t"
             << codes[i].opar1 << "\t\t"
             << codes[i].opar2 << "\t\t"
             << mp2[i] << endl;
    }

    printf("\n\nTriples:\n");
    printf("\tOp\tArg1\tArg2\n");

    for(int i=1; i<=cnt; i++){
        cout << '[' << i << ']' << "\t" << codes[i].op << "\t";

        if(mp1[ codes[i].opar1 ]){
            cout << '[' << mp1[ codes[i].opar1 ] << ']' << "\t\t";
        }else{
            cout << codes[i].opar1 << "\t\t";
        }

        if(mp1[ codes[i].opar2 ]){
            cout << '[' << mp1[ codes[i].opar2 ] << ']' << endl;
        }else{
            cout << codes[i].opar2 << endl;
        }

    }

    return 0;
}



/**

7
t1 = a + b
t2 = c + d
t3 = t1 * t2
t4= a + b
t5 = t4 + c
t6 = t3 - t5
t7 = t6


**/
