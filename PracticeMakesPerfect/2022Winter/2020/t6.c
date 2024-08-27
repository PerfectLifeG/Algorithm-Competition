#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000];static int s,m,h;
    while(strcmp(a,".")!=0){
        strcpy(a,"");
        gets(a);            //nb
        h++;
        if(strstr(a,"chi1 huo3 guo1"))
        {
            s++;
            if (s==1)
            {
                m=h;
            }
        }
    }
    if (s>0)
    {
        printf("%d\n%d %d",h-1,m,s);
    }else printf("%d\n-_-#",h-1);
    
    
    return 0;
}