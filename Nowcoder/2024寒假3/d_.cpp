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
int n;
int cal(vector<int>& v)
{
    vector<int>dp(n+1);
    int mx=-1e18;
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i-1]+v[i],v[i]);
        if(dp[i]>mx){
            mx=dp[i];
        }
    }
    return mx;
}
void solve(){
    int k;cin>>n>>k;
    vector<int>v(n+2);
    for(int i=1;i<=n;i++)cin>>v[i];
    if(k==0){
        cout<<cal(v)<<endl;
        return;
    }
    int ans=-1e18;
    for(int i=1;i<=n-1;i++){
        swap(v[i],v[i+1]);
        ans=max(ans,cal(v));
        swap(v[i],v[i+1]);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}