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
    string s;cin>>s;s=' '+s;
    int ans=0;
    vector<int>dp(n+2);
    int pre=1;
    for(int i=1;i<=n;i++){
        if(s[i]=='1'){
            if(i>=3)dp[i]=dp[i-3]+i;
            else dp[i]=i;
        }else dp[i]=dp[i-1];
    }
    for(int i=1;i<=n;i++){ans+=dp[i];}
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}