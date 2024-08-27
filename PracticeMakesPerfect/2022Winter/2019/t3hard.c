#include<stdio.h>
int main()
{
    int n,i=0,s=0,ss=0;
    scanf("%d",&n);
    char *a[n];
    char *p,*q;
    for (int i = 0; i < n; i++)
    {
        p=&a[i];
        p=(char*)malloc(1000*sizeof(char));
        while((*(p++) =getchar())!='\n'){
            if(*p==' ') {q=p;ss++;}
            if ((*p==','||*p=='.')&&*p-1=='g'&&*(p-2)=='n'&&*(p-3)=='o')
            {
                s++;
            }
            if (s==2)
            {

                *q="qiao ben zhong.";
            }else {
                *p=&a[i];
                *p="Skipped";
            }
             
        }
    }
    
    
    
    return 0;
}