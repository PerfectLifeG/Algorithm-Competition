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
    vector<int>v;
    v.reserve(1000000);
    int n;
    cin>>n;int num=n;
    for (int i = 0; i < n; i++)
    {
        int a;cin>>a;
       v.push_back(a);
    }
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a;int b,c;
        cin>>a>>b;
        if(a==0){
            cin>>c;
            if(b>num)continue;
            v.insert(v.begin()+b,c);
            num++;
            }
        else if(a==1&&b!=0){
            if(b>num)continue;
            v.erase(v.begin()+b-1);
            num--;
        }
    }
    for (auto it:v)
    {
        cout<<it<<" ";
    }
    
    return 0;
}