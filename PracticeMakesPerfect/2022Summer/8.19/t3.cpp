#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll book[100];
int fun(ll a){
    if(a==1)return 1;
    for (int i = 2; i <= a; i++)
    {
        ll x1=book[i];ll x2=book[i+1];
        if(x1-a<0&&x2-a>0&&a-x1<x2-a){
            return i;
        }else if(x1-a<0&&x2-a>0&&a-x1>x2-a){
            return i+1;
        }
    }
}
int main()
{
    int t;cin>>t;
    book[1]=1;book[2]=1;
    for (int i = 3; i <= 100; i++)
    {
        book[i]=book[i-1]+book[i-2];
    }
    for (int i = 0; i < t; i++)
    {
        ll a;cin>>a;
        cout<<fun(a);
    }
    return 0;
}