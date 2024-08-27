#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int a,b,c,m;cin>>a>>b>>c>>m;
    if(m%__gcd(a,b)==0||m%__gcd(c,b)==0||m%__gcd(a,c)==0){
        yes;
    }else if(m%(__gcd(__gcd(a,b),c))==0||m%(__gcd(__gcd(a,c),b))==0||m%(__gcd(__gcd(c,b),a))==0)yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}