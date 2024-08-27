#include<stdio.h>     \\我去    scanf还tm有返回值！
int main()
{
    int a,b,c[2];
    scanf("%d %d",&a,&b);
    int a1=a,b1=b;
    for (int i = 0; i < 3; i++)
    {
    scanf("%d",&c[i]);
    if(c[i]==0)a++;
    if(c[i]==1)b++;
    }
    if (a>b)
    {
        printf("The winner is a: %d + %d",a1,a-a1);
    }
    if (a<b)
    {
        printf("The winner is b: %d + %d",b1,b-b1);
    }
    
    return 0;
}