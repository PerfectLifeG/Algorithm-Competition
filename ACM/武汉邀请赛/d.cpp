#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin()+1,x.end()
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
    vector<int>a(n+1);
    vector<int>pre(n+1);
    vector<int>suf(n+2);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    for(int i=n;i>=1;i--)suf[i]=suf[i+1]+a[i];

    // vector<vector<int>> dp(n+1,vector<int>(2*n+1));
    vector<vector<int>> dp2(n+1,vector<int>(2*n+1));
    vector<vector<int>> dp3(n+2,vector<int>(2*n+1));
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         dp[i][j]=pre[min(n,i+j)]-pre[i-1];
    //     }
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            dp2[i][j]=max(dp2[i-1][j-1],pre[min(n,i+j)]-pre[i-1]);
        }
    }

    //从右往左
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         dp[i][j]=suf[max(1ll,i-j)]-suf[i+1];
    //     }
    // }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=2*n;j++){
            dp3[i][j]=max(dp3[i+1][j-1],suf[max(1ll,i-j)]-suf[i+1]);
            dp2[i][j]=max(dp2[i][j],dp3[i][j]);
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        int res=0;
        for(int j=1;j<=2*n;j++){
            res^=(j*dp2[i][j]);
        }
        res+=i;ans^=res;
    }
    cout<<ans<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}