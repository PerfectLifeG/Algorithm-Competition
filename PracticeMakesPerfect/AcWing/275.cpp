#include<bits/stdc++.h>
using namespace std;
const int N=52;
int n,m;
int w[N][N];
int f[N][N][2*N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a;cin>>a;
            w[i][j]=a;
        }
    }
    for(int s=1;s<=n+m-2;s++){
        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=n;i2++){
                if(i1>s+1||i2>s+1)break;
                if(i1==i2&&s!=n+m-2)continue;
                f[i1][i2][s]=max(max(f[i1][i2][s-1],f[i1][i2-1][s-1]),max(f[i1-1][i2][s-1],f[i1-1][i2-1][s-1]))+w[i1][s-i1+2]+w[i2][s-i2+2];
            }
        }
    }
    cout<<f[n][n][n+m-2];
    return 0;
}