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
    string s[n];
    int sum[n][m+1]={};
    for(int i=0;i<n;i++){
        cin>>s[i];
        s[i]=' '+s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            sum[i][j]=sum[i][j-1]+(s[i][j]=='*');
            // cout<<sum[i][j]<<' ';
        }
        // cout<<endl;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='*'){
                int cnt=0;
                for(int k=i+1;k<n;k++){
                    int t=k-i;
                    if(j-t<=0||j+t>m)break;
                    if(s[k][j-t]!='*'||s[k][j+t]!='*')break;
                    if(sum[k][j+t]-sum[k][j-t-1]==2*t+1)cnt++;
                    // cout<<i<<' '<<j<<' '<<k<<' '<<t<<' '<<sum[k][j+t]<<' '<<sum[k][j-t-1]<<endl;
                    // cout<<cnt<<endl;
                }
                ans+=cnt;
            }
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