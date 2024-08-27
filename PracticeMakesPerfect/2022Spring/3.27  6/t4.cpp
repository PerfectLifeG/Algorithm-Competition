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
    int  n;
    cin>>n;
    vector<int>v;
    for (int i = 0; i < n; i++)
    {
        int a;cin>>a;
        v.push_back(a);
    }
    
    sort(v.begin(),v.end());
    auto it=v.begin();
    for(;it!=v.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}