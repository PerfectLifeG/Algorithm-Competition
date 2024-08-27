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
void solve(){
    int n;cin>>n;
    int sum=0;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    if(sum==0){
        cout<<0<<endl;
        return;
    }
    if(abs(sum)&1){
        cout<<-1<<endl;
        return;
    }
    if(sum>100*200||sum<(-100*200)){
        cout<<-1<<endl;
        return;
    }
    sum/=2;
    vector<int>dp(40010,1e9);
    vector<int>tmp(40010);
    dp[20000]=0;
    tmp=dp;
    for(int i=0;i<n;i++){
        for(int j=0;j<=40000;j++){
            if(j-v[i]>=0&&j-v[i]<=40000)
            dp[j]=min(dp[j],tmp[j-v[i]]+1);
        }
        tmp=dp;
    }
    if(dp[sum+20000]){
        cout<<dp[sum+20000];
    }else cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}