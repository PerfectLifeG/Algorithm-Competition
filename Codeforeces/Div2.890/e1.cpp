#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n;cin>>n;
    vector<int>v[n+1];
    for(int i=2;i<=n;i++){
        int a;cin>>a;
        v[a].push_back(i);
    }
    vector<int>son(n+1);
    vector<int>ob[n+1];
    int ans=0;

    function<int(int)> dfs=[&](int t) -> long long{
        if(v[t].size()==0)return 1;

        vector<int>ob;
        for(int i=0;i<v[t].size();i++){
            int j=v[t][i];
            int a=dfs(j);
            son[t]+=a;
            ob.push_back(a);
        }
        int a=son[t]/2;
        vector<int>f(a+1);
        for(auto i:ob){
            for(int j=son[t]/2;j>=i;j--){
                f[j]=max(f[j],f[j-i]+i);
            }
        }
        ans+=f[a]*(son[t]-f[a]);
        return son[t]+1;
    };

    dfs(1);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}