#include<bits/stdc++.h>
using namespace std;
struct game
{
    vector<int>v;
};

int main()
{
    int n,m;
    cin>>n>>m;
    struct game g[n+1];
    for (int i = 1; i <= n; i++)
    {
        int a;cin>>a;
        for (int j = 0; j < a; j++)
        {
            int b;cin>>b;
            g[i].v.push_back(b);
        }
    }
    int v[10];int flag=1;
    for (int i = 0; i < m; i++)
    {
        int a,b;cin>>a>>b;
        
        if(a==1){
            v[b]=flag;
            cout<<flag<<endl;
        }
        if(a==0)
        flag=g[flag].v[b-1];
        if(a==2)
        flag=v[b];
    }
    cout<<flag;
    return 0;
}