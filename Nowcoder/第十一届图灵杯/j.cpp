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
    int n,m;cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<double>dp(1<<n);
    for(int i=(1<<n)-1;i>=0;i--){
        int cnt=__builtin_popcount(i);
        int sum=0;
        for(int j=0;j<n;j++){
            if(~i>>j&1){
                dp[i]+=dp[i|(1<<j)];
            }else sum+=a[j];
        }
        if(sum>=m)dp[i]=0;
        else {
            dp[i]+=n;
            dp[i]=dp[i]*1.0/(n-cnt);
        }
    }
    cout<<fixed<<setprecision(6)<<dp[0]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}