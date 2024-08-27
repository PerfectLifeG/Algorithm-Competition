#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int w,f;cin>>w>>f;
    int n;cin>>n;
    vector<int>a(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    vector<int>dp(sum+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=sum;j>=a[i];j--){
            dp[j]=max(dp[j],dp[j-a[i]]);
        }
    }
    int ans=1e18;
    for(int j=0;j<=sum;j++){
        if(dp[j]){
            int t=j/w+(bool)(j%w);
            if(t*f>=sum-j)
            ans=min(ans,t);
            t=j/f+(bool)(j%f);
            if(t*w>=sum-j)
            ans=min(ans,t);
        }
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