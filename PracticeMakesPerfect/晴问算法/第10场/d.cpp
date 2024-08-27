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
char g[30][30];
vector<vector<int>>book(30,vector<int>(30));
vector<vector<int>>book2(30,vector<int>(30));
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int n,m;
int ans=0;
// int p=0;
string s;
// void dfs2(int t,int x,int y){
//     if(x<0||y<0||x>=n||y>=m||book2[x][y])return;
//     book2[x][y]=1;
//     // p++;
//     for(int i=0;i<4;i++){
//         int tx=x+dir[i][0],ty=y+dir[i][1];
//         if(tx<0||ty<0||tx>=n||ty>=m||book2[tx][ty])continue;
//         dfs2(t+1,tx,ty);
//     }
// }
void dfs(int t,int x,int y,int cnt){
    // cout<<x<<' '<<y<<' '<<cnt<<endl;
    if(x<0||y<0||x>=n||y>=m||book[x][y])return;
    if(t==n*m-1){
        if(x==n-1&&y==0&&cnt==n*m)ans++;
        return;
    }
    if(x==n-1&&y==0){
        if(t==n*m-1&&cnt==n*m)ans++;
        return;
    }

    if (book2[x - 1][y] && book2[x + 1][y] && !book2[x][y - 1] && !book2[x][y + 1]) {
        return;
    }
    if (book2[x][y - 1] && book2[x][y + 1] && !book2[x - 1][y] && !book2[x + 1][y]) {
        return;
    }

    // book2=book;
    // // p=0;
    // dfs2(t,x,y);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(!book2[i][j]){
    //             return;
    //         }
    //     }
    // }
    // cout<<cnt<<' '<<p<<endl;
    // if(cnt+p-1!=n*m)return;

    book[x][y]=1;
    if(s[t]=='.'){
        for(int i=0;i<4;i++){
            int tx=x+dir[i][0],ty=y+dir[i][1];
            if(tx<0||ty<0||tx>=n||ty>=m||book[tx][ty])continue;
            dfs(t+1,tx,ty,cnt+1);
        }
    }else if(s[t]=='R'){
        dfs(t+1,x,y+1,cnt+1);
    }else if(s[t]=='L'){
        dfs(t+1,x,y-1,cnt+1);
    }else if(s[t]=='U'){
        dfs(t+1,x-1,y,cnt+1);
    }else dfs(t+1,x+1,y,cnt+1);
    book[x][y]=0;
}
void solve(){
    cin>>n>>m;
    cin>>s;
    dfs(0,0,0,1);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}