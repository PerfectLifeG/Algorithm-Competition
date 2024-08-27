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
    int n;cin>>n;
    vector<int>v[n+1];
    vector<int>val(n+1);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=2;i<=n;i++){
        int fa;cin>>fa;
        v[fa].push_back(i);
    }

    vector<int>dp(n+1);
    function<void(int)> dfs=[&](int t){
        int mn=INF;
        for(auto j:v[t]){
            dfs(j);
            mn=min(mn,dp[j]);
        }
        if(t==1){
            dp[t]=val[t]+mn;
        }else if(!v[t].size()){
            dp[t]=val[t];
        }else dp[t]=min(mn,(mn+val[t])/2);
        // cout<<t<<' '<<dp[t]<<endl;
    };

    dfs(1);
    cout<<dp[1]<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}