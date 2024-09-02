#include<bits/stdc++.h>
using namespace std;
vector<int>v[100005];
map<int,int>mp;
int main()
{
    int n,m;cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int k;cin>>k;
        for (int j = 0; j < k; j++)
        {
            int a;cin>>a;
            v[i].push_back(a-1);
        }
    }
    int idx=0;
    for (int i = 0; i < m; i++)
    {
        int a,b;cin>>a>>b;
        if(a==1){
            mp[b]=idx;
            cout<<idx+1<<endl;
        }
        else if(a==0){
            idx=v[idx][b-1];
        }
        else if(a==2){
            idx=mp[b];
        }
    }
    cout<<idx;
    return 0;
}