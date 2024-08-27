#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
using namespace std;
int bang[200005];
int find(int a){
    int t=a,tt=bang[a];
    while (bang[a]!=a)
    a=bang[a];

    while(t!=a){
        tt=a;
        t=bang[t];
        tt=bang[t];
    }
    return a;
}
void merge(int a,int b){
    a=find(a);b=find(b);
    bang[a]=b;
}

int main()
{   
    int p;
    scanf("%d",&p);
    for (int j = 0; j < p; j++)
    {        
        int n,k;
        scanf("%d %d",&n,&k);
        for (int i = 1; i <= 2*n; i++)bang[i]=i;
        for (int i = 0; i < k; i++)
        {
            char f;int a,b;
            cin>>f>>a>>b;
            if(f=='A'){
                int x=find(a);int y=find(b);
                if(x==y)            printf("In the same gang.\n");
                else if(x==find(b+n))     printf("In different gangs.\n");
                else printf("Not sure yet.\n");
            }
            else if(f=='D'){
                merge(a,b+n);
                merge(b,a+n);
            }
        }
    }
    return 0;
}