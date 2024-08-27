#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int book[N];
int ans=1;
vector<vector<PII>>v(N+1);
void dfs(PII t){
    for(int j=0;j<v[t.first].size();j++){
        if(book[v[t.first][j].first])continue;
        book[v[t.first][j].first]=1;
        if(v[t.first][j].second<t.second){cout<<t.first<<' '<<v[t.first][j].first<<endl;ans++;}
        dfs(v[t.first][j]);
    }
}
void solve(){
    memset(book,0,sizeof book);
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    ans=1;book[1]=1;
    dfs({1,0});
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}