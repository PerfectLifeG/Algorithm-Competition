#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=1e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
vector<int>v[N];
int col[N];
int root[N];
int ans;
void merge(int x,int y){
    for(auto i:v[x]){
        if(col[i-1]==y)ans--;
        if(col[i+1]==y)ans--;
    }
    cout<<y<<':'<<endl;
    for(auto i:v[x]){
        cout<<i<<' ';
        col[i]=y;
    }cout<<endl;
    v[y].insert(v[y].end(), v[x].begin(), v[x].end());
    v[x].clear();
}
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>col[i];
        if(col[i]!=col[i-1])ans++;
        v[col[i]].push_back(i);
    }
    while(m--){
        int op;cin>>op;
        if(op==2){
            cout<<ans<<endl;
            continue;
        }
        int x,y;cin>>x>>y;
        if(x==y)continue;
        if(v[root[x]].size()>v[root[y]].size()) swap(root[x],root[y]);
        merge(root[x],root[y]);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    for(int i=0;i<N;i++)root[i]=i;
    while(_--)solve();
    return 0;
}