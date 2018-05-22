#include <iostream>
#include <set>
#include <bits\stdc++.h>

int main ()
{
    std::set<char> myset;
    std::set<char> mylow;

    std::set<char>::iterator it;
    int upper = 0, lower = 0,digit=0,special=0;
    char ch[180];
    int i;


    printf("Enter GRAMMAR( press ';' to end input)\n");
    scanf("%[^;]s", ch);

    printf("Input String = %s", ch);


    for(i = 0; ch[i]!='\0'; i++)

    {
        if (ch[i] >= 'A' && ch[i] <= 'Z')
        {
            upper++;
            myset.insert(ch[i]);

        }

        else if ((ch[i] >= 'a' && ch[i] <= 'z')||(ch[i]>='0'&& ch[i]<='9')||ch[i]=='+'||
                 ch[i]=='-' ||ch[i]=='/' ||ch[i]=='*'||ch[i]=='$')
        {
            lower++;
            mylow.insert(ch[i]);
        }


    }

 std::cout<<" NON-TERMINALS  -> ";
    for (it=myset.begin(); it!=myset.end(); ++it)
        std::cout <<' ' << *it;
    std::cout << '\n';
    std::cout <<" TERMINALS      -> ";
    for (it=mylow.begin(); it!=mylow.end(); ++it)
        std::cout  << ' ' << *it;
    std::cout << '\n';

    return 0;
}


/*
E=jjE|FE|$
L=Lyy|cV|/+gTT
;

*/
