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
    string s;cin>>s;int x=s.size();
    s=' '+s;
    int n;cin>>n;
    string v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>dp(x+1,INF);
    vector<int>fa(x+1);
    vector<int>ans(x+1);
    dp[0]=0;
    for(int i=1;i<=x;i++){
        int f=1;
        for(int j=0;j<n;j++){
            if((i+v[j].size()-1)>x)continue;
            if(s.substr(i,v[j].size())==v[j]){
                // cout<<i<<' '<<v[j]<<endl;
                f=0;
                for(int k=0;k<v[j].size();k++){
                    if(dp[i-1]+1<dp[i+k]){
                        ans[i+k]=j+1;
                        fa[i+k]=i-1;
                        dp[i+k]=dp[i-1]+1;
                    }
                }
            }
        }
        if(f&&dp[i]==INF){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<dp[x]<<endl;
    int t=x;
    while(t){
        cout<<ans[t]<<' '<<fa[t]+1<<endl;
        t=fa[t];
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}