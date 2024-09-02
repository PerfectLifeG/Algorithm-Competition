#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=201;
const int mod=1000000007;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int f[N][202][102];
void solve(){
    memset(f,0,sizeof f);
    int n,m;
    cin>>n>>m;
    // n=46,m=95;
    // int t=1;
    // while(1<<t<m-t)t++;
    f[0][2][0]=1;
    for(int i=1;i<=n+m;i++){
        for(int j=0;j<=m+1;j++){//第i-1个店 从第i-1个店开始为啥就错。为啥为啥为啥。。。可以的可以的可以的！！！
                for(int p=0;p<=n&&p<=i;p++){//遇到了p次店
                    // if(f[8][10][6]==1){cout<<i<<' '<<j<<' '<<p<<endl;}
                    // if(i==8&&j*2==10&&p==6){
                    //     cout<<i<<' '<<j<<' '<<p<<endl;
                    //     cout<<' '<<f[i-1][j][p-1]<<' '<<f[i][j*2][p]<<endl;
                    // }
                    if(p>=1)f[i][j*2][p]=(f[i][j*2][p]%mod+f[i-1][j][p-1]%mod)%mod;
                    // if(f[8][10][6]==1){cout<<i<<' '<<j<<' '<<p<<endl;return;}
                    // if(i==8&&j*2==10&&p==6){
                    //     cout<<i<<' '<<j<<' '<<p<<endl;
                    //     cout<<' '<<f[i-1][j][p-1]<<' '<<f[i][j*2][p]<<endl;
                    // }
                    
                    if(j>=1&&p<=i-1)f[i][j-1][p]=(f[i][j-1][p]%mod+f[i-1][j][p]%mod)%mod;
                    // if(i==8&&j-1==10&&p==6){
                    //     cout<<i<<' '<<j<<' '<<p<<endl;
                    //     cout<<' '<<f[i-1][j][p]<<' '<<f[i][j*2][p]<<endl;
                    // }
                    // if(f[8][10][6]==1){cout<<i<<' '<<j<<' '<<p<<endl;return;}
            }
        }
    }
    // for(int i=1;i<=30;i++){
    //     for(int j=0;j<=30;j++){//第i-1个店 从第i-1个店开始为啥就错。为啥为啥为啥。。。
    //             for(int p=0;p<=n&&p<=i;p++){//遇到了p次店
    //                 cout<<i<<' '<<j<<' '<<p<<' '<<f[i][j][p]<<endl;
    //             }
    //     }
    // }
    // system("2039.exe > 2039.txt");
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