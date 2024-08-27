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
int dp[N];
int vis[N][105];
int v[N];
void solve(){
    int n,m;cin>>n>>m;
    dp[0]=1;
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v,v+n,greater<int>());
    for(int i=0;i<n;i++){
        for(int j=m;j>=v[i];j--){
            if(dp[j-v[i]]){
                dp[j]=1;
                vis[i][j]=1;
            }
        }
    }
    vector<int>ans;
    int id=n-1;
    if(dp[m])while(m){
        if(vis[id][m]){
            ans.push_back(v[id]);
            m-=v[id];
        }
        id--;
    }
    if(ans.size()){
        for(int i=0;i<ans.size();i++){
            if(i)cout<<' ';
            cout<<ans[i];
        }
    }else cout<<"No Solution\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}