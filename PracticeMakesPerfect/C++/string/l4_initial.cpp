#include<bits\stdc++.h>
using namespace std;
//string 初始化
int main()
{
    string s1;
    s1="hello world";
    const char *str="hello world";
    string s2(str);
    string s3(s1,3,2);
    string s4(10,'a');
    cout<<"s1 = "<<s1<<endl;
    cout<<"s2 = "<< s2<<endl;
    cout<<"s3 = "<< s3<<endl;
    cout<<"s4 = "<<s4<<endl;

    return 0;
}