#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        mp[a]++;
    }   
    int ans=1;
    for(auto i:mp){
        if(i.x==(mp.rbegin()->x))break;
        ans=ans*(i.y+1)%mod;
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