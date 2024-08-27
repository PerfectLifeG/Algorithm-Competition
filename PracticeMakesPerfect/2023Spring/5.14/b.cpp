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
int a[N];
void solve(){
    int n;cin>>n;
    int cnt1=0;
    int mx=0;
    // map<int,int>mp;
    int t=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t=__gcd(t,abs(a[i]-i));
        // if(a[i]!=i){
        //     cnt1++;
        //     mp[abs(a[i]-i)]++;
        //     // mx=max(mx,mp[abs(a[i]-i)]);
        // }
    }
    cout<<t<<endl;
    // for(int i)
    // for(auto i:mp){
    //     cout<<i.first<<' '<<i.second<<endl;
    // }
    // cout<<mx<<' '<<cnt1<<endl;
    // int a=(--mp.end())->second+(--(--mp.end()))->second;
    // if(cnt1==a){
        // cout<<(mp.begin())->first<<endl;
    // }else cout<<1<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}