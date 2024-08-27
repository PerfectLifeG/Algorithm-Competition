#include<stdio.h>
int main()
{
    static int a[4][4];int b[3],n,m,x,s=0,flag=0;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            scanf("%d",&a[i][j]);
            flag+=a[i][j];
        }
    }

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (a[i][j]==0)
            {
                a[i][j]=45-flag;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d",&n,&m);
        b[i]=a[n][m];
    }
    scanf("%d",&x);
    switch (x)
    {
    case 1:s=a[1][1]+a[1][2]+a[1][3];
        break;
    case 2:s=a[2][1]+a[2][2]+a[2][3];
        break;
    case 3:s=a[3][1]+a[3][2]+a[3][3];
        break;    
    case 4:s=a[1][1]+a[2][1]+a[3][1];
        break;
    case 5:s=a[1][2]+a[2][2]+a[3][2];
        break; 
    case 6:s=a[1][3]+a[2][3]+a[3][3];
        break;       
    case 7:s=a[1][1]+a[2][2]+a[3][3];
        break;
    case 8:s=a[1][3]+a[2][2]+a[3][1];
        break;}

    switch (s)
    {
    case 6:s=10000;break;
    case 7:s=36;break;
    case 8:s=720;break;
    case 9:s=360;break;
    case 10:s=80;break;
    case 11:s=252;break;
    case 12:s=108;break;
    case 13:s=72;break;
    case 14:s=54;break;
    case 15:s=180;break;
    case 16:s=72;break;
    case 17:s=180;break;
    case 18:s=119;break;
    case 19:s=36;break;
    case 20:s=306;break;
    case 21:s=1080;break;
    case 22:s=144;break;
    case 23:s=1800;break;
    case 24:s=3600;break;
    }
        for (int i = 0; i < 3; i++)
        {
            printf("%d\n",b[i]);
        }
        printf("%d",s);
        return 0;
}