#include<stdio.h>
void lianxv(int a,int x,int *p,int *q);
int main()
{
    int a,min=0,max=0,t;
    scanf("%d",&a);
    lianxv(a,2,&min,&max);
    for (int i = t-max+1; i <= t; i++)
    {
        printf("%d",i);
    }
    return 0;
}

void lianxv(int a,int x,int *p,int *q){
    int t;int b=a;
    for (int i = x; i*i <= a; i++)
    {
        while (a%i==0)
        {
            (*p)++;
            a/=i;
            if (*p>1)
            {
                t=i;
            }
            i++;
        }
        if (*p>*q) *q=*p;
        *p=0;
    }
    x++;
    lianxv(b,x,p,q);
}