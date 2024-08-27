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
const int N=1100;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
char g[N][N];
int book[N][N];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int dir1[4][2]={0,1,-1,0,0,-1};
int dir2[4][2]={1,0,-1,0,0,-1};
int dir3[4][2]={1,0,0,1,0,-1};
int dir4[4][2]={1,0,0,1,-1,0};
void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            g[i+1][j+1]=s[j];
        }
    }
    queue<PII>q;
    q.push({1,1});book[1][1]=1;book[n][m]=INF;
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(t.x==n&&t.y==m)break;
        for(int i=0;i<4;i++){
            int tx=t.x+dir[i][0],ty=t.y+dir[i][1];
            if(tx<=0||ty<=0||tx>n||ty>m||book[tx][ty]||g[tx][ty]=='X')continue;
            book[tx][ty]=book[t.x][t.y]+1;
            q.push({tx,ty});
        }
    }
    int ans=book[n][m];

    memset(book,0,sizeof book);book[1][1]=1;book[n][m]=INF;
    while(q.size())q.pop();q.push({1,1});
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(t.x==n&&t.y==m)break;
        for(int i=0;i<3;i++){
            int tx=t.x+dir1[i][0],ty=t.y+dir1[i][1];
            if(tx<=0||ty<=0||tx>n||ty>m||book[tx][ty])continue;
            book[tx][ty]=book[t.x][t.y]+1;
            if(g[tx][ty]!='X')q.push({tx,ty});
        }
    }
    ans=min(ans,book[n][m]);
    while(q.size())q.pop();q.push({n,m});
    book[n][m]=1;
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<3;i++){
            int tx=t.x+dir3[i][0],ty=t.y+dir3[i][1];
            if(tx<=0||ty<=0||tx>n||ty>m)continue;
            if(book[tx][ty]){
                ans=min(ans,book[t.x][t.y]+book[tx][ty]);
            }else if(g[tx][ty]!='X')book[tx][ty]=book[t.x][t.y]+1;
            if(tx!=n&&ty!=m&&g[tx][ty]!='X')q.push({tx,ty});
        }
    }
    // return;

    memset(book,0,sizeof book);book[1][1]=1;book[n][m]=INF;
    while(q.size())q.pop();q.push({1,1});
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(t.x==n&&t.y==m)break;
        for(int i=0;i<3;i++){
            int tx=t.x+dir3[i][0],ty=t.y+dir3[i][1];
            if(tx<=0||ty<=0||tx>n||ty>m||book[tx][ty])continue;
            book[tx][ty]=book[t.x][t.y]+1;
            if(g[tx][ty]!='X')q.push({tx,ty});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<book[i][j]<<' ';
        }cout<<endl;
    }
    ans=min(ans,book[n][m]);
    while(q.size())q.pop();q.push({n,m});
    book[n][m]=1;
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<3;i++){
            int tx=t.x+dir1[i][0],ty=t.y+dir1[i][1];
            if(tx<=0||ty<=0||tx>n||ty>m)continue;
            if(book[tx][ty]){
                // cout<<tx<<' '<<ty<<endl;
                ans=min(ans,book[t.x][t.y]+book[tx][ty]-1);
                continue;
            }
            if(g[tx][ty]!='X'){
                book[tx][ty]=book[t.x][t.y]+1;
                q.push({tx,ty});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<book[i][j]<<' ';
        }cout<<endl;
    }

    memset(book,0,sizeof book);book[1][1]=1;book[n][m]=INF;
    while(q.size())q.pop();q.push({1,1});
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(t.x==n&&t.y==m)break;
        for(int i=0;i<3;i++){
            int tx=t.x+dir2[i][0],ty=t.y+dir2[i][1];
            if(tx<=0||ty<=0||tx>n||ty>m||book[tx][ty])continue;
            book[tx][ty]=book[t.x][t.y]+1;
            if(g[tx][ty]!='X')q.push({tx,ty});
        }
    }
    ans=min(ans,book[n][m]);
    while(q.size())q.pop();q.push({n,m});
    book[n][m]=1;
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(book[t.x][t.y])break;
        for(int i=0;i<3;i++){
            int tx=t.x+dir4[i][0],ty=t.y+dir4[i][1];
            if(tx<=0||ty<=0||tx>n||ty>m)continue;
            if(book[tx][ty]){
                ans=min(ans,book[t.x][t.y]+book[tx][ty]);
            }else if(g[tx][ty]!='X')book[tx][ty]=book[t.x][t.y]+1;
            if(tx!=n&&ty!=m&&g[tx][ty]!='X')q.push({tx,ty});
        }
    }

    memset(book,0,sizeof book);book[1][1]=1;book[n][m]=INF;
    while(q.size())q.pop();q.push({1,1});
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(t.x==n&&t.y==m)break;
        for(int i=0;i<3;i++){
            int tx=t.x+dir4[i][0],ty=t.y+dir4[i][1];
            if(tx<=0||ty<=0||tx>n||ty>m||book[tx][ty])continue;
            book[tx][ty]=book[t.x][t.y]+1;
            if(g[tx][ty]!='X')q.push({tx,ty});
        }
    }
    ans=min(ans,book[n][m]);
    while(q.size())q.pop();q.push({n,m});
    book[n][m]=1;
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(book[t.x][t.y])break;
        for(int i=0;i<3;i++){
            int tx=t.x+dir2[i][0],ty=t.y+dir2[i][1];
            if(tx<=0||ty<=0||tx>n||ty>m)continue;
            if(book[tx][ty]){
                ans=min(ans,book[t.x][t.y]+book[tx][ty]);
            }else if(g[tx][ty]!='X')book[tx][ty]=book[t.x][t.y]+1;
            if(tx!=n&&ty!=m&&g[tx][ty]!='X')q.push({tx,ty});
        }
    }

    if(ans==INF)cout<<-1<<endl;
    else cout<<ans<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}