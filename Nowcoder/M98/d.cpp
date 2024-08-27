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
    int n,L,R;cin>>n>>L>>R;
    string s;cin>>s;s=' '+s;
    vector<int>pre0(n+1);
    vector<int>pre1(n+1);
    for(int i=1;i<=n;i++){
        pre0[i]=pre0[i-1]+(s[i]=='0');
        pre1[i]=pre1[i-1]+(s[i]=='1');
    }
    int dp[n+1][n+1]={};
    for(int len=2;len<=n;len++){
        for(int i=1;len+i-1<=n;i++){
            int j=len+i-1;
            for(int k=i;k<j;k++){
                int t=abs(pre0[k]-pre0[i-1]-pre1[j]+pre1[k]);
                if(t>=L&&t<=R){
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+1);
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}