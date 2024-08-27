#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int h[N],e[N],ne[N],idx;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int son[N];
int f[N];
int dfs(int t){
    f[0]=1;
    for(int i=h[t];~i;i=ne[i]){
        int j=e[i];
        for(int k=son[t]-1;k>=son[j];j--){
            f[j]|=f[j-son[j]];
        }
    }
    int ans=0;
    for(int j=0;j<=son[t];j++){
        if(f[j]){
            ans=max(ans,j*(son[t]-1-j));    
        }
    }
    return ans;
}
void solve()
{
    int n;cin>>n;
    memset(son,0,sizeof son);
    memset(f,0,sizeof f);
    memset(h,-1,sizeof h);
    for(int i=2;i<=n;i++){
        int a;cin>>a;
        add(a,i);
        son[a]++;
    }
    cout<<dfs(1)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}