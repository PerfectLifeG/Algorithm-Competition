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
    int h,m,a;cin>>h>>m>>a;
    int d=__gcd(h-1,m*h);
    if(m*h==a*2){
        cout<<m*h<<endl;
    }else cout<<d*(a/d+1+m*h/d-(h*m-a+d-1)/d)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}