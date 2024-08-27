#include<stdio.h>
int main()
{
    static char a[100000];   //循环次数太多
    gets(a);
    char *p=a;
    while ((*p)!='\0')
    {
        if (*p>='a'&&*p<'z')
        {
            *p=*p+'B'-'a';
        }
        else if (*p>='A'&&*p<'Z')
        {
            *p=*p+'b'-'A';
        }else if(*p=='Z')
        {
            *p='a';
        }else if (*p=='z')
        {
            *p='A';
        }
        p++;
    }
    printf("%s",&a);
    return 0;
}