#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n;cin>>n;
    vector<int>son(n+1);
    vector<vector<PII>>v(n+1);
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    vector<int>ans;
    function<void(int,int)> dfs=[&](int t,int fa){
        son[t]=1;
        for(auto j:v[t]){
            if(j.x==fa)continue;
            dfs(j.x,t);
            if(son[j.x]==3)ans.push_back(j.y);
            else son[t]+=son[j.x];
        }
    };
    dfs(1,0);
    if((ans.size()+1)*3!=n){
        cout<<-1<<endl;
        return;
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}