#include<stdio.h>
int main()
{
    int a,b,s=0;
    scanf("%d %d",&a,&b);
    for (int i = a,j=1; i <= b; i++,j++)
    {
        printf("%5d",i);
        s+=i;
        if (j==5)
        {
            printf("\n");
            j=0;
        }
        
    }   
    if((b-a+1)%5!=0) printf("\n");   
    printf("Sum = %d",s);    
    return 0;
}