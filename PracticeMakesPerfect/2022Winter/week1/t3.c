#include<stdio.h>
int main()
{
    char a[11],b[11];
    for (int i = 0; i < 11; i++)
    {
        scanf("%c",&a[i]);
        if(i>=1){
            for (int j=0;j<i;j++)
            {
                if(a[i]==a[j])a[j]='a';
            }           
        }
    }
    int j=0;
    for (int i = 0; i < 10&&a[i]!='a'; i++){
        b[j]=a[i];        
        j++;
    }
    int d=j;
    for (int i = 0; i < d; i++)
    {
        int k=i,t;
       for (int j = i+1; j < d; j++)
       {
           if(a[k]<a[j])k=j;
       }
       t=b[i];
       b[i]=b[k];
       b[k]=t;
    }
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if(a[i]==a[j])a[i]=(char)j;
        }
    }
    
    printf("int[] arr = new int[]{%c",b[0]);
    for (int i = 1; i < d; i++)
    {
        printf(",%d",b[i]);
    }
    printf("};\n");
    printf("int[] index = new int[]{%c",a[0]);
    for (int i = 1; i < 11; i++)
    {
        printf(",%c",a[i]);
    }
    printf("};");
    return 0;
}