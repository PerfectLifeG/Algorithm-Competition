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
int f[N];
void solve(){
    int n;cin>>n;
    unordered_map<int,int>mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        if(mp.count(a[i]))
        f[i]=max(f[i],i+1+mp[a[i]]);
        if(mp.count(a[i]))
        mp[a[i]]=max(mp[a[i]],f[i-1]-i);
        else mp[a[i]]=f[i-1]-i;
        // cout<<f[i]<<' '<<mp[a[i]]<<endl;
    }
    cout<<f[n]<<endl;
}
// chkmax(f[i],i+1+mp[a[i]]);   
// chkmax(mp[a[i]],f[i-1]-i);

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}