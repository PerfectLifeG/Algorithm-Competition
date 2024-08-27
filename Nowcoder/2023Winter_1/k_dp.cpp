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
const int INF=0x3f3f3f3f;
int f[N][N][4];
void solve(){
    int n,m;cin>>n>>m;
    if(n<=2){cout<<0<<endl;return;}
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<4;k++)
            f[i][j][k]=1e9;
        }
    }
    f[2][0][0]=0;f[2][1][1]=0;f[2][1][2]=0;f[2][2][3]=0;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=min(m,i);j++){
            f[i][j][0]=min(f[i-1][j][0],f[i-1][j][2]);
            f[i][j][1]=min(f[i-1][j-1][2]+1,f[i-1][j-1][0]);
            f[i][j][2]=min(f[i-1][j][3]+1,f[i-1][j][1]);
            f[i][j][3]=min(f[i-1][j-1][1]+1,f[i-1][j-1][3]+1);
        }
    }
    cout<<min({f[n][m][0],f[n][m][1],f[n][m][2],f[n][m][3]})<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}