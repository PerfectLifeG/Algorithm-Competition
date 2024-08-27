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
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int l=0,r=n-1;
    for(;l<n;l++){
        if(v[l]!=v[0])break;
    }
    for(;r>=0;r--){
        if(v[r]!=v[0])break;
    }
    // cout<<r<<' '<<l<<endl;
    int ans=1e9;
    if(r>=l){
        ans=min(ans,r-l+1);
    }else {
        cout<<0<<endl;
        return;
    }

    l=0,r=n-1;
    for(;l<n;l++){
        if(v[l]!=v[n-1])break;
    }
    for(;r>=0;r--){
        if(v[r]!=v[n-1])break;
    }
    if(r>=l){
        ans=min(ans,r-l+1);
    }else {
        cout<<0<<endl;
        return;
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