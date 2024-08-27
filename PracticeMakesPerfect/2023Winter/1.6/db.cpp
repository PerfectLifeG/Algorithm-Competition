#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int f[a+1][b+1];
    int i;
    int j;
    for(i=0;i<100;i++)f[i][0]=f[0][i]=0;
    f[1][1]=0;
    for(i=2;i<=100;i++)f[i][1]=f[1][i]=1;
    for(i=2;i<100;i++)
    {
        for(j=2;j<100;j++)
        {
            f[i][j]=max(1^f[i-1][j-2],1^f[i-2][j-1]);
        }
    }
    for(i=0;i<=50;i++)
    {
        for(j=0;j<=50;j++)
        {
            printf("%d ",f[i][j]);
        }
            puts("");
    }
    system("pause");
}