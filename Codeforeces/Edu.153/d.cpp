#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=210;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    string s;cin>>s;
    int n=s.size();
    int c0=0,c1=0;
    int c10=0,c01=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0')c10+=c1,c0++;
        if(s[i]=='1')c01+=c0,c1++;
    }
    int dp[2*n+1][2*c0*c1+1];
    memset(dp,INF,sizeof dp);
    dp[n][c0*c1]=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            for(int j=2*n;j>=1;j--){
                for(int k=2*c0*c1;k>=i;k--){
                    dp[j][k]=min(dp[j][k],dp[j-1][k-i]+1);
                }
            }
        }else{
            for(int j=0;j+1<=2*n;j++){
                for(int k=0;k+i<=2*c0*c1;k++){
                    dp[j][k]=min(dp[j][k],dp[j+1][k+i]);
                }
            }
        }
    }
    cout<<dp[n][c0*c1-(c01-c10)/2]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}