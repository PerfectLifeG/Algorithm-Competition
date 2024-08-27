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
    double ans=1;
    for(int i=0;i<3;i++){
        double a,b,c;cin>>a>>b>>c;
        double t=max({a,b,c});
        if(t==a)cout<<"W ";
        else if(t==b)cout<<"T ";
        else if(t==c)cout<<"L ";
        ans*=t;
    }   
    ans=ans*0.65-1;
    cout<<fixed<<setprecision(2)<<ans*2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}