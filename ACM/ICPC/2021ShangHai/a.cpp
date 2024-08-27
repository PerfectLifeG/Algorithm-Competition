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
    if(p*p-4*q*q<0){
        cout<<0<<' '<<0<<endl;
        return;
    }
    int t=p*p-4*q*q;
    int qq=sqrt(t);
    if(t==qq*qq){
        int d=__gcd(p+qq,2*q);
        cout<<(p+qq)/d<<' '<<2*q/d<<endl;
    }else cout<<0<<' '<<0<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}