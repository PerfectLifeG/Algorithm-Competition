#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define pb push_back
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N];
void solve(){
    int n; cin>>n;
    map<int,int> mp;
    for(int i=1;i<=n-1;++i){
        cin>>a[i],mp[a[i]-a[i-1]]++;
    }
    vector<int>v;
    for(int i=1;i<=n;++i)if(!mp[i])v.pb(i);
    if(v.size()>2)cout<<"NO\n";
    else if(v.size()==1)cout<<"YES\n";
    else{
        if(v[0]+v[1]>n&&mp[v[0]+v[1]]==1||v[0]+v[1]<=n&&mp[v[0]+v[1]]==2)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}