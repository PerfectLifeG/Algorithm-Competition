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
int main()
{
    vector<int>v;
    int n,m;
    cin>>n>>m;
    queue<int>q;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    
    while (1)
    {
        q.push(m);auto it=v.begin();
        for(;it!=v.end();it++) if(*it==m)break;
        v.erase(it);
        m++;
    }
    
    
    for (int i = 0; ; i++)
    {
        
    }
    


    return 0;
}