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
    int n,k;cin>>n>>k;
    string s;cin>>s;
    map<char,int>mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    int ans=0;
    for(auto [i,j]:mp){
        if(i<='Z'){
            int t=min(mp[i],mp[i-'Z'+'z']);
            ans+=t;
            mp[i]-=t;mp[i-'Z'+'z']-=t;
        }
        int p=min(mp[i]/2,k);
        k-=p;
        ans+=p;
        // cout<<ans<<' '<<i<<' '<<mp[i]<<' '<<k<<endl;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}