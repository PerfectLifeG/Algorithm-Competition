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
char g[31][31];
vector<vector<int>>book(31,vector<int>(31));
vector<vector<int>>book2(31,vector<int>(31));
string ans;
int n,m;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int dfs2(int x,int y){
    int sum=1;
    for(int i=0;i<4;i++){
        int tx=x+dir[i][0],ty=y+dir[i][1];
        if(tx<0||ty<0||tx>=n||ty>=m||book2[tx][ty]||g[tx][ty]=='#')continue;
        book2[tx][ty]=1;
        sum+=dfs2(tx,ty);
    }
    return sum;
}
void dfs(int x,int y,string s,int cnt){
    book2=book;
    int t=dfs2(x,y);
    if(cnt+t-1<ans.size())return;
    if(cnt+t-1==ans.size()&&s<ans.substr(0,cnt))return;
    if(cnt>ans.size()){
        ans=s;
    }else if(cnt==ans.size()){
        ans=max(ans,s);
    }
    for(int i=0;i<4;i++){
        int tx=x+dir[i][0],ty=y+dir[i][1];
        if(tx<0||ty<0||tx>=n||ty>=m||book[tx][ty]||g[tx][ty]=='#')continue;
        book[tx][ty]=1;
        dfs(tx,ty,s+g[tx][ty],cnt+1);
        book[tx][ty]=0;
    }
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            g[i][j]=s[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]!='#'){
                book[i][j]=1;
                string t="";
                dfs(i,j,t+g[i][j],1);
                book[i][j]=0;
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}