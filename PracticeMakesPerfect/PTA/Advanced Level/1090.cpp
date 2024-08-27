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
vector<int>v[N];
void solve(){
    int n;cin>>n;
    double p,r;cin>>p>>r;r=0.01*r+1;
    int root;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a==-1)root=i;
        else v[a].push_back(i);
    }
    int cnt=0;
    double ans=0;
    function<void(int,double)> dfs=[&](int t,double now){
        if(ans<now){
            cnt=1;
            ans=now;
        }else if(ans==now)cnt++;
        for(auto j:v[t]){
            dfs(j,now*r);
        }
    };
    dfs(root,p);
    cout<<fixed<<setprecision(2)<<ans<<' '<<cnt<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}