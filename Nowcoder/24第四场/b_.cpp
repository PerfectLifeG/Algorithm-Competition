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
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int root[N];
int find(int a){
    if(a==root[a]) return a;
    return root[a]=find(root[a]);
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)root[i]=i;
    vector<array<int,3>>q;
    vector<int>v[n+1];
    int r;
    for(int i=0;i<n-1;i++){
        int a,b,c;cin>>a>>b>>c;
        r=c;
        q.push_back({a,b,c});
        v[a].push_back(b);
    }    

    vector<int>dep(n+1);
    function<void(int,int)> dfs=[&](int t,int d){
        dep[t]=d;
        for(auto j:v[t]){
            dfs(j,d+1);
        }
    };
    dfs(r,0);

    vector<int>ans(n+1);
    for(auto [a,b,c]:q){
        int ra=find(a),rb=find(b);
        ans[ra]=max(ans[ra],dep[rb]-dep[ra]+ans[rb]);
        cout<<ans[c]<<' ';
        root[rb]=ra;
    }
    cout<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}