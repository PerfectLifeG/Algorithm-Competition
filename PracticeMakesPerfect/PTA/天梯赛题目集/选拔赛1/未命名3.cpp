#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int a,b;cin>>a>>b;
    int ans=0;
    double lst=0;
    double k=1.0*b/a;
    for(int i=1;i<=a;i++){
        double now=1.0*b*i/a;
//      cout<<lst<<' '<<now<<' '<<ans<<endl;
        ans+=(int)ceil(now)-((int)floor(lst));
        //ans++;
        lst=now;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
}