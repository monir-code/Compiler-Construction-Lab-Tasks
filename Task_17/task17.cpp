#include <bits\stdc++.h>
#include <strstream>
using namespace std;
int main ()
{

    string input,inputString[20] ;
    cout<<" Please enter '#' at the end of your 3 address code"<<endl;
    getline(cin,input,'#');

    std::stringstream stringStream(input);
    std::string l ,res,l3;
    int i=0;
    while(std::getline(stringStream, l))
    {
        std::size_t prev = 0, pos;
        while ((pos = l.find_first_of("\n", prev)) != std::string::npos)
        {
            if (pos > prev)
                //wordVector.push_back(line.substr(prev, pos-prev));
            {
                inputString[i]=l.substr(prev, pos-prev);
                i++;
            }
        //    cout<<inputString[i-1]<<endl;

            prev = pos+1;
        }
        if (prev < l.length())
        {
            // wordVector.push_back(line.substr(prev, std::string::npos));

            inputString[i]=l.substr(prev, std::string::npos);
            i++;

        }
      //  cout<<inputString[i-1]<<" "<<i<<endl;

    }
    /*
    // read input
    string input;
    getline(cin, input);

    // initialize string stream
    stringstream ss(input);
    cout<<ss;
    // extract input
    string name;

    ss >> name ;
    cout<<ss;
    cout<<name;
    */
    int v=0;
    string result;
    while (v<i)
    {
//LOOP START--------------------------
        int chk=0;

        std::stringstream stringStream(inputString[v]);
        std::string line ,l2;
        while(std::getline(stringStream, line))
        {
            std::size_t prev = 0, pos;
            while ((pos = line.find_first_of("=", prev)) != std::string::npos)
            {
                if (pos > prev)
                    //wordVector.push_back(line.substr(prev, pos-prev));

                    result=line.substr(prev, pos-prev);
                /// cout<< result<<endl;

                prev = pos+1;
            }
            if (prev < line.length())
                // wordVector.push_back(line.substr(prev, std::string::npos));

                l2=line.substr(prev, std::string::npos);
            /// cout<< l2 <<endl;

            if (l2.find('+') != std::string::npos)  chk=1;
            else if (l2.find('-') != std::string::npos) chk=2 ;
            else if (l2.find('/') != std::string::npos) chk=3;
            else if (l2.find('*') != std::string::npos) chk=4;
            else
            {
                if(l2.find_first_not_of("0123456789") == std::string::npos){
                   cout<<"LD "<<"r"<<result<<" "<<l2<<endl;
                }else
                cout<<"MOV "<<"r"<<result<<" r"<<l2<<endl;
            }


        }

        std::stringstream ss(l2);
        std::string line2 ,op1,op2;

        while(std::getline(ss, line2))
        {
            std::size_t prev = 0, pos;


            while ((pos = line2.find_first_of("+-/*", prev)) != std::string::npos)
            {
                if (pos > prev)
                    //wordVector.push_back(line.substr(prev, pos-prev));

                    op1=line2.substr(prev, pos-prev);
                //cout<< op1<<endl;

                prev = pos+1;
            }
            if (prev < line2.length())
                // wordVector.push_back(line.substr(prev, std::string::npos));

                op2=line2.substr(prev, std::string::npos);
            // cout<<op2<<endl;


            //cout<< op2 <<endl;
            if(chk==1)
                cout<<"ADD "<<"r"<<result<<" r"<<op1<<" r"<<op2<<endl;
            else if(chk==2)
                cout<<"SUB "<<"r"<<result<<" r"<<op1<<" r"<<op2<<endl;
            else if(chk==3)
                cout<<"DIV "<<"r"<<result<<" r"<<op1<<" r"<<op2<<endl;
            else if(chk==4)
                cout<<"MUL "<<"r"<<result<<" r"<<op1<<" r"<<op2<<endl;

        }

        v++;
    }
    cout<<"STR "<<"r"<<result<<endl;
}

/*
g=9
f=10
t=g+f
s=t
l=s*s
q=l/s#

*/
