#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x&(-x))
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=5010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    int a[n+1]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int dp[n+2][n+2]={};
    for(int i=1;i<=n;i++){
        for(int j=n;j>i;j--){
            dp[i][j]=dp[i][j+1];
            if(a[i]>a[j])dp[i][j]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]+=dp[i-1][j];
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]<a[j]){
                ans+=dp[j-1][j+1]-dp[i][j+1];
            }
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