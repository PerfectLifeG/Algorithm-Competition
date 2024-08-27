#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n;cin>>n;
    vector<vector<int>>v(n+2);
    vector<int>val(n+2);
    vector<int>mx(n+2,-1);
    vector<int>mn(n+2,INF);
    mx[1]=1;mn[1]=1;
    int idx=2;
    vector<array<int,3>>q;
    for(int i=0;i<n;i++){
        char op[2];int a,b,c;
        cin>>op;
        if(*op=='+'){
            cin>>a>>b;
            v[a].push_back(idx);
            val[idx++]=b;
        }else{
            cin>>a>>b>>c;
            q.push_back({a,b,c});
        }
    }

    function<void(int,int)> dfs=[&](int t,int fa){
        for(int i=0;i<v[t].size();i++){
            int j=v[t][i];
            if(j==fa)continue;
            mx[j]=max(val[j]+mx[t],val[j]);
            mn[j]=min(val[j]+mn[t],val[j]);
            dfs(j,t);
        }
    };

    function<void(int,int)> dfs2=[&](int t,int fa){
        for(int i=0;i<v[t].size();i++){
            int j=v[t][i];
            if(j==fa)continue;
            mx[j]=max(mx[j],mx[t]);
            mn[j]=min(mn[j],mn[t]);
            dfs2(j,t);
        }
        mx[t]=max(mx[fa],mx[t]);
        mn[t]=min(mn[fa],mn[t]);
    };
    dfs(1,0);
    // for(int i=1;i<idx;i++)cout<<i<<' '<<mn[i]<<' '<<mx[i]<<endl;
    dfs2(1,0);
    // for(int i=1;i<idx;i++)cout<<i<<' '<<mn[i]<<' '<<mx[i]<<endl;
    for(auto [a,b,c]:q){
        if(c>=mn[b]&&c<=mx[b]||c==0){
            yes;
        }else no;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}