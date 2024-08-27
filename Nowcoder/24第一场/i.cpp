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
const int N=1010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;

//上1  左2 下3 右4
// -   /   |   \

int n,m;
int g[N][N];
int book[N][N][5];
int ans[N][N][5];
int Dir[5][2]={0,0,-1,0,0,-1,1,0,0,1};
int nx[5][5]={
    0,0,0,0,0,
    0,3,4,1,2,
    0,2,3,4,1,
    0,1,2,3,4,
    0,4,1,2,3,
};
set<PII>st;
void dfs(int x,int y,int dir){
    if(x<=0||y<=0||x>n||y>m)return;
    if(book[x][y][dir])return;
    book[x][y][dir]++;
    int ndir=nx[dir][g[x][y]];
    if(dir!=ndir)st.insert({x,y});

    int tx=x+Dir[ndir][0],ty=y+Dir[ndir][1];
    dfs(tx,ty,ndir);
    book[x][y][dir]=0;

    ans[x][y][dir]=st.size();
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=1;j<=m;j++){
            if(s[j-1]=='-')g[i][j]=1;
            if(s[j-1]=='|')g[i][j]=3;
            if(s[j-1]=='/')g[i][j]=2;
            if(s[j-1]=='\\')g[i][j]=4;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        st.clear();
        dfs (i, 1, 4);
        st.clear();
        dfs (i, m, 2);
    }
    for (int j = 1; j <= m; j++)
    {
        st.clear();
        dfs (1, j, 3);
        st.clear();
        dfs (n, j, 1);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=4;k++){
                if(!ans[i][j][k]){
                    st.clear();
                    dfs(i,j,k);
                }
            }
        }
    }

    int q;cin>>q;
    while(q--){
        int x,y;cin>>x>>y;
        string s;cin>>s;
        int dir;
        if(s=="above")dir=1;
        if(s=="below")dir=3;
        if(s=="left")dir=2;
        if(s=="right")dir=4;
        x+=Dir[dir][0],y+=Dir[dir][1];
        cout<<ans[x][y][dir]<<endl;
    }


}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}