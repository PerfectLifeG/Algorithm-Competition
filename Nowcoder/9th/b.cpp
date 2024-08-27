#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i,j;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)sum[i][j]=suf[i][j]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[j]>i)sum[i][j]=sum[i][j-1]+1;
            else sum[i][j]=sum[i][j-1];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=n;j;j--)
        {
            if(a[j]>i)suf[i][j]=suf[i][j+1]+1;
            else suf[i][j]=suf[i][j+1];
        }
    }
    
    

    int ans=0;
    map<PII,int>mp;
    for(int i=0;i<n;i++){
        int mn=a[i];
        for(int j=i;j<n;j++){
            mn=min(mn,a[j]);
            mp[{i,j}]=mn-1;
        }
    }
    set<PII>st;
    for(int i=0;i<n;i++){
        int mx=a[i];
        if(mx==mp[{i,n-1}]+1)continue;
        for(int j=i+1;j<n;j++){
            mx=max(mx,a[j]-mp[{i,j}]);
            // cout<<mx<<endl;
            if(a[j]-mp[{i,j}]==j-i+1){
                break;
            }
            if(a[j]-mp[{i,j}]!=mx){
                ans++;
                cout<<i<<' '<<j<<endl;
            }
        }
    }
    cout<<ans<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}