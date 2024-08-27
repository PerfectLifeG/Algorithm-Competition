#include<bits/stdc++.h>
using namespace std;
const int N=100;
int ans[N];
int lay[N];
vector<int>v[N];
int mx;
void layer(){
    queue<int>q;
    q.push(1);lay[1]=1;
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(!v[t].size())ans[lay[t]]++;
        mx=max(mx,lay[t]);
        for(int i=0;i<v[t].size();i++){
            lay[v[t][i]]=lay[t]+1;
            q.push(v[t][i]);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int t;cin>>t;
        int k;cin>>k;
        while(k--){
            int a;cin>>a;
            v[t].emplace_back(a);
        }
    }
    layer();
    cout<<ans[1];
    for(int i=2;i<=mx;i++){
        cout<<' '<<ans[i];
    }
    return 0;
}