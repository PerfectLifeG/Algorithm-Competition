#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a;i <= b;i++)
#define lson rt<<1
#define rson rt<<1|1
using namespace std;
typedef long long ll;
#define LL long long
const int maxn=1e5+6;
int a[maxn];
bool f[2][32][maxn];
int pre[2][32][maxn];
LL sum[32][maxn];
const LL mod=1e9+7;
int main(){
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
        }
        for(int i=0;i<32;i++){
            for(int j=1;j<=n;j++){
                if(a[j]&(1<<i))f[0][i][j]=f[1][i][j]=1;
                else f[0][i][j]=f[1][i][j]=0;
            }
            f[0][i][n+1]=f[0][i][0]=0;
            f[1][i][n+1]=f[1][i][0]=0;
        }

        for(int i=0;i<32;i++){
            LL ji=0,ou=0;
            for(int j=1;j<=n;j++){
                if(f[0][i][j]){
                    sum[i][j]=1+ou+sum[i][j-1];
                    swap(ji,ou);
                    ji++;
                }
                else{
                    sum[i][j]=ji+sum[i][j-1];
                    ou++;
                }
            }
        }

        for(int i=0;i<32;i++){
            pre[0][i][0]=pre[1][i][n+1]=0;
            for(int j=1;j<=n;j++){
                f[0][i][j]^=f[0][i][j-1];
                pre[0][i][j]=pre[0][i][j-1]+f[0][i][j];
            }
            for(int j=n;j>=1;j--){
                f[1][i][j]^=f[1][i][j+1];
                pre[1][i][j]=pre[1][i][j+1]+f[1][i][j];
            }
        }
        int l,r;
        l=1,r=n;
        LL ans=0;
        for(int i=0;i<32;i++){
            ans=(ans+(1ll<<i)*sum[i][r])%mod;
        }
        printf("%lld\n",ans);
}