#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll isprime(ll n){
    for (ll i = 2; i*i <= n; i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
int main()
{
    ll n;cin>>n;ll cnt=0;
    if(n%2==0){cnt=n/2;cout<<cnt;return 0;}
    //if(isprime(n)){cout<<1;return 0;}
    if(n==3){cout<<1;return 0;}
    while(n){
        for (ll i = 2; i*i<= n; i++)
        {
            if(n%2==0){cnt+=n/2;cout<<cnt;return 0;}
            //if(isprime(n)){cnt++;cout<<cnt;return 0;}
            if(n%i==0)
            {
            cnt++;
            n-=i;
            break;}
            if((i+1)*(i+1)>n){cnt++;cout<<cnt;return 0;}
        }
    }
    cout<<cnt;
    return 0;
}