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
    map<int,int>mp;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]=i;
    }
    int k;cin>>k;
    vector<int>v(n+1);
    v[0]=1e18;
    int pre=0;
    for(auto [val,id]:mp){
        if(id>pre){
            int y=k/(val-a[pre]);
            // cout<<k<<' '<<y<<' '<<val<<' '<<pre<<' '<<a[pre]<<endl;
            if(y>v[pre]){
                y=v[pre];
            }
            if(y>0){
                v[pre]-=y;
                v[id]+=y;
                k-=(val-a[pre])*y;
                pre=id;
            }
        }
    }
    vector<int>ans(n+1);
    int t=0;
    for(int i=n;i>=1;i--){
        t+=v[i];
        ans[i]=t;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}