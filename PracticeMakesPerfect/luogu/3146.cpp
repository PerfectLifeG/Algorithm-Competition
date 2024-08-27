#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int a[N];
int f[N][N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int len=1;len<=n;len++)
        for(int l=1;l<=n;l++){
            int r=l+len-1;
            if(len==1)f[l][r]=a[l];
            else for(int k=l;k<r;k++){
                if(f[l][k]==f[k+1][r]){
                    f[l][r]=max(f[l][r],f[l][k]+1);
                }
            }
        }
    int mx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        mx=max(mx,f[i][j]);
    }
    cout<<mx;
    return 0;
}