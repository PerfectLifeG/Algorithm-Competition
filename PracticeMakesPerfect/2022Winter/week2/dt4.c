#include<stdio.h>
char* py(int a);
struct people
{
    char name[3];
    int arrival;
    int time;
};

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[m];
    char *p[m];  
    struct people persons[n];
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&a[i]);
        p[i]=py(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d",persons[i].name,persons[i].arrival,persons[i].time);
    }
    

    return 0;
}

char* py(int a){
    for (int i = 0; i < a; i++)
    {
        
    }
    
}