#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int ksm(int a,int n){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}
int inv(int a){
    return ksm(a,mod-2);
}
void solve()
{
    int n,m;cin>>n>>m;
    vector<int>v;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
        mp[a]++;
    }
    sort(all(v));
    v.erase(unique(all(v)),v.end());
    int ans=0;
    int t=1;
    int cnt=0;
    for(int i=0;i<v.size();i++){
        t=t*mp[v[i]]%mod;
        if(m!=1&&i&&v[i]-1>v[i-1]){t=mp[v[i]];cnt=1;continue;}
        cnt++;
        if(cnt==m){
            ans=(ans+t)%mod;
            t=t*inv(mp[v[i-m+1]])%mod;
            cnt--;
        }
    }
    cout<<ans%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}