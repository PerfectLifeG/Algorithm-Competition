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
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans=0;
    for(int j=0;j<21;j++){
        int c0=0,c1=0;
        for(int i=0;i<n;i++){
            if((v[i]>>j)&1)ans+=(1ll<<j)*c0%mod*(n-i)%mod,c1+=(i+1);
            else ans+=(1ll<<j)*c1%mod*(n-i)%mod,c0+=(i+1);
            ans%=mod;
        }
    }
    ans=ans*2%mod;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}