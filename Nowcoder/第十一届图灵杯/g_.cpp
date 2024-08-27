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
int dp[200010];
void solve(){
    int n;cin>>n;
    vector<int>v(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    int ans=INF;
    for(int i=1;i<=n;i++){
        int a=v[i];
        for(int j=N-1;j>=0;j--){
            if(j>=a&&dp[j-a]==j-a)dp[j]=dp[j-a]+a;
            ans=min(ans,abs(sum-2*dp[j]));
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}