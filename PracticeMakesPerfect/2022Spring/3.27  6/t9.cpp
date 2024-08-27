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
int peo[1000000];
int find(int a){
    if(a==peo[a])return a;
    return peo[a]=find(peo[a]);
}
void merge(int a,int b){
    a=find(a);b=find(b);
    peo[a]=b;
}
int main()
{
    int t;
    cin>>t;
    
    for (int i = 0; i < t; i++)
    {
        int n,m;
        cin>>n>>m;
        for (int i = 1; i <= n; i++)
        {
            peo[i]=i;
        }
        for (int i = 0; i < m; i++)
        {
            int a,b;
            cin>>a>>b;
            if(find(a)!=find(b))merge(a,b);
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d ",find(i));
        }
        cout<<endl;
    }

    return 0;
}