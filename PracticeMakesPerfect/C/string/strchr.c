#include<stdio.h>
#include<string.h>
int main()
{
    char a[]="hello";
    char*p=strstr(a,"e");
    printf("%s",p);
    return 0;
}