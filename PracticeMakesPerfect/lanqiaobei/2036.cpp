#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=550;
int a[N][N];
int s[N][N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    for(int l=1;l<=m;l++){
        for(int r=l;r<=m;r++){
            for(int i=1,j=1;j<=n;j++){
                while(i<=j && s[j][r]-s[i-1][r]-s[j][l-1]+s[i-1][l-1]>k)i++;
                if(i<=j)cnt+=j-i+1;
            }
        }
    }
    cout<<cnt;
    return 0;
}