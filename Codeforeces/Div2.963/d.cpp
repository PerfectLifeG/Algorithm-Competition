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

    int m=(n%k ? n%k :k);

    auto check=[&](int mid){
        vector<int>dp(m);
        int t=0;
        for(int i=0;i<n;i++){   
            int j=i%k;
            if(j>=m)continue;
            dp[j]=max(dp[j], (j == 0 ? 0 : dp[j-1]) + (a[i] >= mid));
        }
        // cout<<mid<<' '<<dp[m-1]<<endl;
        return dp[m-1]>=m/2+1;
    };

    int l=0,r=1e9+1;
    while(l+1!=r){
        int mid=l+r>>1;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<l<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}