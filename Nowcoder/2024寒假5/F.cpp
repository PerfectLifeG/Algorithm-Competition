#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    vector<int>b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    if(n==1){
        cout<<0<<endl;return;
    }
    if(n%2==0){
        int mx=0;
        for(int i=1;i<=n-1;i++){
            mx=max(mx,a[i]-a[i+1]);
        }
        cout<<mx<<endl;
        return;
    }
    int mx=0;
    vector<int>cnt(n+1);
    for(int i=n-1;i>=1;i--){
        if(i%2==0){
            mx=max(mx,(a[i+1]-a[i])/i);
            a[i-1]+=mx*(i-1);
            a[i]+=mx*i;
        }
    }
    for(int i=1;i<=n-1;i++){
        if(a[i]>a[i+1]){cout<<-1<<endl;return;}
    }
    cout<<mx<<endl;
    // for(int i=1;i<=n;i++)cout<<a[i]<<' '<<cnt[i]<<' '<<b[i]+cnt[i]*i<<endl;

    // auto check=[&](int mid){
    //     vector<__int128>c(n+1);
    //     for(int i=1;i<=n;i++){
    //         c[i]=b[i]+__int128(min(mid,cnt[i]))*i;
    //     }
    //     // for(int i=1;i<=n;i++)cout<<c[i]<<' ';
    //     //     cout<<endl;

    //     for(int i=1;i<=n-1;i++){
    //         if(c[i]>c[i+1]){return 0;}
    //     }
    //     return 1;
    // };

    // int l=-1,r=mx+1;
    // while(l+1!=r){
    //     int mid=l+r>>1;
    //     // cout<<l<<' '<<r<<endl;
    //     if(check(mid))r=mid;
    //     else l=mid;
    // }
    // cout<<r<<endl;
    // for(int i=1;i<=n;i++)b[i]=b[i]+min(r,cnt[i])*i;
    //  for(int i=1;i<=n;i++)cout<<b[i]<<' ';
    //         cout<<endl;

    // int ans=0;
    // for(int i=1;i<=n;i++){
    //     ans=max(ans,(a[i]-b[i])/i);
    // }
    // cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}