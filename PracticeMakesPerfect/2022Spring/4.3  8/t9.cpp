#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int a[1000000];
int dp[1000000];
int n;
int max(int x,int y){
    if(x>y)return x;
    return y;
}
int maxnode(int i){
    for (int i = n-3; i >= 0; i--)
    {
        dp[i]=max(dp[i+1],a[i]+dp[i+2]);
    }
    return dp[0];
}
int main()
{
    int i=0;
    while (scanf("%d",&a[i])!=EOF)i++;
    n=i;
    dp[i-1]=a[i-1];
    dp[i-2]=max(a[i-1],a[i-2]);
    cout<<maxnode(0);
    return 0;
}