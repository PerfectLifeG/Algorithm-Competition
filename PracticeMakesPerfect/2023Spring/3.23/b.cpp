#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
set<int>s;
void solve(){
    int a;cin>>a;
}
// int a[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    // int i=1;
    // while(4*i*i>0){
    //     a[i]=i*i*2;
    //     i++;
    // }
    while(T--){
        // solve();
        int a;cin>>a;
        int ans=sqrt(a);
        if(ans*ans==a)ans--;
        cout<<ans<<endl;
    }
    return 0;
}