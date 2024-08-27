#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int a[N];
int b[N];
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    int g=0,l=1;
    int ans=1;
    for(int i=0;i<n;i++){
        g=__gcd(g,a[i]*b[i]);
        l=l*b[i]/__gcd(l,b[i]);
        if(g%l){
            ans++;
            l=b[i];
            g=a[i]*b[i];
        }
    }
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