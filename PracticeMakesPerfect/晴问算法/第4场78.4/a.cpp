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
    int n,m;cin>>n>>m;
    int x,y;cin>>x>>y;
    char g[n+1][m+1]={};
    g[x][y]='%';
    int j=0;
    for(int i=x-1;i>=1;i--){
        j++;
        if(y-j>=1)g[i][y-j]='%';
        if(y+j<=m)g[i][y+j]='%';
    }
    j=0;
    for(int i=x+1;i<=n;i++){
        j++;
        if(y-j>=1)g[i][y-j]='%';
        if(y+j<=m)g[i][y+j]='%';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]!='%')cout<<'#';
            else cout<<'%';
        }cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}