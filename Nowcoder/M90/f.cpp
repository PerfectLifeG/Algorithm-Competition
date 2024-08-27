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
    int n,m;cin>>n>>m;
    vector<PII>a(m+1);
    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(all(a));
    int dp[n+1][m+1][1];
    for(int j=1;j<=m;j++){
        for(int i=1;i<=a[j].x-1;i++){
            dp[i][j][1]*=2;
            dp[i][j][2]*=2;
        }
        for(int i=a[j].x;i<=a[j].y;i++){
            dp[i][j][1]=dp[i][j-1][1]+1;
            dp[i][j][2]=dp[i][j-1][2]+1;
            dp[i][j-1][2]*2+dp[i][j];
        }
    }
    cout<<dp[n][m][2]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}