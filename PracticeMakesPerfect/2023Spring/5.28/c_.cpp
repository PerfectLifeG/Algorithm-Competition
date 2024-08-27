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
void solve(){
    memset(book,0,sizeof book);
    int ans=1;
    int n;cin>>n;
    vector<vector<PII>>v(n+1);
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    queue<PII>q;
    q.push({1,0});
    while(q.size()){
        auto t=q.front();
        q.pop();
        book[t.first]=1;
        for(int j=0;j<v[t.first].size();j++){
            if(book[t.first])continue;
            book[v[t.first][j].first]=1;
            if(!book[t.first]&&v[t.first][j].second<t.second){
                ans++;
                book[t.first]=1;
            }
            cout<<t.first<<' '<<v[t.first][j].first<<endl;
            q.push(v[t.first][j]);
        }
    }
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