#include<stdio.h>
void f(int l,int n){
    char a[l];int i,b;
    a[l]='\0';
    for ( i = 0; i < l; i++)
    {   
        b=n%26;
        n/=26;
        a[l-1-i]='z'-b;
        
    } 
    printf("%s",a);
}
int main()
{
    int l,n;
    scanf("%d %d",&l,&n);
    f(l,n-1);           //倒数第 N 个字符串   我艹nm，真想把电脑砸了！
    return 0;
}