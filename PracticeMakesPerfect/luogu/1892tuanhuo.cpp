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
int peo[2005];
int find(int a){
    if(a==peo[a])return a;
    return peo[a]=find(peo[a]);
}
void merge(int a,int b){
    a=find(a);b=find(b);
    peo[b]=a;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int num=0;
    for (int i = 1; i <= n*2; i++)
    {
        peo[i]=i;
    }
    for (int i = 0; i < m; i++)
    {
        char flag;int a,b;
        cin>>flag>>a>>b;
        if(flag=='F')
        {
            merge(a,b);
            //merge(a+n,b+n);
        }
        else if(flag=='E'){
            merge(a,b+n);
            merge(b,a+n);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if(peo[i]==i)num++;
    }
    cout<<num;
    return 0;
}