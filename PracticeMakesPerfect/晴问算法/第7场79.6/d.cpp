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
    string s;cin>>s;
    int n=s.size();
    s=' '+s;
    vector<int>dp(n+1,1);
    vector<int>lst(10,-1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=9;j++){
            if(lst[j]!=-1){
                dp[i]=(dp[i]+dp[lst[j]])%mod;
            }
        }
        lst[s[i]-'0']=i;
    }
    int ans=0;
    for(int i=1;i<=9;i++){
        if(lst[i]!=-1){
            ans+=dp[lst[i]];
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}