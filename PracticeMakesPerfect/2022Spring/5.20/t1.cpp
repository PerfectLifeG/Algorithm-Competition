#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;int flag=1;
    for (int i = 0; i < m/2; i++)
    {
        int x=2*i+1;
        for (int j = 0; j < m/2; j++)
        {
            int y=2*j+1;
            for (int k = 0; k < m/2; k++)
            {
                int z=2*k+1;
                if(flag==1&&(3.0/n)==(1.0/x+1.0/y+1.0/z)){
                    printf("%d %d %d",x,y,z);
                    flag=0;
                    break;
                }
            }
        }
    }
    if(flag)
    printf("No solution in (3, %d].",m);
    return 0;
}