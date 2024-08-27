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
unordered_map<int,int>mp;
void solve(){
    int n,m;cin>>n>>m;
    if(n%m==0&&n>=m){
        cout<<0<<endl;
        return;
    }
    int ta=n,tb=m;
    ta/=__gcd(n,m);
    tb/=__gcd(n,m);
    if(!mp.count(tb)){
        cout<<-1<<endl;
        return;
    }
    if(m%n==0){
        cout<<(m/n-1)*n<<endl;
        return;
    }
    int ans=0;
    if(n>m){
        n=n%m;
    }
    while(m!=n){
        n%=m;
        ans+=n;
        n*=2;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    for(int i=1;i<30;i++){
        mp[1<<i]=1;
    }
    while(_--)solve();
    return 0;
}