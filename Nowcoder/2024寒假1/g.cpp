#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<PII>v;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    sort(all(v),[&](PII a,PII b){
        return a.x<b.x;
    });
    // for(auto [a,b]:v)cout<<a<<' '<<b<<endl;
    int ans=m;
    int she=0;
    int mx=m;
    for(auto [a,b]:v){
        if(ans>=a){
            if(she<=b){
                mx=max(ans+b-she,mx);
                ans=mx;
                she=0;
            }else{
                she-=b;
            }
        }else{
            she+=a-ans;
            if(she<=b){
                mx=max(a+b-she,mx);
                ans=mx;
                she=0;
            }else {
                she-=b;
                ans=a;
            }
            // cout<<she<<' '<<ans<<' '<<mx<<endl;
        }
    }
    cout<<mx<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}