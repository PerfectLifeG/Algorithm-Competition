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
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    unordered_map<int,int>mn;
    unordered_map<int,int>mx;
    mn[1]=1;
    mn[2]=10;
    mn[3]=100;
    mn[4]=1000;
    mn[5]=10000;
    mn[6]=100000;
    mx[1]=9;
    mx[2]=99;
    mx[3]=999;
    mx[4]=9999;
    mx[5]=99999;
    mx[6]=999999;
    // a 1  1
    // b 1  1~8
    // c 3  1~9
    
    // 1+99=100
    // 1+998=999
    //
    int ans=0;
    for(int i=mn[a];i<=mx[a];i++){
        int bmn=mn[c]-i;
        int bmx=mx[c]-i;
        bmn=max(bmn,mn[b]);
        bmx=min(bmx,mx[b]);
        if(bmx<bmn)continue;
        // cout<<bmn<<' '<<bmx<<endl;
        if(ans+bmx-bmn+1>=k){
            cout<<i<<" + "<<k-ans+bmn-1<<" = "<<i+k-ans+bmn-1<<endl;
            return;
        }
        ans+=bmx-bmn+1;
    }
    cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}