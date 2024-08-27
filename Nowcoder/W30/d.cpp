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
const int INF=0x3f3f3f3f;
void solve(){
    int x,y,l,r;cin>>x>>y>>l>>r;
    int d=__gcd(x,y);
    x/=d,y/=d;
    int t1=ceil(1.0*l/x);
    int t2=r/x;
    int t11=ceil(1.0*l/y);
    int t22=r/y;
    cout<<min(t22,t2)-max(t11,t1)+1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}