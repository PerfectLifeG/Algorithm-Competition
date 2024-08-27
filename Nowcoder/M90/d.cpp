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
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
PII a[20];
int s[N];
int pre[N];
int n,m;
int ans=0;
void dfs(int t){
    if(t==m){
        for(int i=1;i<=n;i++){
            pre[i]=s[i]+pre[i-1];
            if(pre[i]<=1)return;
        }
        ans++;ans%=mod;
        return;
    }
    s[a[t].x]++;
    s[a[t].y+1]--;
    dfs(t+1);
    s[a[t].x]--;
    s[a[t].y+1]++;
    dfs(t+1);
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i].x>>a[i].y;     
    }
    dfs(0);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}