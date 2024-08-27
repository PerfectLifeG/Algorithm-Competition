#include<stdio.h>
void mycmp(char*p,char*q){
    while (*p++ == *q++ && *(q-1)!='\0'&&*(p-1)!='\0');    //还有一种情况相等且等于'\0'跳出
    printf("%d",*(p-1)-*(q-1));  
}
int main()
{
    char a[]="hell";char b[]="hell";
    mycmp(a,b);
    return 0;
}