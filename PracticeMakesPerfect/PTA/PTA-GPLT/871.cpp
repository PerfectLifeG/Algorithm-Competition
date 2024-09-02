#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
const int mod=1e9+7;
unordered_map<int,int>prime;
int sum(int q,int n){
    int t=1;
    for(int i=0;i<n+1;i++){
        t=(t*q)%mod;
    }
    int res=(1-t)/(1-q)%mod;
    return res;
}
void divisor_num(int n){
    for(int i=2;i<=n/i;i++){
        while(n%i==0){
            n/=i;
            prime[i]++;
        }
    }
    if(n>1)prime[n]++;
}
signed main(){
    int n;cin>>n;
    while(n--){
        int a;cin>>a;
        divisor_num(a);
    }
    int res=1;
    for(auto it:prime){
        int p=it.x;
        int a=it.y;
        //int t=1;
        //while(a--)t=(t*p+1)%mod;
        res=(res*sum(p,a))%mod;
        //res=(res*t)%mod;
    }
    cout<<res;
    return 0;
}