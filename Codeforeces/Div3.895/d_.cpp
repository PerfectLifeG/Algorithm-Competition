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
    int n,x,y;cin>>n>>x>>y;
    int a=n/x;
    int b=n/y;
    int t=x*y/__gcd(x,y);
    int c=n/t;
    a-=c;b-=c;
    int ans=0;
    ans+=(n+n-a+1)*a/2;
    ans-=(1+b)*b/2;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}