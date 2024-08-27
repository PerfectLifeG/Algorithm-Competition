#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    vector<int>pre(n+1);
    vector<int>suf(n+2);
    pre[0]=suf[n+1]=-1e18;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=max(a[i]+i,pre[i-1]);
    }
    for(int i=n;i>=1;i--){
        suf[i]=max(a[i]-i,suf[i+1]);
    }
    int ans=0;
    for(int i=2;i<n;i++){
        ans=max(ans,a[i]+pre[i-1]+suf[i+1]);
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