#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=1000100;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    int g[n][m]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    queue<PII>q;
    q.push({0,0});
    vector<int>v;
    v.push_back(g[0][0]);
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(t.x==n-1&&t.y==m-1){
            break;
        }
        if(t.x==n-1){
            q.push({t.x,t.y+1});
            v.push_back(g[t.x][t.y+1]);
        }else if(t.y==m-1){
            q.push({t.x+1,t.y});
            v.push_back(g[t.x+1][t.y]);
        }
        else if(g[t.x][t.y+1]>g[t.x+1][t.y]){
            q.push({t.x+1,t.y});
            v.push_back(g[t.x+1][t.y]);
        }else if(g[t.x][t.y+1]<g[t.x+1][t.y]){
            v.push_back(g[t.x][t.y+1]);
            q.push({t.x,t.y+1});
        }
    }
    sort(all(v));
    v.push_back(1e18);
    for(int i=0;i<v.size();i++){
        // cout<<i<<' '<<v[i]<<endl;
        if(v[i]!=i){
            cout<<i<<endl;
            return;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}