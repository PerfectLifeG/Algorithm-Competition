#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n/2; i++)
    {
        if (n%i==0)
        {
            printf("%d ",i);
        }
    }
    printf("%d",n);
    return 0;
}