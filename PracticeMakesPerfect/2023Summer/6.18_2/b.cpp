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
void solve(){
    int n,k,g;cin>>n>>k>>g;
    int t=(g-1)/2*n;
    if(t>=k*g){
        cout<<k*g<<endl;
        return;
    }
    int x=(g-1)/2+k*g-t;
    int r=x%g;
    if(r>=(g+1)/2){
        cout<<(g-1)/2*(n-1)-(g-r)<<endl;
    }
    else cout<<(g-1)/2*(n-1)+r<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}