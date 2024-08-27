#include<stdio.h>
void prime(long long a);    //注意一点，质因数从小到大顺序输出，如15=3*5所以不用考虑是否5%2==0
long long isprime(long long a);
int main()
{
    long long a;
    scanf("%d",&a);
    printf("%d=",a);
    prime(a);
    return 0;
}

void prime(long long a)
{
    int b=a;
    if(isprime(a)) 
    {   printf("%d",a);    
        return;
    }
    for (int i = 2; i*i <= b; i++)    //未知数不能变
    {
        if(isprime(a)) 
    {   printf("%d",a);
        return;
    }

        int x=0,n=0;
        while (a%i==0)
        {
            n++;
            x=i;
            a/=i;
        }
        if (a>1)   
        {
            if (n>1)
            {
                printf("%d^%d*",x,n);
            }else if(n==1){
                printf("%d*",x);
            }
        }
        else{
            if (n>1)
            {
                printf("%d^%d",x,n);
            }else if(n==1){
                printf("%d",x);
            }    
        }
    }
}

long long isprime(long long a){
    for (int i = 2; i*i <= a ; i++)
    {
        if (a%i==0)  return 0;
    }
    return 1;
}