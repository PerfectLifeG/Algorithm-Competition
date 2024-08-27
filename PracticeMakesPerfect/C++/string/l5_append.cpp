#include<bits\stdc++.h>
using namespace std;

int main()
{
    string s1="hello";
    string s2=s1+" world";   //+号  是啥都能加 包括
    cout<<s2<<endl;
    string s3;
    s3.append(s2,0,5);   //string型只能这样用
    cout<<s3;
    
    return 0;
}