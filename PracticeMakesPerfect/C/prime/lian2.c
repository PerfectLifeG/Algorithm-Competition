#include<stdio.h>
int prime(int a);
int main()
{
    int a,s=1,len=0,max=0;
    scanf("%d",&a);
    if(prime(a)){
        printf("1\n%d",a);
        return 0;
    }
    for (int i = 2; i*i <= a; i++)//平方是判断有无因子的次数    因为要把a分解成因子乘积所以判断是否有因子   的次数
    {
        s=1;
        for (int j = i; s*j <= a/2; j++)//这里不用s*j的平方是因为它一定有因子
        {
            s=s*j;
            if (a%s==0)
            {
                if (j-i+1>len)
                {
                    max=j;
                    len=j-i+1;
                }
            }else 
                break;
        }
    }
    printf("%d\n%d",len,max-len+1);
    for (int i = max-len+2; i <= max; i++)
    {
        printf("*%d",i);
    }
    

    return 0;
}
int prime(int a){
    for (int i = 2; i*i <= a; i++)
    {
        if (a%i==0)   return 0;        
    }
    return 1;
}