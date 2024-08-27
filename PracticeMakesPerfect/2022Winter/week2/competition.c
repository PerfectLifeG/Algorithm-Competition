#include<stdio.h>
#include<string.h>
int main()
{
    int k,j=1;char a[10000][8];char (*p)[8]=a;
    scanf("%d",&k);
    while (1)
    {
       scanf("%s",p);
       if(strcmp(*p,"End")==0)break;
       p++;
       j++;
    }
    p=a;
    for (int i = 1; i < j; i++)
    {   if(i%(k+1)==0){
        if(strcmp(*p,"JianDao")==0)printf("JianDao\n");
        if(strcmp(*p,"ChuiZi")==0)printf("ChuiZi\n");
        if(strcmp(*p,"Bu")==0)printf("Bu\n");
    }
        else{
        if(strcmp(*p,"Bu")==0)printf("JianDao\n");
        if(strcmp(*p,"JianDao")==0)printf("ChuiZi\n");
        if(strcmp(*p,"ChuiZi")==0)printf("Bu\n");
        }
        p++;
    }
    
    return 0;
}