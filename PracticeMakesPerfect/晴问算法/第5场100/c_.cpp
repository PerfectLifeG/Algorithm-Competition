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
vector<PII>v[N];
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    int dp[N]={};
    for(int i=1;i<N;i++){
        for(auto [j,w]:v[i]){
            dp[j]=max(dp[j],dp[i-1]+w);
        }
        dp[i]=max(dp[i-1],dp[i]);
    }
    cout<<dp[N-1]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}