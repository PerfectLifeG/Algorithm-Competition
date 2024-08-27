#include<stdio.h>
struct student
{
    int name;
    int time;
    int w;
};
map<int,int>m;
int main(){
    int n;
    scanf("%d",&n);
    struct student stu[100000];
    struct student* st[100000];
    int time,m;
    for (int i = 0; i < n; i++)
    {   
        scanf("%d %d",&time,&m);
        for (int j = 0; j < m; j++)
        {   int p;
            scanf("%d",&p);
            stu[p].name=p;
            stu[p].time=stu[p].time+time;
            stu[p].w++;
            
        }
    }
    
    
    printf("")
    
    return 0;
}