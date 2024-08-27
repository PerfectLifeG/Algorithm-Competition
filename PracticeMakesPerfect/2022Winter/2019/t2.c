#include<stdio.h>
int main()
{
    char a[1000];int s=0,i=0;
    while ((a[i]=getchar())!='\n')
    {
        if (a[i]==' '&&a[i-1]=='6')
        {
            for (int j = i-1;a[j]=='6' ; j--)
            {
                s++;
            }
            if (s>3){
                if (s<=9)
            {
                i=i-s;
                a[i]='9';
            }
            else
            {
                i=i-s;
                a[i]='2';
                i++;
                a[i]='7';
            }
            i++;
            a[i]=' ';
            }
            s=0;
        }
        i++;
    }
    i--;
    for (; a[i] =='6'; i--)
    {
        s++;
    }
    i++;
            if (s>3){
                if (s<=9)
            {
                a[i]='9';
            }
            else
            {
                a[i]='2';
                i++;
                a[i]='7';
            }
            a[i+1]='\n';
            }
            


    i=0;
    while (a[i]!='\n')
    {
        printf("%c",a[i]);
        i++;
    }
    
    
    
    return 0;
}