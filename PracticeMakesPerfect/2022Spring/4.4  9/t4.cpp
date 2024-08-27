#include<iostream>
#include<algorithm>
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
    int n;
    cin>>n;int s=0;
    for (int i = 0; i < n; i++)
    {
        int a;cin>>a;
        if(a==0)s--;
        if(a==1)s++;
        if(s<0){cout<<"0";return 0;}
    }
    if(s==0)
    cout<<"1";
    else cout<<"0";
    return 0;
}