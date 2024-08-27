#include<bits/stdc++.h>
using namespace std;
long long f(long long a, long long b, long long c){
    long long s = 0;
    while (b)
    {
        if(b&1ll) 
        s=(s+a)%c;
        a=(a+a)%c;
        b>>=1;
    }
    return s;
}
int main()
{
    unsigned long long int n;
    cin>>n;
    cout<<f(n,n,998244353);
    return 0;
}