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
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>v[n][2];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(__gcd(a[i],a[j])==1)v[i][0].push_back(j);
            else v[i][1].push_back(j);
        }
    }
    int ans=0;
    function<void(int,int,int)> dfs=[&](int t,int f,int cnt){
        int flag=1;
        for(auto j:v[t][f]){
            dfs(j,f^1,cnt+1);
            flag=0;
        }
        if(flag)ans=max(ans,cnt);
    };
    dfs(0,0,1);
    dfs(0,1,1);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}