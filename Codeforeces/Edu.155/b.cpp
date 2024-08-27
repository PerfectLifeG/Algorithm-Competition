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
    int n;cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    int ans=0;
    int mn1=1e18;
    int mn2=1e18;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans+=a[i];
        mn1=min(mn1,a[i]);
    }
    int t=0;
    for(int i=0;i<n;i++){
        cin>>b[i];
        t+=b[i];
        mn2=min(mn2,b[i]);
    }
    cout<<min(mn1*n+t,mn2*n+ans)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}