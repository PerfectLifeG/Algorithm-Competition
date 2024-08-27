#include<stdio.h>
int main()
{
    int t,n,m,s=0;
    scanf("%d",&t);
    for (int f = 0; f < t; f++)
    {
        scanf("%d %d",&n,&m);
        int a[n][m];int (*p)[m]=a;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%c",&a[i][j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(a[i][j]=='*'){
                *(*(p+i-1)+j-1)=0;*(*(p+i-1)+j)=0;*(*(p+i-1)+j+1)=0;
                *(*(p+i)+j-1)=0;*(*(p+i)+j)=0;*(*(p+i)+j+1)=0;
                *(*(p+i+1)+j-1)=0;*(*(p+i+1)+j)=0;*(*(p+i+1)+j+1)=0;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j]=='p')
                {
                    s++;
                }
            }
        }
        printf("%d\n",s);
    }
    return 0;
}