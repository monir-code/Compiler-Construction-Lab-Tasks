#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll i, j, k, l, n, m = 9999999999, mini, ma = 0;

    string s[100], st, ch, sc="", result, fs, maxi, rs= "";
    vector<string> ss, sp;
    ll x = 1;
    while(cin>>s[x++])
    {
        ;
    }
    n = x-1;
    for(i = 1; i <= n; i++)
    {
        st = s[i];
        sc = "";

        for(j = 0; j < st.length(); j++)
        {
            if(i == 1)
            {
                fs = st[0];
            }
            if(st[j] == '=')
            {
                l = j;
            }
        }

        if(i == 1)
        {

            for(k = l + 1; k < st.length(); k++)
            {
                if(st[k] == '|')
                {
                    ss.pb(sc);
                    sc = "";
                }
                if(st[k] != '|')
                {
                    ch = st[k];
                    sc = sc + ch;
                }

            }
            ss.pb(sc);
        }
    }

    for(k = 0; k < ss.size(); k++)
    {
        mini = ss[k].size();
        m = min(m,mini);
        maxi = ss[k];
    }

    for (int i = 0; i < m; i++)
    {

        char current = ss[0][i];

        for (int j = 1 ; j < ss.size(); j++)
        {
            if (ss[j][i] != current)
            {
                break;
            }
            result.pb(current);
        }

    }

    for(j = 0; j < ss.size(); j++)
    {
        maxi = ss[j];
        for(k = 0; k < maxi.length(); k++)
        {


            if(k >= result.length())
            {
                rs = rs + maxi[k];


            }
        }
        if(j != ss.size()-1)
        {
            rs = rs + '|';
        }
    }

    cout<<fs<<"="<<result<<fs<<"'"<<endl;
    cout<<fs<<"'"<<"="<<rs<<endl;

    for(i = 2; i <= n; i++)
    {
        cout<<s[i]<<endl;
    }

    return 0;
}
