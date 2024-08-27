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
    int q,n;cin>>q>>n;
    vector<int>in;
    vector<int>pre;
    unordered_map<int,int>mp;
    unordered_map<int,int>mp2;
    vector<int>v[n];
    int idx=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(mp.count(a))while(1);
        if(!mp.count(a)){mp2[idx]=a;mp[a]=idx++;}
        in.push_back(a);
    }
    for(int i=0;i<n;i++){
        int a;cin>>a;
        pre.push_back(a);
    }

    function<int(int,int,int)> build=[&](int root,int l,int r)->int{
        if(l>r)return -1;
        int i=l;
        while(i<=r&&pre[root]!=in[i])i++;
        int p=build(root+1,l,i-1);
        if(p!=-1) v[mp[pre[root]]].push_back(p);
        p=build(root+i-l+1,i+1,r);
        if(p!=-1) v[mp[pre[root]]].push_back(p);
        return mp[pre[root]];
    };
    build(0,0,n-1);
    int root=mp[pre[0]];

    vector<int>depth(n);
    vector<vector<int>>f(n,vector<int>(30));
    function<void(int,int)> dfs=[&](int t,int fa){
        depth[t]=depth[fa]+1;
        f[t][0]=fa;
        for(int i=1;(1<<i)<=depth[t];i++){
            f[t][i]=f[f[t][i-1]][i-1];
        }
        for(auto j:v[t]){
            if(j==fa)continue;
            dfs(j,t);
        }
    };
    auto lca=[&](int x,int y){
        if(depth[x]<depth[y])swap(x,y);
        while(depth[x]>depth[y])x=f[x][log2(depth[x]-depth[y])];
        if(x==y)return x;
        for(int j=log2(depth[x]);j>=0;j--){
            if(f[x][j]!=f[y][j]){
                x=f[x][j];
                y=f[y][j];
            }
        }
        return f[x][0];
    };
    dfs(root,0);

    while(q--){
        int x,y;cin>>x>>y;
        if(!mp.count(x)&&!mp.count(y)){
            cout<<"ERROR: "<<x<<" and "<<y<<" are not found."<<endl;
        }else if(!mp.count(x)){
            cout<<"ERROR: "<<x<<" is not found."<<endl;
        }else if(!mp.count(y)){
            cout<<"ERROR: "<<y<<" is not found."<<endl;
        }else {
            int r=mp2[lca(mp[x],mp[y])];
            if(r==x){
                cout<<x<<" is an ancestor of "<<y<<"."<<endl;
            }else if(r==y){
                cout<<y<<" is an ancestor of "<<x<<"."<<endl;
            }else{
                cout<<"LCA of "<<x<<" and "<<y<<" is "<<r<<"."<<endl;
            }
        }
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}