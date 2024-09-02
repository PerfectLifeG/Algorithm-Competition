#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=201,M=1<<7;
const int mod=1000000007;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int f[N][M][101];
void solve(){
    memset(f,0,sizeof f);
    int n,m;
    // cin>>n>>m;
    n=46,m=95;
    f[0][2][0]=1;
    for(int i=1;i<=n+m;i++){
        for(int j=0;j<=m+1;j++){//第i个店
                for(int p=0;p<=n&&p<=i;p++){//遇到了p次店
                    if(p>=1&&!(j&1))f[i][j][p]=(f[i][j][p]%mod+f[i-1][j/2][p-1]%mod)%mod;//状态是存遇第i个店后的结果，并不是存遇第i个店前的结果                    
                    if(p<=i-1)f[i][j][p]=(f[i][j][p]%mod+f[i-1][j+1][p]%mod)%mod;
            }
        }
    }
    for(int i=1;i<=30;i++){
        for(int j=0;j<=30;j++){//第i-1个店 从第i-1个店开始为啥就错。为啥为啥为啥。。。
                for(int p=0;p<=n&&p<=i;p++){//遇到了p次店
                    cout<<i<<' '<<j<<' '<<p<<' '<<f[i][j][p]<<endl;
                }
        }
    }
    system("2039_.exe > 2039_.txt");  
    cout<<f[n+m-1][1][n]%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;T=1;
    while(T--){
        solve();
    }
    return 0;
}