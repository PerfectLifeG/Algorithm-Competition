#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,m,d;cin>>n>>m>>d;
    vector<int>a(m+1);
    for(int i=1;i<=m;i++)cin>>a[i];
    int cnt=m;
    a[0]=1;
    if(a[1]!=1)cnt+=(a[1]-2)/d,cnt++;
    for(int i=2;i<=m;i++)cnt+=(a[i]-a[i-1]-1)/d;
    cnt+=(n-a[m])/d;
    int ans=0;
    for(int i=2;i<m;i++){
        int t=a[i-1];
        if((a[i+1]-t-1)/d<(a[i]-t-1)/d+(a[i+1]-a[i]-1)/d+1){
            ans++;
        }
    }
    if(a[1]!=1)if((a[2]-1-1)/d<(a[1]-1-1)/d+(a[2]-a[1]-1)/d+1){
        ans++;
    }
    if(m>1)if((n-a[m-1])/d<(n-a[m])/d+(a[m]-a[m-1]-1)/d+1)ans++;
    if(ans==0)cout<<cnt<<' '<<m<<endl;
    else cout<<cnt-1<<' '<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}