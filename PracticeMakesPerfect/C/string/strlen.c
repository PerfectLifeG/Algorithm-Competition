#include<stdio.h>
void mylen(char*p){
    int i=0;
    while (*p++ !='\0')i++; 
    printf("%d",i);
}
int main()
{
    char a[]="hello";
    mylen(a);
    return 0;
}