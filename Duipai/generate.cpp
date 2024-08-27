#include<iostream>  
#include<windows.h>
using namespace std;  
int main()  
{  
    int t=10;
    for(int i=21;i<=t+20;i++)
    {  
        string in=to_string(i)+".in";
        // string s1="data.exe > "+in;
        // system(s1.c_str());

        string out=to_string(i)+".out";
        string s2="ans.exe < "+in+" > "+out;
        system(s2.c_str());
        // Sleep(1000);

    }

    return 0;  
} 