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
unordered_map<int,int>mp;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];mx=max(mx,a[i]);
        mp[a[i]]++;
    }
    int b=sqrt(mx);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=(mp[a[i]]-1)*(mp[a[i]]-2);
        for(int j=2;a[i]*j*j<=mx;j++){
            ans+=mp[a[i]*j]*mp[a[i]*j*j];
        }
    }
    for(int i=0;i<n;i++){
        mp[a[i]]--;
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