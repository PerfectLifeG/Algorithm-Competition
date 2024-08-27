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
const int N=10010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
vector<int>dp(N+1,1e18);
void solve(){
    int n;cin>>n;
    dp[0]=0;
    for(int i=0;i<n;i++){
        int v,w;cin>>w>>v;
        for(int j=N;j>=v;j--){
            dp[j]=min(dp[j],dp[j-v]+w);
        }
    }
    for(int i=N-1;i>=1;i--){
        dp[i]=min(dp[i],dp[i+1]);
    }
    int q;cin>>q;
    while(q--){
        int w;cin>>w;
        int l=0,r=N;
        while(l+1!=r){
            int mid=l+r>>1;
            if(dp[mid]>w)r=mid;
            else l=mid;
        }
        cout<<l<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}