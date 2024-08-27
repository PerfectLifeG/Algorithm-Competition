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
int dir[8][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
void solve(){
    int n,m;cin>>n>>m;
    char g[n][m];
    char ans[n][m];
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            g[i][j]=s[j];
            if(g[i][j]=='H'){   
                for(int k=0;k<8;k++){
                    int tx=dir[k][0]+i,ty=dir[k][1]+j;
                    if(tx<0||ty<0||tx>=n||ty>=m)continue;
                    ans[tx][ty]='*';
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ans[i][j]!='*')
            ans[i][j]=g[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='L'){
                int cnt=0;
                for(int k=0;k<8;k++){
                    int tx=dir[k][0]+i,ty=dir[k][1]+j;
                    if(tx<0||ty<0||tx>=n||ty>=m)continue;
                    if(g[tx][ty]=='L')cnt++;
                    if(g[tx][ty]=='G'&&ans[tx][ty]!='*')ans[tx][ty]='N';
                    // cout<<tx<<' '<<ty<<' '<<ans[tx][ty]<<endl;
                }
                if(cnt==8)ans[i][j]='S';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ans[i][j]=='*')ans[i][j]=g[i][j];
        else if(ans[i][j]!='N'&&g[i][j]=='G')ans[i][j]='B';
            cout<<ans[i][j];
        }cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}