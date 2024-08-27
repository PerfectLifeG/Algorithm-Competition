#include<bits/stdc++.h>
using namespace std;
const int N=11;
int n;
int w[N][N];
int f[N][N][2*N];
int main(){
    cin>>n;
    int a,b,c;
    while(cin>>a>>b>>c,a|b|c){
        w[a][b]=c;
    }
    f[1][1][0]=w[1][1];
    for(int s=1;s<=2*n-2;s++){
        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=n;i2++){
                if(i1>s+1||i2>s+1)break;
                if(i1==i2)f[i1][i2][s]=max(max(f[i1][i2][s-1],f[i1][i2-1][s-1]),max(f[i1-1][i2][s-1],f[i1-1][i2-1][s-1]))+w[i1][s-i1+2];
                else f[i1][i2][s]=max(max(f[i1][i2][s-1],f[i1][i2-1][s-1]),max(f[i1-1][i2][s-1],f[i1-1][i2-1][s-1]))+w[i1][s-i1+2]+w[i2][s-i2+2];
            }
        }
    }
    cout<<f[n][n][2*n-2];
    return 0;
}