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
int ksm(int a,int n){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}
void solve(){
    int n,m;cin>>n>>m;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    unordered_map<int,int>mp;
    for(int i=2;i<=n/i;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            mp[i]=cnt;
        }
    }
    if(n>1){
        mp[n]=1;
    }
    int ans=1ll;
    for(auto [i,j]:mp){
        int t=(ksm(1+j,m)-ksm(j,m)+mod)%mod;
        ans*=t;ans%=mod;
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