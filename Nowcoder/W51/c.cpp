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
void solve(){
    int x,y,t,a,b,c;cin>>x>>y>>t>>a>>b>>c;
    if(x<=t){
        cout<<fixed<<setprecision(10)<<(100-x)*1.0/c;
        return;
    }
    double ans=0;
    ans+=(x-t)*1.0/y;
    ans+=(100-t)*1.0/c;
    double ans2=min((100-x)*1.0/b,(100-x)*1.0/a);
    cout<<fixed<<setprecision(10)<<min(ans,ans2);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}