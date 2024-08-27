#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    char a[n];
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 6; i++)
    {
        char x[6];
        scanf("%c",&x[i]);
        x[i]=x[i]-'0';
        if (i==5&&x[0]+x[1]+x[2]==x[3]+x[4]+x[5])
        {
            a[j]=1;
        }else a[j]=0;
        
    }
    getchar();
    }

    for (int j = 0; j < n; j++)
    {
        if (a[j]==1)
        {
            printf("You are lucky!\n");
        }else printf("Wish you good luck.\n");
        
    }
    return 0;
}