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
const int N=100010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int n,k;
int ans;
vector<int>v[N];
map<int,int>dp[N];
int flag[N];
void dfs(int t,int fa){
    for(auto j:v[t]){
        if(j==fa)continue;
        dfs(j,t);
        if(flag[j])flag[t]=1;
        else{
            for(auto i:dp[j]){
                dp[t][i.x]+=i.y;
            }
        }
    }
    // cout<<t<<endl;
    // for(auto [i,j]:dp[t]){
    //     cout<<i<<' '<<j<<endl;
    // }
    if(!flag[t]){
        int sum=1;
        for(auto [i,j]:dp[t]){
            sum*=(j+1);
            if(sum>=k){
                ans++;
                flag[t]=1;
                return;
            }
        }
        if(sum>=k)ans++;
    }else ans++;
}
void solve(){
    cin>>n>>k;
    for(int i=2;i<=n;i++){
        int t=i;
        for(int j=2;j<=n/j;j++){
            if(t%j==0){
                int cnt=0;
                while(t%j==0){
                    cnt++;
                    t/=j;
                }
                dp[i][j]=cnt;
            }
        }
        if(t>1)dp[i][t]=1;
    }
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,1);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}