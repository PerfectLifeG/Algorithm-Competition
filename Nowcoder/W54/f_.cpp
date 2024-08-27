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
int g[N][N];
int book[N][N];
int book2[N][N];
int n,m;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    book[1][1]=1;
    book[n][m]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]==-1)continue;
            book[i][j]|=book[i][j-1];
            book[i][j]|=book[i-1][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(g[i][j]==-1)continue;
            book[i][j]|=book[i][j+1];
            book[i][j]|=book[i+1][j];
        }
    }

    book2[1][1]=1;
    book2[n][m]=1;
    for(int i=1;i<=m;i++)book2[1][i]|=book2[1][i-1];
    for(int i=m;i>=1;i--)book2[1][i]|=book2[1][i+1];


    for(int i=2;i<=n-1;i++){
        for(int j=1;j<=m;j++){
            if(book[i-1][j]||book[i][j])book2[i][j]=1;
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(book[i][j]&&g[i][j]>0)ans+=g[i][j];
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