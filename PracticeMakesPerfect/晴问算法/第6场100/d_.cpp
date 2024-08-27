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
const int N=50;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int n,m;
string ans;
void get_lcs(string &a,string &b){
    // cout<<a<<' '<<b<<endl;
    string dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]="";
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + a[i-1];
            } else {
                if(dp[i-1][j].size()>dp[i][j-1].size()){
                    dp[i][j]=dp[i-1][j];
                }else if(dp[i-1][j].size()<dp[i][j-1].size()){
                    dp[i][j]=dp[i][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
    if(ans.size()<dp[n][m].size()){
        ans=dp[n][m];
    }else if(ans.size()==dp[n][m].size()){
        ans=min(ans,dp[n][m]);
    }
}
void solve(){
    string a,b;cin>>a>>b;
    n=a.size();m=b.size();
    int flag1=-1,flag2=-1;
    for(int i=0;i<n;i++){
        if(a[i]=='?'){
            if(flag1==-1){
                flag1=i;
            }else{
                flag2=i;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(b[i]=='?'){
            if(flag1==-1){
                flag1=i+35;
            }else{
                flag2=i+35;
            }
        }
    }
    if(flag1==-1){
        get_lcs(a,b);
    }else if(flag2==-1){
        for(int i=0;i<26;i++){
            if(flag1<30){
                a[flag1]='a'+i;
            }else b[flag1-35]='a'+i;
            get_lcs(a,b);
        }
    }else{
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(flag1<30){
                    a[flag1]='a'+i;
                }else{
                    b[flag1-35]='a'+i;
                }
                if(flag2<30){
                    a[flag2]='a'+j;
                }else{
                    b[flag2-35]='a'+j;
                }
                get_lcs(a,b);
            }
        }
    }
    cout<<ans.size()<<endl;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}