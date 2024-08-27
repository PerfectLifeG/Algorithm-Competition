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
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int book[2][550][550];
void solve(){
    int n,m;cin>>n>>m;
    char g[2][n][m];
    PII st,ed;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            g[0][i][j]=s[j];
            if(s[j]=='S'){
                st={i,j};
            }
        }
    }
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            g[1][i][j]=s[j];
            if(s[j]=='T'){
                ed={i,j};
            }
        }
    }
    queue<array<int,3>>q;
    q.push({0,st.first,st.second});
    book[0][st.first][st.second]=1;
    while(q.size()){
        auto [op,x,y]=q.front();
        q.pop();
        if(g[op][x][y]=='T')break;
        for(int i=0;i<4;i++){
            int tx=x+dir[i][0],ty=y+dir[i][1];
            if(tx<0||ty<0||tx>=n||ty>=m||book[op][tx][ty]||g[op][tx][ty]=='#')continue;
            if(op==0&&g[0][tx][ty]=='@'&&g[1][tx][ty]!='#'){
                book[1][tx][ty]=book[op][x][y]+1;
                q.push({1,tx,ty});
            }
            book[op][tx][ty]=book[op][x][y]+1;
            // cout<<op<<' '<<x<<' '<<y<<' '<<tx<<' '<<ty<<' '<<book[op][x][y]<<' '<<book[op^1][x][y]<<endl;
            q.push({op,tx,ty});
        }
    }
    // cout<<book[0][4][3]<<endl;
    // cout<<book[1][4][3]<<endl;
    // cout<<book[1][3][3]<<endl;
    // cout<<book[1][2][3]<<endl;
    // cout<<book[1][1][3]<<endl;
    // cout<<book[1][1][2]<<endl;
    // cout<<book[1][1][1]<<endl;
    cout<<book[1][ed.first][ed.second]-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}