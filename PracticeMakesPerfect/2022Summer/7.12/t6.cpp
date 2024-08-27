#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
int main()
{
    ll a,max;cin>>max>>a;
    ll cnt=0;
    while(a!=1){
        cnt+=max/a;
        max%=a;
        ll t=a;
        a=max;
        max=t;
        if(a==0){
            cout<<cnt;
            return 0;
        }
    }
    cnt+=max;
    cout<<cnt;
    return 0;
}