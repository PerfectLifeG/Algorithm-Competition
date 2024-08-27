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
    int x=0,n=0;
    if(isprime(a)) 
    {   printf("%d",a);
        return;
    }

    for (int i = 2; i*i <= a; i++)    //等号没加     实际上从i=x开始++就行，因为分解的数从小到大
    {
        while (a%i==0)
        {
            n++;
            x=i;
            a/=i;
        }
        if (a>1)   //判断失误
        {
            if (n>1)
            {
                printf("%d^%d*",x,n);
                prime(a);            
                break;                    //小技巧
            }else if(n==1){
                printf("%d*",x);
                prime(a);
                break;
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
    for (int i = 2; i*i <= a || a==1; i++)
    {
        if (a%i==0)  return 0;
    }
    return 1;
}