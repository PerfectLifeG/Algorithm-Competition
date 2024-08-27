#include<stdio.h>
int main(){
    int t,n,s=0;
    scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d",&n);
        int a[n],b[n]; 
        for (int j = 0; j < n; j++)
        {  
            scanf("%d",&a[j]);
        }

        for (int i = 0; i < n-1; i++)
        {
                b[i]=a[i+1]-a[i];
        }
        int *p=&b[0],x=0,y=0;
        for (;*p>=0;)
        {
            p++;
        }
        int *q=
        
         
    }
    
    return 0;
}
