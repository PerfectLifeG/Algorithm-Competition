#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n;
int f[N][N];
int s[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)s[i]+=s[i-1];

    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int l=i,r=i+len-1;
            f[l][r]=1e8;
            for(int k=l;k<=r-1;k++)
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
        }
    }
    printf("%d",f[1][n]);
    return 0;
}