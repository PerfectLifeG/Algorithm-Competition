#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int a1,a2,n;
    scanf("%d %d %d",&a1,&a2,&n);
    int a[10000];
    a[0]=a1;a[1]=a2;
    int i=2,j=0;
    while (i!=n)
    {
        a[i]=a[j]*a[j+1]/10;
        if (a[i]==0)
        {
            a[i]=a[j]*a[j+1]%10;
        }else{
        a[i+1]=a[j]*a[j+1]%10;
        i++;
        }
        i++;
        if (i>n)
        {
            break;
        }
        
        j++;
    }
    printf("%d",a[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" %d",a[i]);
    }
    return 0;
}