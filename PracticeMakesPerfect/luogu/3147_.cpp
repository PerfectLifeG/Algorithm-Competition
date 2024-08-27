#include<bits/stdc++.h>
using namespace std;
const int N=262150;
int f[60][N];
int a[N];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[a[i]][i]=i;
    }
    int ans=0;
    for(int i=2;i<=58;i++){
        for(int j=1;j<=n;j++){
            if(1+f[i-1][j]<=n&&f[i-1][j]&&f[i-1][1+f[i-1][j]])
            f[i][j]=f[i-1][1+f[i-1][j]];//能合并的话就合并
            if(f[i][j])ans=i;
        }
    }

    cout<<ans;
    return 0;
}