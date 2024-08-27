#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int dir2[4][2]={2,0,-2,0,0,2,0,-2};
int g[7][7];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<PII>v(k);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            g[i][j]=0;
        }
    }
    map<PII,int>mp;
    for(int i=0;i<k;i++){
        int a,b;cin>>a>>b;
        v[i]={a,b};
        g[a][b]=1;
        mp[{a,b}]=i;
    }
    int ans=k;
    vector<int>book(k);
    function<void(int)>dfs=[&](int now){
        // cout<<st<<' '<<now<<endl;
        // if(now==0){
        //     ans=min(ans,st);
        //     return;
        // }
        ans=min(ans,now);
        for(int i=0;i<k;i++){
            if(g[v[i].x][v[i].y]==0)continue;
            // cout<<v[i].x<<'.'<<v[i].y<<' '<<now<<endl;
            auto a=v[i];
            for(int j=0;j<4;j++){
                int tx=v[i].x+dir[j][0],ty=v[i].y+dir[j][1];
                int tx2=v[i].x+dir2[j][0],ty2=v[i].y+dir2[j][1];
                if(tx2<=0||ty2<=0||tx2>n||ty2>m)continue;
                if(g[tx][ty]==0||g[tx2][ty2]==1)continue;
                // book[mp[{tx,ty}]]=1;
                g[v[i].x][v[i].y]=0;
                g[tx][ty]=0;
                g[tx2][ty2]=1;
                v[i]={tx2,ty2};
                // cout<<tx2<<' '<<ty2<<endl;
                dfs(now-1);
                // cout<<"?"<<endl;
                v[i]=a;
                g[v[i].x][v[i].y]=1;
                g[tx][ty]=1;
                g[tx2][ty2]=0;
                // book[mp[{tx,ty}]]=0;
            }
        }
    };
    dfs(k);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}