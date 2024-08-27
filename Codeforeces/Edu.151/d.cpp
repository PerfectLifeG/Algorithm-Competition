#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int>sufmx(n+2);
    vector<int>pre(n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int t=0;
    sufmx[n+1]=0;
    for(int i=n;i>=1;i--){
        t+=a[i];
        sufmx[i]=max({0ll,sufmx[i+1],t});
    }
    int ans=0;
    int mx=sufmx[1];
    for(int i=1;i<=n;i++){
        if(pre[i]+sufmx[i+1]>mx){
            mx=pre[i]+sufmx[i+1];
            ans=pre[i];
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}