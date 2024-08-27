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
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,x;cin>>n>>x;
    int dp[x+1]={};
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        for(int j=x;j>=0;j--){
            if(j>=a&&(j-a==0||dp[j-a]))dp[j]=max(dp[j],dp[j-a]+1);
            // cout<<j<<' '<<dp[j]<<endl;
        }
    }
    if(dp[x]==0)cout<<"-1\n";
    else cout<<dp[x]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}