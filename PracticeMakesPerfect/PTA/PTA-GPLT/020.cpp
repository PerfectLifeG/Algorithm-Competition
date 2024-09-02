#include<bits/stdc++.h>
using namespace std;
struct Node
{
    vector<double>v;
    double value;
    int con;
    int t;
}node[100005];
double sum,r;
void dfs(int n){
    if(n){
        if(!node[n].v.empty())node[n].value=node[node[n].t].value*0.01*(100.00-r);
        else    {node[n].value=node[node[n].t].value*0.01*(100.00-r)*node[n].con;
                sum+=node[n].value;}
    }
    int len=node[n].v.size();
    for (int i = 0; i < len; i++)
    {
        dfs(node[n].v[i]);
    }
}
int main()
{
    int n;double z;cin>>n>>z>>r;
    node[0].value=z;
    for (int i = 0; i < n; i++)
    {
        int num;cin>>num;
        if(num==0){int a;cin>>a;
        node[i].con=a;}
        while (num)
        {
            int a;cin>>a;
            node[i].v.push_back(a);
            node[a].t=i;
            num--;
        }
    }
    dfs(0);
    if(sum==0)sum+=node[0].value*node[0].con;
    printf("%d",(int)sum);
    return 0;
}