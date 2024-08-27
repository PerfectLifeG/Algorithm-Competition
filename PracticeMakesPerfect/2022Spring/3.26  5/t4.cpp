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
int bang[2005];
int find(int a){
    if(a==bang[a])return a;
    return bang[a]=find(bang[a]);
}
void merge(int a,int b){
    a=find(a);b=find(b);
    bang[b]=a;
}
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    int num=0;
    for (int i = 0; i < n; i++)
    {
        bang[i]=i;
    }
    
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        merge(a,b);
    }

    for (int i = 1; i <= n; i++)
    {
        if(bang[i]==i)num++;
    }
    int a,b;
    cin>>a>>b;
    if(find(a)==find(b))cout<<"In the same gang."<<endl;
    else cout<<"In different gangs."<<endl;
    cout<<num;
    return 0;
}