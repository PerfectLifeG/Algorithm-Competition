#include<bits\stdc++.h>
using namespace std;
int dp[6][6];
int a[6][6];
int n;
int max(int x,int y){
    if(x>y)return x;
    return y;
}
int maxnode(int i,int j){
    for (int i = 1; i <= n; i++)
        dp[n][i]=a[n][i];
    for (int i = n-1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
        }
    }
    return dp[1][1];
}
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d",&a[i][j]);
    cout<<maxnode(1,1)<<endl;
    return 0;
}