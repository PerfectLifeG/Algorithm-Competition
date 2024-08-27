#include<stdio.h>
#include<stdlib.h>
int inc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
 } 
int main()
{
    struct people{
        char name[9];
        int cnt;
        int *a;
    };
    int n,i,j;
    scanf("%d",&n);
    struct people p[n];
    for ( i = 0; i < n; i++)
    {
        scanf("%s %d",&p[i].name,&p[i].cnt);
        p[i].a=(int*)malloc(p[i].cnt*sizeof(int));
        for ( j = 0; j < p[i].cnt; j++)
        {
            scanf(" %d",&p[i].a[j]);
        }

        for ( j = 0; j < p[i].cnt; j++)
        {
            scanf(" %d",&p[i].a[j]);
        }
        qsort(&p[i].a[0], p[i].cnt , sizeof(int), inc);
        p[i].a[0]=p[i].a[p[i].cnt]-p[i].a[0];
    }
    for ( i = 0; i < 3; i++)
    {
        printf("%s",&p[i].name);
    }
    return 0;
}


//101 102 103 104 105 106 107 108 108 107 107  这个怎么处理     排序