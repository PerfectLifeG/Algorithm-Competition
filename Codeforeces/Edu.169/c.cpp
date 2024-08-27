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
    int n,k;cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>v;
    sort(all(a),greater<int>());
    for(int i=1;i<a.size();i+=2){
        v.push_back(a[i-1]-a[i]);
    }
    sort(all(v),greater<int>());
    int ans=0;
    if(n&1)ans=a[n-1];
    for(auto i:v){
        if(k==0){ans+=i;continue;}
        if(i>=k){ans+=i-k;k=0;}
        else k-=i;
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