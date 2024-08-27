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
int main()
{
    int n,m;
    cin>>n>>m;
    int  a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }
    for (int j   = 0; j    < m; j    ++)
    {   int i = 0;
        for (; i < n-1; i++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<a[i][j];
        cout<<endl;
    }
    
    return 0;
}