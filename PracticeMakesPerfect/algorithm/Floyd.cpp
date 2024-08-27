#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
int e[10][10]={
    {1,1,1,1,1},
    {1,0,2,5,4},
    {1,9,0,3,4},
    {1,6,8,0,1},
    {1,5,7,10,0}
};
int main()
{
    int n=4;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(e[i][j]>e[i][k]+e[k][j])
                e[i][j]=e[i][k]+e[k][j];
            }   
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ",e[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}