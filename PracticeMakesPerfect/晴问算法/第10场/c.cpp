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
const int mod=1e9+7;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,k,m;cin>>n>>k>>m;
    vector<int>book(n+1);
    for(int i=0;i<m;i++){
        int a;cin>>a;
        book[a]=1;
    }
    vector<int>dp(n+1);
    dp[0]=1;
    for(int i=0;i<=n;i++){
        if(book[i])continue;
        for(int j=1;j<=k&&j<=i;j++){
            if(!book[i-j])
            dp[i]+=dp[i-j];dp[i]%=mod;
        }
    }
    cout<<dp[n]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}