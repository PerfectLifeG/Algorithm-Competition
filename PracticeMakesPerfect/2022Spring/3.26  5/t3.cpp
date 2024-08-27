#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
using namespace std;
struct node
{
    int x;
    int l;
};
int  cmp(struct node n1,struct node n2){
    return n1.l<n2.l;
}
int  cmp2(struct node n1,struct node n2){
    return n1.l>n2.l;
}
int main()
{   
    
    int n,e;
    
    while(scanf("%d %d",&n,&e)!=EOF){
        int s=0;struct node city[100];
        struct node nd[100];
        for (int i = 0; i < n; i++)city[i].l=0;
        for (int i = 0; i < n; i++)nd[i].l=0;
        for (int i = 0; i < e; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
             nd[a].x=a;
             nd[b].x=b;
            nd[a].l+=c;
            nd[b].l+=c;
            city[a].x=a;
            city[b].x=b;
            city[a].l++;
            city[b].l++;
        }
        sort(city,city+e+1,cmp2);
        sort(nd,nd+e+1,cmp);
        int i=0;int t=1000;int flag;int j=0;
        while (city[i].l==city[0].l)
        {
            while (nd[j].x!=city[i].x)
            {
               j++;
            }
            
            if(nd[j].l<t)
            {
                t=nd[j].l;
                flag=nd[j].x;}
            i++;
            j=0;
        }
        cout<<flag<<endl;
    }
    return 0;
}