#include<stdio.h>
int* a(int n,int m);
int main()
{
    int t,n,m,s=0;
    scanf("%d",&t);
    for (int f = 0; f < t; f++)
    {
        scanf("%d %d",&n,&m);
        int (*p)[m]=a(n,m);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(*(*(p+i)+j)=='*'){
                *(*(p+i-1)+j-1)=0;*(*(p+i-1)+j)=0;*(*(p+i-1)+j+1)=0;
                *(*(p+i)+j-1)=0;*(*(p+i)+j)=0;*(*(p+i)+j+1)=0;
                *(*(p+i+1)+j-1)=0;*(*(p+i+1)+j)=0;*(*(p+i+1)+j+1)=0;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ( *(*(p+i)+j)=='p' )
                {
                    s++;
                }
            }
        printf("%d\n",s);
        }
    }
    return 0;
}
int* a(int n,int m){
    int **p;//int*p是指向int的指针，int**p是指向一级指针的指针
    p = (int**)malloc(sizeof(int*)*n);//malloc动态分配内存定义行
    for(int i = 0;i<4;i++)
    {
    p[i] = (int *)malloc(sizeof(int)*m);//定义列
    }
    for (int i = 0; i < count; i++)
    {
        scanf("%c",**p);
    }
    return &**p;
}