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
    int n,m;cin>>n>>m;
    vector<int>a(n+1);
    vector<int>prea(n+1);
    vector<int>v(m+1);
    vector<int>prev(m+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>v[i];
    sort(all(a));
    sort(all(v));
    for(int i=1;i<=n;i++){
        prea[i]=prea[i-1]+a[i];
    }
    for(int i=1;i<=m;i++){
        prev[i]=prev[i-1]+v[i];
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        int t=n-i;
        // ans=max(ans,(prea[i]-prev[i])+((prev[m]-prev[m-t])-(prea[n]-prea[n-t])));
        ans=max(ans,(prea[n]-prea[n-i])-prev[i]+((prev[m]-prev[m-t])-(prea[t])));
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}