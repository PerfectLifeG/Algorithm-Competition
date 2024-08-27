#include<bits/stdc++.h>
using namespace std;
struct student
{
    int name;
    int time;
    int w=0;
};
int main(){
    int n;
    scanf("%d",&n);
    map<int,int>ma;
    map<int,int>::iterator p=ma.begin();
    struct student stu[10000];
    struct student* st[10000];
    int time,m;

    for (int i = 0; i < n; i++)
    {   scanf("%d %d",&time,&m);
        for (int j = 0; j < m; j++)
        {   int o;
            scanf("%d",&o);
            stu[o].name=o;
            stu[o].time=stu[o].time+time;
            stu[o].w++;
            ma.insert(pair<int,int>(stu[o].w,o));
            if(p != ma.end())
            {
                ma.find(stu[o].w);
                if(){
                    p->first=;
                }
            else 
            ma.insert(pair<int,int>(stu[o].w,o));
            p++;
            }
            
        }

        if(p != ma.end())
        {
            ma[]++;
            p++;
        }
        else ma.insert(pair<int,int>(stu[p].w,1));
    }
    
    return 0;
}