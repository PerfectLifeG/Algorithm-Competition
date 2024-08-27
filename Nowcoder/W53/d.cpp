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
    int n,m;cin>>n>>m;
    int a[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int tar;cin>>tar;
    int ans=1e9;
    vector<int>dp1(5500);
    vector<int>dp2(5500);
    dp1[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=5100;j>=0;j--){
            for(int k=1;k<=m;k++){
                if(j<a[i][k])continue;
                if(dp1[j-a[i][k]]){dp2[j]=1;break;}
            }
        }
        dp1=dp2;
        if(i==n)break;
        dp2.assign(5500,0);
    }
    for(int j=1;j<=5500;j++){
        if(dp2[j])ans=min(ans,abs(j-tar));
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}