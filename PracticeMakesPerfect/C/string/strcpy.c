#include<stdio.h>
void mycpy(char*p,char*q){
    while (*p++ = *q++);       //更nb的
}
int main()
{
    char a[]="hello";char b[10];
    mycpy(b,a);
    printf("%s",b);
    
    return 0;
}