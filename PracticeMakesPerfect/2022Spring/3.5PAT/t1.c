#include<stdio.h>
int main(){
    int n,count=0;
    scanf("%d",&n);
    int a[n];
    int b[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    if (n==1&&a[0]==0) printf("000");
    else{
    for (int i = 0; i < n; i++)
    {
        b[count]=a[i];
        int s=b[count]*10;
        for (int j = 0; j < n; j++)
        {
            b[count]=s+a[j];
            int ss=b[count]*10;
            for (int f = 0; f < n; f++)
            {
                b[count]=ss+a[f];
                count++;
            }
        }
    }
    for (int i = 0; i < count-1; i++)
    {
        int t,k=i;
        for (int j = i+1; j < count; j++)
        {
            if (b[k]>b[j])  
            k=j;
            
        }
        t=b[k];
        b[k]=b[i];
        b[i]=t;
    }
    for (int j = 0; j < count;)
    { 
        printf("%03d",b[j]);
        j++;
        for (int i = 1; i < 10; i++)
        {
            printf(" %03d",b[j]);
            j++;
            if (j==count)
            {
                break;
            }
            
        }
        printf("\n");
    }
    }
    return 0;
}