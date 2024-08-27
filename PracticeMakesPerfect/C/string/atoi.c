#include<stdio.h>
#include<stdlib.h>
int main()
{
    char a[]="123";
    a[0]=atoi(a);
    printf("%d",a[0]);
    return 0;
}