#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int ksm(int a,int n){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}
int inv(int a){
    return ksm(a,mod-2);
}
void solve()
{
    int n;cin>>n;
    int flag=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;if(a!=1)flag=1;
        if(a==1)cnt++;
    }
    if(flag){
        cout<<1*inv(2)<<endl;
    }else if(cnt%2==0){
        cout<<0<<endl;
    }else cout<<1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}