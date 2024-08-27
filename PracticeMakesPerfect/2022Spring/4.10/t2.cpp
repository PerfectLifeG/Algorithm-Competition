#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string a;
    cin>>a;int i=0;int an1;int t;
    while(a.find("mocha")!=-1&&i<=k){
        t=a.find("mocha");
        if(i==0)an1=t;
        a.erase(t,5);
        i++;
    }
    if(i>=k)cout<<"Mocha suki!"<<endl<<t-an1+i*5;
    else cout<<"poor Mocha";
    return 0;
}