#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
int f[N][2];
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=-1e18;
    for(int i=1;i<=n;i+=2){
        ans=max(ans,a[i]);
    }
    if(ans>0){
        ans=0;
        for(int i=1;i<=n;i+=2)
        ans=max(ans,ans+a[i]);
    }

    int ans2=-1e18;
    for(int i=2;i<=n;i+=2){
        ans2=max(ans2,a[i]);
    }
    if(ans2>0){
        ans2=0;
        for(int i=2;i<=n;i+=2)
        ans2=max(ans2,ans2+a[i]);
    }
    cout<<max(ans,ans2)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}