#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int cmp(int a,int b){
    return a>b;
}
stack<int>s;
unordered_map<int,int>smp;
vector<int>sv;
unordered_map<int,int>mp;
vector<int>v;
unordered_map<int,int>mp2;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        s.push(a);
        sv.push_back(a);
    }
    sort(sv.begin(),sv.end(),cmp);
    for(int i=1;i<=sv.size();i++){
        smp.insert({sv[i-1],i});
    }
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        v.push_back(a);
        mp.insert({a,i});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=1;i<=v.size();i++){
        mp2.insert({i,v[i-1]});
    }
    while(s.size()){
        auto idx=smp[s.top()];
        if(s.size()!=1)
        cout<<mp[mp2[idx]]<<' ';
        else cout<<mp[mp2[idx]];
        s.pop();
    }
}