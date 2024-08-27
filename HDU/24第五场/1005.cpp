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
const int N=1e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int root[N];
int find(int a){
    if(a==root[a]) return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    a=find(a),b=find(b);
    root[a]=b;
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<=n;i++)root[i]=i;
    vector<PII>v[n+1];
    for(int i=1;i<=n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }

    vector<int>dep(n+1);
    vector<int>fa(n+1);
    vector<int>idx(n+1);
    function<void(int,int,int)> dfs=[&](int t,int ff,int d){
        dep[t]=d;
        fa[t]=ff;
        for(auto [j,w]:v[t]){
            if(j==ff)continue;
            idx[j]=w;
            dfs(j,t,d+1);
        }
    };
    dfs(1,1,0);

    vector<int>ans(n+1);
    for(int d=n/2;d>=1;--d){
        int x=find(d);
        for(int j=d+d;j<=n;j+=d){
            int y=find(j);
            while(x!=y){
                if(dep[x]>dep[y])swap(x,y);
                ans[idx[y]]=d;
                merge(y,fa[y]);
                y=find(y);
            }
        }
    }
    
    for(int i=1;i<=n-1;i++)cout<<ans[i]<<' ';cout<<endl;

}
signed main(){
    int size(256<<20); //256M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    exit(0);
    return 0;
}