#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=201,M=1<<7;
const int mod=1000000007;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int f[N][201][101];
void solve(){
    memset(f,0,sizeof f);
    int n,m;cin>>n>>m;
    // int t=1;这出错了，不能用t
    // while(1<<t<n+m-t)t++;
    f[0][2][0]=1;
    for(int i=1;i<=n+m;i++){
        for(int j=0;j<=m+1;j++){//第i-1个店
            for(int k=0;k<2;k++){//第i个店
                for(int p=0;p<=n+m&&p<=i;p++){//遇到了p次店带这次
                    if(k==0&&p>=1)f[i][j*2][p]=f[i-1][j][p-1]%mod;
                    else if(k==1&&j>=1&&p<=i-1)f[i][j-1][p]=(f[i][j-1][p]%mod+f[i-1][j][p]%mod)%mod;
                    // if(i==n+m-1)cout<<j<<' '<<p<<" "<<f[i][j][p]<<endl;
                }
            }
        }
    }
    cout<<f[n+m-1][1][n]%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}