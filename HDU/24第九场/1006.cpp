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
const int N=3100;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int val[11];
int dp[N];
int dp2[N];
int a[N];
void solve(){
    for(int i=1;i<=10;i++)cin>>val[i];
    for(int i=0;i<N;i++)a[i]=0;
    for(int i=0;i<N;i++)dp[i]=dp2[i]=0;

    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        int v1,v2;cin>>v1>>v2;
        a[v1]=max(a[v1],v2);
    }

    for(int i=1;i<=m;i++){
        if(!a[i])continue;
        for(int j=i;j<=m;j++){
            if(j-i==0||j-i!=0&&dp[j-i])
            dp[j]=max(dp[j],dp[j-i]+a[i]);
        }
    }


    for(int i=1;i<=m;i++){
        if(!dp[i])continue;
        // cout<<i<<' '<<dp[i]<<endl;
        for(int j=i;j<=m;j++){
            // cout<<i<<' '<<dp[i]<<' '<<(dp[i]*10+i-1)/i<<endl;
            dp2[j]=max(dp2[j],dp2[j-i]+val[(dp[i]*10+i-1)/i]*i);
        }
    }

    // for(int i=1;i<=m;i++)cout<<dp2[i]<<' ';cout<<endl;
    cout<<dp2[m]<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}