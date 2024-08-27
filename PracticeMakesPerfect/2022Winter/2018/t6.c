#include<stdio.h>
int main()
{
    char c;int n,flag=0,t;
    scanf("%c %d",&c,&n);
    getchar(); 
    char a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c",&a[i][j]);
            
            if(a[i][j]!=' ')a[i][j]=c;
        }  
        getchar();    
    }

    for (int i = 0; i <= n/2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j]!=a[n-1-i][n-1-j])
            {
                flag=1;break;
            }
        }      
    }
    if (flag==1)
    {
        for (int i = 0; i <= n/2; i++)
        {
            for (int j = 0; j < n; j++)
            {   if(i==n/2&&j==n/2)break;
                t=a[i][j];
                a[i][j]=a[n-1-i][n-1-j];
                a[n-1-i][n-1-j]=t;
            }
            
        }
        
    }
    else{
        printf("bu yong dao le\n");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c",a[i][j]);
        }    
        printf("\n");  
    }
    
    return 0;
}