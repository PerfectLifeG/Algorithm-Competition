#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    string a;
    cin>>a;
    string b(a,a.size()-1,1);
    string c(a,0,a.size()-1);
    string d(c,0,1);
    //if(b<"A"||b>"F"||b=="E"){cout<<"输入错误";return 0;}
    if(c>="1"&&c.size()==1||(c>="1"&&c<="17")){
    if(b=="A"||b=="a")cout<<"窗口";
    else if(b=="B"||b=="b")cout<<"中间";
    else if(b=="C"||b=="c")cout<<"过道";
    else if(b=="D"||b=="d")cout<<"过道";
    else if(b=="F"||b=="f")cout<<"窗口";
    else cout<<"输入错误";
    }else cout<<"输入错误";
    return 0;

}