#include<bits/stdc++.h>
using namespace std;
const int N=2*110;
int a[N];
int s[N];
int f[N][N];
int g[N][N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];s[i+n]=s[i];
    }
    for(int i=1;i<=2*n;i++){
        a[i]=s[i]+a[i-1];
    }
    memset(f,0x3f,sizeof f);    
    memset(g,-1,sizeof g);
    for(int len=1;len<=n;len++){
        for(int l=1;l+len-1<=2*n;l++){
            int r=l+len-1;
            if(len==1)f[l][r]=g[l][r]=0;
            for(int k=l;k<r;k++){
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+a[r]-a[l-1]);
                g[l][r]=max(g[l][r],g[l][k]+g[k+1][r]+a[r]-a[l-1]);
            }
        }
    }
    int mn=0x3f3f3f3f,mx=0;
    for(int i=1;i<=n;i++){
        for(int j=i+n-1;j<=2*n;j++){
            mn=min(mn,f[i][j]);
            mx=max(mx,g[i][j]);
        }
    }
    cout<<mn<<endl;
    cout<<mx;
    return 0;
}