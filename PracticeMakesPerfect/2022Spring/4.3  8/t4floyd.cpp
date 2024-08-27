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
int e[10][10];
int main()
{
    int max=999999;
    int n,m;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                e[i][j]=max;
            }
            
        }
        
        for (int i = 0; i < n; i++)
        {
            int a,b;
            cin>>a>>b;
            for (int j = 0; j < b; j++)
            {
                int c;cin>>c;
                e[a][c]=1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(e[i][j]>e[i][k]+e[k][j])
                    e[i][j]=e[i][k]+e[k][j];
                }
                
            }
            
        }
        
        for (int i = 0; i < m; i++)
        {
            int a,b;
            cin>>a>>b;
            if(e[a][b] > 909999)cout<<"connection impossible"<<endl;
            else cout<<e[a][b]<<endl;
        }
    
    }
    return 0;
}