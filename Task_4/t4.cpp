#include <bits/stdc++.h>
using namespace std;

char s[100][100] = {"CSE","EEE","SWE","PHY","GEB","BMB","GEE",
                    "ARC","CEE","PAD","BBA","ENG","BAN","CEP",
                    "SOC","SCW", "MAT","PSS","IPE","BNG","OCG",
                    "ECO","GEE"};
int i, j;

int main()
{
    char ss[1000];
    gets(ss);
    int l = strlen(ss);
    for(i = 0; i <l-2;)
    {
        int flag = 1;
        char a = toupper(ss[i]);
        char b = toupper(ss[i+1]);
        char c = toupper(ss[i+2]);
        for(j = 0; j < 28; j++)
        {
            if(s[j][0]==a&&s[j][1]==b && s[j][2]==c)
            {
                flag = 0;
                printf("%c%c%c\n", ss[i],ss[i+1],ss[i+2]);
            }
            if(!flag)
                break;
        }
        if(flag)i++;
        else i += 3;
    }
}
