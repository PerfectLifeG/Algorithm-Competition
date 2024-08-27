#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    string s;
    string t;string tt;
    cin>>s;
    for (int i = 1; i <= s.size()/2; i++)
    {
        string s1(s,0,i); 
        string s2(s,s.size()-i,i);
        if(s1==s2)t=s1;
    }
    for (int i = 1; i < t.size(); i++)
    {
        string s3(s,0,i); 
        string s4(s,s.size()-i,i);
        if(s3==s4)tt=s3;
    }
    cout<<s.size()-tt.size()*2;
    return 0;
}