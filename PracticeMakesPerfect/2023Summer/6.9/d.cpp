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
int b[N];
int s[N];
void solve(){
    int n,m;cin>>n>>m;
    int ans=0;
    memset(b,0,sizeof b);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0)b[i]=a[i]*(n-i+1);
        ans+=a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+b[i];
    }
    if(m>=n){
        cout<<ans-(s[n]-s[0])<<endl;
    }
    else 
        cout<<ans-(s[n]-s[n-m])<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}