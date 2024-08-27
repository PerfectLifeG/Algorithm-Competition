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
void solve(){
    int ans=0;
    int n,k,q;cin>>n>>k>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0;
    for(int i=0;i<n;i++){
        int j=i;
        while(i<n&&a[i]<=q)i++; 
        int l=i-j;
        if(l>=k)ans+=(2+l-k)*(1+l-k)/2;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}