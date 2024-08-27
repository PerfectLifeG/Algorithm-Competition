#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=400010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int s[N]={};
PII v[N];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>v[i].x>>v[i].y;
        s[v[i].x]+=1;
        s[v[i].y+1]-=1;
    }
    for(int i=1;i<N;i++){
        s[i]=(s[i]+s[i-1]+mod)%mod;
    }
    for(int i=1;i<N;i++){
        s[i]=(s[i]+s[i-1]+mod)%mod;
    }
    int ans=0;
    for(int i=0;i<m;i++){
        int b=n-v[i].x;
        int a=max(1ll,n-v[i].y);
        auto [x,y]=v[i];
        int l=max(a,x);
        int r=min(b,y);
        if(l<=r)ans=(ans-r+l-1+mod)%mod;
        if(b>=a)ans=(ans+s[b]-s[a-1]+mod)%mod;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}