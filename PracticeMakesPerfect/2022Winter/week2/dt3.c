#include<stdio.h>
int main()
{
    char a[100];int i=0,s=0;char *p=&a[1];
    while ((a[i]=getchar())!='\n'){
        if (i>=1)
        {
            if(*p!=' '&&*(p-1)==' ')s++;
            p++;
        }      
        i++;
    }
    if(a[0]!=' ') s++;
    printf("%d",s);
    return 0;
}