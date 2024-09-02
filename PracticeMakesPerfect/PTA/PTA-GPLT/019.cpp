#include<bits/stdc++.h>
using namespace std;
struct Node
{
    string s;
    float num;
};
int main()
{
    int n,m;cin>>n;
    set<string>set;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        set.insert(s);
    }
    cin>>m;Node node[m];
    vector<Node>ans;
    float sum=0;
    for (int i = 0; i < m; i++)
    {
        string s;cin>>s;float a;cin>>a;
        sum+=a;
        if(set.find(s)==set.end()){
            ans.push_back({s,a});
        }
    }
    if(ans.empty()){
        cout<<"Bing Mei You";
        return 0;
    }
    sum=sum*1.0/m;
    vector<string>vv;
    for(auto it:ans){
        if(it.num>sum){
            vv.push_back(it.s);
        }
    }
    if(vv.empty()){
        cout<<"Bing Mei You";
        return 0;
    }
    sort(vv.begin(),vv.end());
    for(auto it:vv){
        cout<<it<<endl;
    }
    return 0;
}