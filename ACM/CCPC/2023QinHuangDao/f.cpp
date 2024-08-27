#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
vector<int>prime;
int book[N];
int cnt;
void getprime(int n=N-1){
    for(int i=2;i<=n;i++){//枚举k
        if(!book[i])prime.push_back(i);
        for(int j=0;prime[j]*i<=n;j++){//p*k<=n
            book[prime[j]*i]=1;
            if(i%prime[j]==0)break;//k不包含比p小的质因子
        }
    }
}
int a[N];
int dp[N][4];//0偶 1奇 2:1 3不变
void solve(){
    getprime();
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dp[0][0]=1,dp[0][1]=1;
    if(a[0]!=1)dp[0][2]=1;
    for(int i=1;i<n;i++){
        if(a[i]==1){
            dp[i][3]=dp[i-1][0];
            dp[i][2]=min(dp[i-1][2],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+1;
            dp[i][0]=dp[i-1][1]+1;
            if(a[i-1]&1){
                dp[i][0]=min(dp[i][0],dp[i-1][3]+1);
            }else{
                dp[i][1]=min(dp[i][1],dp[i-1][3]+1);
            }
            if(a[i-1]==1){
                dp[i][0]=min(dp[i-1][3]+1,dp[i][0]);
            }
            if(!book[a[i]+a[i-1]]){
                dp[i][3]=min(dp[i][3],dp[i-1][3]);
                dp[i][2]=min(dp[i][2],dp[i-1][3]);
            }
        }else if(a[i]&1){
            dp[i][3]=dp[i-1][0];
            dp[i][2]=min(dp[i-1][2]+1,dp[i-1][0]+1);
            dp[i][1]=dp[i-1][0]+1;
            dp[i][0]=dp[i-1][1]+1;
            if(a[i-1]&1){
                dp[i][0]=min(dp[i][0],dp[i-1][3]+1);
            }else{
                dp[i][1]=min(dp[i][1],dp[i-1][3]+1);
            }
            if(a[i-1]==1){
                dp[i][2]=min(dp[i][2],dp[i-1][3]+1);
                dp[i][0]=min(dp[i][0],dp[i-1][3]+1);
            }
            if(!book[a[i]+1]){
                dp[i][3]=min(dp[i][3],dp[i-1][2]);
            }
            if(!book[a[i]+a[i-1]]){
                dp[i][3]=min(dp[i][3],dp[i-1][3]);
            }
            if(!book[1+a[i-1]]){//1和修改的数
                dp[i][2]=min(dp[i][2],dp[i-1][3]+1);
            }
        }else{
            dp[i][3]=dp[i-1][1];
            dp[i][2]=min(dp[i-1][2]+1,dp[i-1][0]+1);
            dp[i][1]=dp[i-1][0]+1;
            dp[i][0]=dp[i-1][1]+1;
            if(a[i-1]&1){
                dp[i][0]=min(dp[i][0],dp[i-1][3]+1);
            }else{
                dp[i][1]=min(dp[i][1],dp[i-1][3]+1);
            }
            if(a[i-1]==1){
                dp[i][2]=min(dp[i][2],dp[i-1][3]+1);
                dp[i][0]=min(dp[i][0],dp[i-1][3]+1);
            }
            if(!book[a[i]+1]){
                dp[i][3]=min(dp[i][3],dp[i-1][2]);
            }
            if(!book[a[i]+a[i-1]]){
                dp[i][3]=min(dp[i][3],dp[i-1][3]);
            }
            if(!book[1+a[i-1]]){
                dp[i][2]=min(dp[i][2],dp[i-1][3]+1);
            }
        }
    }
    cout<<min({dp[n-1][0],dp[n-1][1],dp[n-1][2],dp[n-1][3]});
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}