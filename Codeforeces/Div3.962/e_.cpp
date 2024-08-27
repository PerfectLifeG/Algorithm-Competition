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
const int mod=1e9+7;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    string s;cin>>s;
    int n=s.size();
    vector<int>pre(n+1);
    for(int i=0;i<n;i++){
        pre[i+1]=pre[i]+(s[i]=='1'?1:-1);
    }

    map<int,int>mp;
    int ans=0;
    for(int i=0;i<=n;i++){
        ans+=mp[pre[i]]*(n-i+1)%mod;ans%=mod;
        mp[pre[i]]+=i+1;mp[pre[i]]%=mod;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}