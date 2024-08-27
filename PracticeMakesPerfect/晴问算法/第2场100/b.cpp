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
void solve(){
    int n;cin>>n;
    vector<int>v[n+1];

    for(int i=2;i<=n;i++){
        int fa;cin>>fa;
        v[fa].push_back(i);

    }

    int mx=0;
    function<void(int,int)> dfs=[&](int t,int depth){
        mx=max(mx,depth);
        for(auto j:v[t]){
            dfs(j,depth+1);
        }
    };
    dfs(1,0);
    cout<<2*(n-1)-mx<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}