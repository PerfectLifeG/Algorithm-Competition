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
    sort(all(v));
    vector<int>dp[m+1];
    vector<int>pre[m+1];
    for(int i=0;i<n;i++){
        for(int j=v[i];j<=m;j++){
            if(j-v[i]!=0&&!pre[j-v[i]].size())continue;
            int flag=0;
            if(dp[j].size()){
                if(!pre[j-v[i]].size()&&dp[j][0]<=v[i])continue;
                int k=0;
                for(;k<pre[j-v[i]].size()&&k<dp[j].size();k++){
                    if(pre[j-v[i]][k]>dp[j][k]){flag=1;break;}
                    else if(pre[j-v[i]][k]<dp[j][k]){flag=0;break;}
                }
                if(dp[j].size()>k&&(k==pre[j-v[i]].size()||k==dp[j].size())&&v[i]>dp[j][k])flag=1;
            }
            if(flag)continue;
            dp[j]=pre[j-v[i]];
            dp[j].push_back(v[i]);
        }
        for(int j=0;j<=m;j++){
            pre[j]=dp[j];
        }
    }
    if(!dp[m].size())cout<<"No Solution\n";
    int first=1;
    for(auto i:dp[m]){
        if(first){cout<<i;first=0;}
        else cout<<' '<<i;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}