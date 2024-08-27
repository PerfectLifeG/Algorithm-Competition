#include<stdio.h>
int main()
{
    struct student
    {
        char kh[17];
        int jh;
        int zh;
    };
    int n;scanf("%d",&n);
    struct student students[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d",students[i].kh,&students[i].jh,&students[i].zh);
    }
    int m;scanf("%d",&m);
    int a[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i]==students[j].jh)
            {
                printf("%s %d\n",students[j].kh,students[j].zh);
            }
        }
    }  
    return 0;
}