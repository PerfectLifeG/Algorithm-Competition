#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(all(v),greater<int>());
    vector<int>dp[m+1];
    vector<int>pre[m+1];
    for(int i=0;i<n;i++){
        for(int j=v[i];j<=m;j++){
            if(j-v[i]!=0&&!pre[j-v[i]].size())continue;
            dp[j]=pre[j-v[i]];
            dp[j].push_back(v[i]);
        }
        for(int j=0;j<=m;j++){
            pre[j]=dp[j];
        }
    }
    if(!dp[m].size())cout<<"No Solution\n";
    int first=1;
    for(int i=dp[m].size()-1;i>=0;i--){
        if(first){cout<<dp[m][i];first=0;}
        else cout<<' '<<dp[m][i];
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}