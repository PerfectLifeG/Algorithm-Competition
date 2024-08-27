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
int  cmp1(int a,int b){
    return a<b;
}
int  cmp2(int a,int b){
    return a>b;
}
int main()
{
    int n,k,m;int s=0;
    while (cin>>n>>k>>m)
    {   vector<int>v;
        int i = 0;
        for (; i < n; i++)
        {
            int a;cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end(),cmp2);
        printf("%d.00",v[0]+k);
    }
    
    return 0;
}