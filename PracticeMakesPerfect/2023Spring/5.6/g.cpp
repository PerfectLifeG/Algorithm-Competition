#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1510;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int ans[N][N];
int f[N][N];
unordered_map<int,PII>mp;
void solve(){
    int n;cin>>n;
    auto a=mp[n].first;
    auto b=mp[n].second;
    // cout<<a<<' '<<b<<endl;
    // if(a>=3&&b>=2)cout<<ans[a][b]-ans[a-2][b-1]<<endl;
    cout<<ans[a][b]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int cnt=2;
    f[1][1]=1;ans[1][1]=1;
    mp[1]={1,1};
    for(int i=2;i<=1500;i++){
        for(int j=1;j<=i;j++){
            f[i][j]=cnt*cnt;
            ans[i][j]=f[i][j]+ans[i-1][j];
            if(j>=2)ans[i][j]+=ans[i-1][j-1];
            if(i>=3&&j>=2)ans[i][j]-=ans[i-2][j-1];
            mp[cnt]={i,j};
            // cout<<cnt<<' '<<i<<' '<<j<<' '<<f[i][j]<<' '<<ans[i][j]<<endl;
            cnt++;
        }
    }
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}