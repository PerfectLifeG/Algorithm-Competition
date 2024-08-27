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
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m,k,d;cin>>n>>m>>k>>d;
    int a[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    int dp[n+1][m+1]={};
    for(int i=1;i<=n;i++){
        dp[i][1]=1;
        priority_queue<PII,vector<PII>,greater<PII>>q;
        q.push({dp[i][1],1});
        for(int j=2;j<=m;j++){
            while((j-q.top().y)>d+1)q.pop();
            dp[i][j]=q.top().x+a[i][j]+1;
            q.push({dp[i][j],j});
        }
    }

    vector<int>pre(n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+dp[i][m];

    int ans=1e18;
    for(int i=1;i+k-1<=n;i++){
        ans=min(ans,pre[i+k-1]-pre[i-1]);
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