#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define ll long long
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        mp[x]++;
    }
    ll ans=0;
    for(auto [x,y]:mp){
        ans+=1ll*y*(y-1)*(y-2);
        if(x>1e6){
            for(int b=2;1ll*b*x<=1e9;b++){
                if(x%b==0&&mp.count(x/b)&&mp.count(x*b))ans+=1ll*y*mp[x/b]*mp[x*b];
            }
        }else{
            for(int b=1;1ll*b*x<=1e9&&b<=x/b;b++){
                if(x%b==0){
                    if(mp.count(x/b)&&mp.count(x*b))
                    if(b!=1)ans+=1ll*y*mp[x/b]*mp[x*b];
                    if(1ll*x/b*x<=1e9&&mp.count(b)&&mp.count(x/b*x))
                    if(b*b!=x)ans+=1ll*y*mp[b]*mp[x/b*x];
                }
            }
        }
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