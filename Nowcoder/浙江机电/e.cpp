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
int dp[2][N];
void solve(){
    int n,v;
    cin>>n>>v;
    for(int i=0;i<n;i++){
        int op,vv,ww;
        cin>>op>>vv>>ww;
        for(int j=v;j>=vv;j--){
            dp[op][j]=max(dp[op][j],dp[op][j-vv]+ww);
        }
    }
    if(dp[1][v]>dp[0][v]){
        cout<<dp[1][v]<<' '<<1<<endl;
    }else cout<<dp[0][v]<<' '<<0<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}