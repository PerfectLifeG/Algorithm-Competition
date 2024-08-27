#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define int long long
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int f[N];
void solve(){
    int a;cin>>a;
    // f[4]=11;f[5]=13 2*n+1
    // 26 + 2*5+2*6+1+1
    cout<<26+(a-4)+2*(5+a)*(a-4)/2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}