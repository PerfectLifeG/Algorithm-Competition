#include<stdio.h>    //这道题我是天才！！！
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    getchar();
    char b[n];
    int a[m];
    for (int i = 0; i < m; i++)
    {
        a[i]=0;
        for (int j = 0; j < n; j++)
        {
            b[j]=getchar();
            if(b[j]=='y') b[j]='0';
            if(b[j]=='n') b[j]='1';
        }
        for (int j = 0; j < n; j++)
        {
            a[i]*=2;
            a[i]+=b[j]-'0';
        }
        a[i]++;
        getchar();
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d\n",a[i]);
    }
    
    return 0;
}