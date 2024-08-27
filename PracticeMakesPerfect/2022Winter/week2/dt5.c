#include<stdio.h>
#include<math.h>
int main()
{
    int a;char b;int flag=0;
    scanf("%d %c",&a,&b);
    int n;
    n=pow((a+1)/2,0.5);
    int c=n;
    for (int i = 0; i < n; i++)
    {   
        for (int z = 0; z < flag; z++)
        {
            printf(" ");
        }   
        for (int j=0; j<2*c-1; j++)
        {
            printf("%c",b);
        }
        printf("\n");
        c--;
        flag++;
    }

    for (int i = 0; i < n-1; i++)
    {   
        for (int z = 0; z < flag-2; z++)
        {
            printf(" ");
        }   
        for (int j=0; j<2*c+3; j++)
        {
            printf("%c",b);
        }
        printf("\n");
        c++;
        flag--;
    }
    printf("%d",a-(2*n*n-1));
    return 0;
}