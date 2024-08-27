#include<bits/stdc++.h>
using namespace std;
int cmp(pair<vector<int>,int> p1,pair<vector<int>,int> p2){
    if(p1.second==p2.second){
        int i=0;
        while(p1.first[i]==p2.first[i]){
            i++;
        }
        return p1.first[i]<p2.first[i];
    }
    return p1.second>p2.second;
}
int main()
{
    int n,m;cin>>n>>m;
    vector<pair<vector<int>,int>>v;
    map<vector<int>,int>mp;
    for (int i = 0; i < n; i++)
    {
        vector<int>t;
        for (int i = 0; i < m; i++)
        {
            int a;cin>>a;
            t.push_back(a);
        }
        mp[t]++;
    }
    cout<<mp.size()<<endl;
    for (auto it:mp)
    {
        v.push_back({it.first,it.second});
    }
    sort(v.begin(),v.end(),cmp);
    for (int i = 0; i < mp.size(); i++)
    {
        cout<<v[i].second;
        for(auto it:v[i].first)
            cout<<" "<<it;
        cout<<endl;
    }
    return 0;
}