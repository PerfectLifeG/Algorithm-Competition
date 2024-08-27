#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin()+1,x.end()
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
    int n,k,x;cin>>n>>k>>x;
    vector<int>a(n+1);
    vector<int>s(n+1);
    for(int i=1;i<=n;i++){cin>>a[i];}
    x=min(x,n);
    k=min(k,n);
    sort(all(a),greater<int>());
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=s[x]*(-1)+s[n]-s[x];
    for(int i=1;i<=k;i++){
        int t=i+x;
        ans=max(ans,(s[min(n,t)]-s[i])*(-1)+s[n]-s[min(n,t)]);
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