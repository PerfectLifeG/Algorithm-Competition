#include<bits\stdc++.h>
using namespace std;
/*
    5   
    3

    1    5

    8    4    3

    2    6    7    9

    6    2    3    5    1
*/
int dp[6][6];
int n;
int max(int x,int y){
    if(x>y)return x;
    return y;
}
int maxnode(int i,int j){
    if(i==n) return dp[i][j];
    int x=maxnode(i+1,j);
    int y=maxnode(i+1,j+1);
    return max(x,y)+dp[i][j];
}
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d",&dp[i][j]);
    cout<<maxnode(1,1)<<endl;
    return 0;
}