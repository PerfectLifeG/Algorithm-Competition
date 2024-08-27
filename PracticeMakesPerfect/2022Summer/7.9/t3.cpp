#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll isprime(ll n){
    int i;
    for (i = 2; i*i <= n; i++)
    {
        if(n%i==0)return 0;
    }
    cout<<i;
    return 1;
}
int main()
{
    cout<<isprime(9998200081);
    return 0;
}