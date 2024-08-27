#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *a,*b;
    int c,d;
    a=(char*)malloc(5*sizeof(char));
    b=(char*)malloc(5*sizeof(char));
    scanf("%s %s",a,b);
    for (int i = 0; i < 4; i++)
    {
        if (a[i]<='9'&&a[i]>='0')  
        a[i]=a[i]-'0';
        else {a[0]='?';}
    }   
    if (a[0]!='?')
    {
        a[0]=zheng();
    }
    
    if(a[0]<='9'&&a[0]>='1'&&(a[1]=='\0'||a[1]<='9'&&a[1]>='0')&&(a[2]=='\0'||a[2]<='9'&&a[2]>='0')&&(a[3]=='\0'||a[3]<='9'&&a[3]>='0')){

    } else printf("%c + %c = %c",a[0],b[0]  );
    return 0;
}