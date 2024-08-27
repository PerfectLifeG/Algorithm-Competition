#include<bits/stdc++.h>
using namespace std;
const int N=100;
int f[N][N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;
    int n=s.size();
    memset(f,0x3f,sizeof f);
    for(int len=1;len<=n;len++){
        for(int l=0;l+len-1<n;l++){
            int r=l+len-1;
            if(len==1)f[l][r]=1;
            else if(s[r]==s[r-1])f[l][r]=f[l][r-1];
            else if(s[l]==s[l+1])f[l][r]=f[l+1][r];
            else if(s[r]==s[l])f[l][r]=min(f[l+1][r],f[l][r-1]);
            else for(int k=l;k<r;k++){
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]);
            }
        }
    }
    cout<<f[0][n-1];
    return 0;
}