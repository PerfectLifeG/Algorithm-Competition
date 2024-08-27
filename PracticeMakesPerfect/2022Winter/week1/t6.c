#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    char *p[n];
    for (int i = 0; i < n; i++)
    {       
        p[i]=(char*)malloc(10*sizeof(char));
        scanf("%d %s",a[i],p[i]);
    }
    for (int i = 0,j=n; i < n/2; i++,j--)
    {
        if(a[i]==1){
            for (int j = n-1; j >=n/2; j--)
            {
                
            }
            
        }
        
    }
    
    return 0;
}