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
const int INF=0x3f3f3f3f;
void solve(){
    int n,m,h;cin>>n>>m>>h;
    int g[n+1][m+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    int x=1e9,y=1e9;
    int ans=0;
    int f=0;
    int p=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]!=0)continue;
            int t=0;
            for(int k=j-1;k>=0;k--){
                if(g[i][k]>=h)break;
                if(g[i][k]<0){t++;}
            }
            for(int k=j+1;k<m;k++){
                if(g[i][k]>=h)break;
                if(g[i][k]<0){t++;}
            }
            for(int k=i-1;k>=0;k--){
                if(g[k][j]>=h)break;
                if(g[k][j]<0){t++;}
            }
            for(int k=i+1;k<n;k++){
                if(g[k][j]>=h)break;
                if(g[k][j]<0){t++;}
            }
            if(t>=3){
                if(t>p){
                    p=t;
                    x=i,y=j;
                }
                ans++;
            }
        }
    }
    cout<<ans<<endl<<x<<' '<<y<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}