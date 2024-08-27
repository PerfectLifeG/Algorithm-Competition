#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first`
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int p,q;cin>>p>>q;
    int d=__gcd(p,q);
    p/=d;
    q/=d;
    if(p-2*q<0){
        cout<<0<<' '<<0<<endl;
        return;
    }
    int x1=p+2*q;
    int x2=p-2*q;
    int t1=sqrt(x1),t2=sqrt(x2);
    if(t1*t1!=x1||t2*t2!=x2){
        cout<<0<<' '<<0<<endl;
        return;
    }
    int a=(t1+t2);
    int b=(t1-t2);
    cout<<a<<' '<<b<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}