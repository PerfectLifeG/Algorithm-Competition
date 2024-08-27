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
const int N=810;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
char g[N][N];
int n,m;
int check(int x,int y){
    if(g[x][y]=='A'){
        g[x+1][y]='B';
        g[x][y+1]='B';
        g[x+1][y+1]='A';
        if(x>=1&&x+1<=n&&y>=1&&y+1<=m) return 1;
    }else{
        g[x+1][y]='A';
        g[x][y+1]='A';
        g[x+1][y+1]='B';
    }
    return 0;
}
void solve(){
    int k;cin>>n>>m>>k;
    int x,y;string s;cin>>x>>y>>s;
    if(k<n+m){no;return;}
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            g[i][j]=s[0];
        }
    }
    int cnt=n+m;
    for(int i=x;i>=1;i--){
        if(cnt==k)break;
        for(int j=y;j>=1;j--){
            if(cnt==k)break;
            if(g[i][j]=='A')g[i-1][j-1]='A';
            else g[i-1][j-1]='B';
            cnt+=check(i-1,j-1);
        }
    }
    for(int i=x;i>=1;i--){
        if(cnt==k)break;
        for(int j=y+1;j<=m;j++){
            if(cnt==k)break;
            cnt+=check(i-1,j-1);
        }
    }
    for(int i=x+1;i<=n;i++){
        if(cnt==k)break;
        for(int j=y;j>=1;j--){
            if(cnt==k)break;
            cnt+=check(i-1,j-1);
        }
    }
    for(int i=x+1;i<=n;i++){
        if(cnt==k)break;
        for(int j=y+1;j<=m;j++){
            if(cnt==k)break;
            cnt+=check(i-1,j-1);
        }
    }


    if(cnt!=k){no;return;}
    yes;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<g[i][j];
        }cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}