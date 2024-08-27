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
vector<int>v;
int n;
int ans=INF;
void dfs(int t,int now,int cnt,int pre){
    if(t==n){
        if(pre==0){
            ans=min(ans,cnt);
        }
        return;
    }
    if(now==0&&pre==-1){
        dfs(t+1,v[t+1],cnt,now);
        dfs(t+1,v[t+1]^1,cnt+1,now^1);
    }
    else if(now==1&&pre==-1){
        dfs(t+1,v[t+1],cnt,now);
        dfs(t+1,v[t+1]^1,cnt+1,now^1);
    }
    else if(now==0&&pre==1){
        dfs(t+1,v[t+1]^1,cnt+1,now^1);
    }
    else if(now==0&&pre==0){
        dfs(t+1,v[t+1],cnt,now);
    }
    else if(now==1&&pre==0){
        dfs(t+1,v[t+1],cnt,now);
    }else {
        dfs(t+1,v[t+1]^1,cnt+1,now^1);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    v.push_back(0);
    dfs(0,v[0],0,-1);
    if(ans==INF)cout<<-1<<endl;
    else cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}