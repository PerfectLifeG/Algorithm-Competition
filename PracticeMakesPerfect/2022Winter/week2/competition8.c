#include<stdio.h>
int main()
{
    int ra,ca,j,i,z,s=0;
    scanf("%d %d",&ra,&ca);
    int a[ra][ca];
    for ( i = 0; i < ra; i++)
    {
        for (j = 0; j < ca-1; j++)
        {
            scanf("%d ",&a[i][j]);
        }
        scanf("%d",&a[i][j]);
    }
    
    int rb,cb;
    scanf("%d %d",&rb,&cb);
    int b[rb][cb];
    for ( i = 0; i < rb; i++)
    {
        for (j = 0; j < cb-1; j++)
        {
            scanf("%d ",&b[i][j]);
        }
        scanf("%d",&b[i][j]);
    }

    

    if(rb==ca){
        printf("%d %d\n",ra,cb);
        for ( i = 0; i < ra; i++)
        {
            for ( j = 0; j < cb; j++)
            {
                for ( z = 0; z < ca; z++)
                {
                    s+=a[i][z]*b[z][j];                    
                }
                if (j==cb-1)
                {
                printf("%d",s);
                }
                else
                printf("%d ",s);
                s=0;
                
            }
            printf("\n");
        }
    }
    else{
        printf("Error: %d != %d",ca,rb);
    }
    return 0;
}