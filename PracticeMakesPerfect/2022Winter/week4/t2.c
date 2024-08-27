#include<stdio.h>
int main()
{
    int n,a,b,c,j,digit=0,cnt=0;
    scanf("%d %d %d %d",&n,&a,&b,&c);
    for (int i = 0; i <= n; i++)
    {
        j=i;
        if (j==0) digit++;
        while(j!=0)
        {
            digit++;
            j/=10;
        }
    }
    for (int i = a; i <= b; i++)
    {
        int j=i;
        while(1){
            int x=j%10;
            if (x==c)
            {
                cnt++;
            }
            j/=10;
            if (j==0)
            {
                break;
            }
        }
    }
    
    printf("%d %d",digit,cnt);
    
    return 0;
}