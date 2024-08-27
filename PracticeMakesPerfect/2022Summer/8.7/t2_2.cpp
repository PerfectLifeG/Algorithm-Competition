#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long  ll;
ll l,r;
ll cmp(ll n1,ll n2){
    return n1>n2;
}
int main()
{
    int n;cin>>n;
    ll node[n];
    for (int i = 0; i < n; i++)
    {
        cin>>node[i];
    }
    cin>>l>>r;
    sort(node,node+n,cmp);
    for (int i = 0; i < n; i++)
    {
        if(node[i]<r)
    }
    return 0;
}