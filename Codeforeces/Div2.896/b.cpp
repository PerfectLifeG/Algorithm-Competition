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
    int n,k,a,b;cin>>n>>k>>a>>b;
    vector<int>x(n+1);
    vector<int>y(n+1);
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    int mna=1e18,mnb=1e18;
    for(int i=1;i<=k;i++){
        mna=min(mna,abs(x[i]-x[a])+abs(y[i]-y[a]));
        mnb=min(mnb,abs(x[i]-x[b])+abs(y[i]-y[b]));
    }
    if(a<=k)mna=0;
    if(b<=k)mnb=0;
    cout<<min(mna+mnb,abs(x[b]-x[a])+abs(y[b]-y[a]))<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}