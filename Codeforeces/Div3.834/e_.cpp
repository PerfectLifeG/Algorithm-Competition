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
    int n,h;cin>>n>>h;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    int dp[3][2]={};//当前剩余i个2,j个3的最大能量
    dp[2][1]=h;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int x=2;x>=0;x--){
            for(int y=1;y>=0;y--){
                if(x){
                    dp[x-1][y]=max(dp[x-1][y],dp[x][y]*2);
                }
                if(y){
                    dp[x][y-1]=max(dp[x][y-1],dp[x][y]*3);
                }
                if(dp[x][y]>a[i]){
                    dp[x][y]+=a[i]/2;
                    ans=i+1;
                }
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