#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    int t;cin>>t;
    while (t--)
    {
        int r,c;cin>>r>>c;
        int f[105][105]={};
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                cin>>f[i][j];
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++){
                f[i][j]=max(f[i][j]+f[i-1][j],f[i][j]+f[i][j-1]);
            }
        cout<<f[r][c]<<endl;
    }
    return 0;
}