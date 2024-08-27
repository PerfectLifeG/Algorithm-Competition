#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=10001;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int dp[201];
void solve(){
    int tot;cin>>tot;
    int n;cin>>n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    int m;cin>>m;
    vector<int>mx(n+1);
    int ans=0;
    for(int i=1;i<=m;i++){
        int a;cin>>a;
        int t=0;
        for(int j=1;j<=n;j++){
            t=max(t,mx[j]);
            if(a==v[j])dp[j]=t+1;
        }
        for(int j=1;j<=n;j++){
            mx[j]=max(mx[j],dp[j]);
            ans=max(ans,dp[j]);
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}