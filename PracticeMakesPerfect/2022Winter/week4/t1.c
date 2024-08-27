#include<stdio.h>
#include<string.h>
typedef struct lll
{
    char* add[5];
    int  n;
    char* next[5];
} link;

int main()
{
    char* l1[5];
    char* l2[5];
    int  a,f1=0,f2=0;
    scanf("%s %s %d",l1,l2,&a);
    link l[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%s %d %s",l[i].add,&l[i].n,l[i].next);
        if ((l[i].next,"-1")==0)
        {    
            int x=1;
            if (x)
            {
                f1=l[i].n;
                x=0;
            }
            f2=l[i].n;
        }
        
    }
    
    if (f1>f2)
    {
        int t;
        t=f1;
        f1=f2;
        f2=t;
    }
    
    for (int i = 1; i <= a; i++)
    {
        
            if ( ((i-1)%2==0 && i!=1) ||i==f1+1)
            {
                for (int j = 0; j < a; j++)
                {
                    if (l[i].n==f2)
                    {
                        printf("%s %d %s\n",l[i].add,l[i].n,l[i].next);
                        f2--;
                        break;
                    }
                }
            }else
            {
            for (int j = 0; j < a; j++)
                {
                    if (l[i].n==i&&i!=f1+1)
                    {
                        printf("%s %d %s\n",l[i].add,l[i].n,l[i].next);
                        break;
                    }
                }
            }
    }
    

    return 0;
}