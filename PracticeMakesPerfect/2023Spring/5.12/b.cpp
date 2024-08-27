#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
int s[N];
void solve(){
    int n,k;cin>>n>>k;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=a[i]+s[i-1];
    }
    int ans=0;
    for(int i=0;i<=k;i++){
        ans=max(sum-s[2*i]-(s[n]-s[n-(k-i)]),ans);
    }
    // for(int i=1,j=n-1;k&&i<j;){
    //     if(a[i]+a[i-1]<a[j]){
    //         s=s-a[i]-a[i-1];
    //         i+=2;k--;
    //     }else if(a[i]+a[i-1]==a[j]){
    //         s=s-2*(a[i]+a[i-1]);
    //         t+=a[i]+a[i-1];
    //         i+=2;j--;
    //         k--;
    //     }else{
    //         s=s-a[j];
    //         j--;
    //         k--;
    //     }
    // }
    // s+=t;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}