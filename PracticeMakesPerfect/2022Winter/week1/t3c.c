#include<stdio.h>
#include<stdlib.h>
int main()
{
    static char a[11];int b[10]={};int c[10]={};
    for (int i = 0; i < 11; i++)
    {
        scanf("%c",&a[i]);
        a[i]=a[i]-'0';
        b[(a[i])]++;
    }
    int j=0;
    for (int i = 9; i >= 0; i--)
    {     
        if(b [i]!=0){ 
        c[j]=i;
        j++;}  
    }
    int d=j;
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if(a[i]==c[j]){a[i]=j;break;}
        }
    }
    
    printf("int[] arr = new int[]{%d",c[0]);
    for (int i = 1; i < d; i++)
    {
        printf(",%d",c[i]);
    }
    printf("};\n");
    printf("int[] index = new int[]{%d",a[0]);
    for (int i = 1; i < 11; i++)
    {
        printf(",%d",a[i]);
    }
    printf("};");
    return 0;
}