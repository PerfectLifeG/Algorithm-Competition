#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    sort(a,a+n*m);
    int ans=0;
    int m1=a[n*m-1],m2=a[n*m-2],l1=a[0],l2=a[1];
    int a=max(n*(m-1),m*(n-1));
    ans=(m1-l1)*a;
    int mx=max((m2-l1),(m1-l2));
    if(n*(m-1)>m*(n-1))
    cout<<ans+(n-1)*mx<<endl;
    else cout<<ans+(m-1)*mx<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}