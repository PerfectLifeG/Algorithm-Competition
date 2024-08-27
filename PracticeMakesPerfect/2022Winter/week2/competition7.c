#include<stdio.h>
int main()
{
    struct people{
        char name[4];
        int breath;
        int maibo;
    };
    int n;
    scanf("%d",&n);
    struct people p[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d",&p[i].name,&p[i].breath,&p[i].maibo);
    }
    
    for (int i = 0; i < n; i++)
    {
        if(p[i].breath>20||p[i].breath<15||p[i].maibo>70||p[i].maibo<50)
        printf("%s\n",&p[i].name);
    }
    
    return 0;
}