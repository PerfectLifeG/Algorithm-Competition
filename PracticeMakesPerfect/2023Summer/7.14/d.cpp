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
int a[N];
int f[N][2];
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=0){
            f[i][0]=min(f[i-1][0]*a[i],f[i-1][0])%mod;//fu
            f[i][1]=max({f[i-1][1]*a[i],f[i-1][1]+a[i],f[i-1][0]+a[i]})%mod;
        }
        else{
            f[i][0]=min({f[i-1][1]*a[i],f[i-1][0]+a[i],f[i-1][1]+a[i]})%mod;//fu
            f[i][1]=max(f[i-1][0]*a[i],f[i-1][1])%mod;
        }
    }
    cout<<f[n][1]%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}