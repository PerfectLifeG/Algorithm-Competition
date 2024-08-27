#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    map<int,string>mp;
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        string a;int b;
        cin>>a>>b;
        mp[b]=a;
    }
    int m;cin>>m;
    for (int i = 0; i < m; i++)
    {
        int c;cin>>c;
        if(mp.count(c))cout<<"case"<<i<<":"<<mp[c]<<endl;
        else cout<<"case"<<i<<":no ID!"<<endl;
    }
    
    return 0;
}