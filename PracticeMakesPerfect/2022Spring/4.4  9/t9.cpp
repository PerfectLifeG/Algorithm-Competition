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
    for (int i = 1; i <= n; i++)
    {
        peo[i]=i;
    }
    for (int i = 0; i < n; i++)
    {
        int a,b;
        merge(a,b);
    }
    int k;cin>>k;
    for (int i = 0; i < k; i++)
    {
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b))printf("1\n");
        else printf("0\n");
    }
    
    return 0;
}