#include<stdio.h>
struct people
{
    char name[8];
    int n;
};

int main()
{
    int a;
    float s=0;
    scanf("%d",&a);
    int b[a];
    struct people friends[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%s %d",&friends[i].name,&friends[i].n);
        b[i]=friends[i].n;
        s+=friends[i].n;
    }
    s=s/a/2;
    for (int i = 0; i < a; i++)
    {
        friends[i].n=friends[i].n - s;
        if (friends[i].n<0)
        friends[i].n=-friends[i].n;
    }
        int k=0;
        for (int j = 1; j < a; j++)
        {
            if(friends[k].n>friends[j].n)k=j;
        }
    
    printf("%.0f %s",s,&friends[k].name);
    return 0;
}