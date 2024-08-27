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
struct crime
{
    int a;
    int b;
    int q;
}crime[100000];
int bcj[40005];
int cmp(struct crime a,struct crime b){
    return a.q>b.q;
}
int find(int a){
    if(a==bcj[a])return a;
    return bcj[a]=find(bcj[a]);
}
void merge(int a,int b){
    a=find(a);b=find(b);
    bcj[a]=b;
}
int main()
{
    int flag=1;
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= 2*n; i++)bcj[i]=i;
    for (int i = 1; i <= m; i++)
    {
        int a,b,q;
        cin>>a>>b>>q;
        crime[i].a=a;
        crime[i].b=b;
        crime[i].q=q;
    }
    sort(crime+1,crime+1+m,cmp);
    for (int i = 1; i <= m; i++)
    {
        int a=crime[i].a,b=crime[i].b;
        if(find(crime[i].a)==find(crime[i].b)||find(crime[i].a+n)==find(crime[i].b+n)){//因为所有状态都表示了，所以a，与b连的话，a+n与b+n一定连
            flag=0;cout<<crime[i].q;return 0;
        }
        merge(a,b+n);
        merge(b,a+n);
    }
    if(flag)
    printf("0");
    return 0;
}