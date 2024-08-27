#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,a,b;cin>>n>>a>>b;
    int ans=0;
    if(b>=a*2){
        cout<<n*3*a<<endl;
        return;
    }
    int mn=min(a,b);
    for(int i=0;i<n;i++){
        unordered_map<char,int>mp;
        string s;cin>>s;
        for(auto j:s)mp[j]++;
        for(auto j:mp){
            ans+=j.second/2*b+j.second%2*mn;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}