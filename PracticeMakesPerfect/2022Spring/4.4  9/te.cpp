#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
struct team
{
    int s;
    char name[100];
};
int cmp(struct team t1,struct team t2){
    if(t1.s!=t2.s)return t1.s>t2.s;
    else return strcmp(t1.name,t2.name);
}
int main()
{
    int  n;
    cin>>n;getchar();
    
    struct team t[n];
    
    for (int i = 0; i < n; i++)
    {
        char a[100];
        int j=0;
        int s1=0,s2=0,s3=0;
        while ((a[j]=getchar())!='\n')j++;
        strcpy(t[i].name,a);
        for (int k = 0; k < 10; k++)
        {
            for (int o = 1; o <= 15; o++)
            {
                int b;
                cin>>b;
                if(o<=8)s1+=b;
                else if(o<15&&o>8)s2+=b;
                else s3+=b;
            }
        }
        if(s1>800){s1+=s2;
        if(s2>400)s1+=s3;
        }
        getchar();
        t[i].s=s1;
    }
    sort(t,t+n,cmp);
    for (int i = 0; i < n; i++)
    {
        int j=0;
        while (t[i].name[j]!='\n')
        {
            printf("%c",t[i].name[j]);
            j++;
        }
        
        printf(" %d\n",t[i].s);
    }
    
    return 0;
}