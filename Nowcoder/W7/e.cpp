#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int ksm(int a,int n){
    int ret=1ll;
    while(n){
        if(n&1)ret=(ret*a)%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ret%mod;
}
void solve()
{
    int n,k;cin>>n>>k;
    int t=n-k;
    int mx=max(t,k),mn=min(t,k);
//     cout<<mx<<' '<<mn<<endl;
    if(k==0||k==n){
        cout<<ksm(4,(n-1)*(n-2)/2)%mod*(ksm(3,n-1)%mod)%mod<<endl;
    }else{
//         cout<<ksm(ksm(6,mn),mx-1)%mod<<endl;
        cout<<ksm(ksm(6,mn),mx-1)%mod*ksm(4,mn)%mod*ksm(3,mx-1)%mod*ksm(4,((mx-1)*(mx-2))/2)%mod<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}