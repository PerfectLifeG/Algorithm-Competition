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
vector<int>v;int n,k;
int b;
int ans=INF;
void dfs(int t,int sum,int cnt){
    if(t==n){
        if(sum==b){
            ans=min(ans,cnt);
        }
        return;
    }
    if(sum==b){
        ans=min(ans,cnt);
        return;
    }
    dfs(t+1,sum|v[t],cnt+1);
    dfs(t+1,sum,cnt);
}
void solve(){
    cin>>n>>k;
    b=(1<<k)-1;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    dfs(0,0,0);
    if(ans==INF)cout<<-1<<endl;
    else cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}