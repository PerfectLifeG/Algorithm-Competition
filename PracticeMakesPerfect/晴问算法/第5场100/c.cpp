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
    int n;cin>>n;
    vector<array<int,3>>v;
    v.push_back({0,0,0});
    for(int i=1;i<=n;i++){
        int a,b,c;cin>>a>>b>>c;
        v.push_back({a,b,c});
    }
    sort(all(v),[&](array<int,3> a,array<int,3> b){
        return a[1]<b[1];
    });
    int dp[n+1]={};
    int mx[n+1]={};
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=0,r=i;
        while(l+1!=r){
            int mid=l+r>>1;
            if(v[mid][1]<v[i][0])l=mid;
            else r=mid;
        }
        dp[i]=mx[l]+v[i][2];
        mx[i]=max({mx[i-1],dp[i]});
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}