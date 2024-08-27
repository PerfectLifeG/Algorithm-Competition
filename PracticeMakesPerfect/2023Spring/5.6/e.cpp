#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
int n,m;
int g[N][N];
int book[N][N];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int mx;
void bfs(int a,int b){
    mx=g[a][b];
    book[a][b]=1;
    if(g[a][b]==0)return;
    queue<PII>q;
    q.push({a,b});
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=t.x+dir[i][0],ty=t.y+dir[i][1];
            if(tx<0||ty<0||tx>=n||ty>=m||book[tx][ty]||g[tx][ty]==0)continue;
            book[tx][ty]=1;
            mx+=g[tx][ty];
            q.push({tx,ty});
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            book[i][j]=0;
            cin>>g[i][j];
        }
    }    
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(book[i][j]==0&&g[i][j]){
                mx=0;
                bfs(i,j);
                ans=max(ans,mx);
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}