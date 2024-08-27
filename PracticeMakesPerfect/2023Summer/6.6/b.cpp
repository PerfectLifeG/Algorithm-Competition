#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
#define int long long
inline int Log2(double x){
    if(x==1)return 0;
    return ((*(unsigned long long*)&x>>52)&1023)+1;
}
void solve(){
    int a,b;cin>>a>>b;
    if(b>Log2(a))cout<<a+1<<endl;
    else cout<<(1<<b)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}