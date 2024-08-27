#include<bits/stdc++.h>
using namespace std;
const int N=10;
int val[N];
vector<int>v[N];
unordered_map<int,int>mp;
unordered_map<int,int>l;
int mx=1;
void dfs(int t,int layer){
    for(int i=0;i<v[t].size();i++){
        mx=max(mx,layer+1);
        dfs(v[t][i],layer+1);
    }
    l[layer]++;
}
int main(){
    int n;cin>>n;
    for(int i=2;i<=n;i++){
        int a;cin>>a;
        v[a].push_back(i);
    }
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    sort(val+1,val+n+1);
    dfs(1,1);
    int s=0;
    int idx=1;
    for(int i=1;i<=mx;i++){
        for(int j=0;j<l[i];j++,idx++)
            s+=i*val[idx];
    }
    cout<<s;
    return 0;
}