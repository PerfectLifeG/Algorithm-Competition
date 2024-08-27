#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin()+1,x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<PII>v[2*n+1];
    int sum=0;
    for(int i=0;i<m;i++){
    	int a,b,c;cin>>a>>b>>c;
        sum+=c;
    	if(a>b)swap(a,b);
        v[a].push_back({b,c});
        v[b].push_back({a+n,c});
    }
    int dp[2*n+1][2*n+1]={};
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=2*n;l++){//下面这两个循环最多执行m次
            int r=l+len-1;
            dp[l][r]=dp[l+1][r];
            for(auto [j,w]:v[l]){
                if(j<=r){
                    int res=w;
                    res+=dp[l+1][j-1];
                    if(j+1<r)res+=dp[j+1][r];
                    dp[l][r]=max(dp[l][r],res);
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,dp[i][i+n-1]);
    cout<<sum-ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}