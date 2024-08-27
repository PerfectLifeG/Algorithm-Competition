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
PII a[N],b[N],c[N];
int ans[N];
void solve(){
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        a[i]={t,i};
        c[i]=a[i];
    }
    for(int i=0;i<n;i++){
        int t;cin>>t;
        b[i]={t,i};
    }
    // 1 3 3 5 9
    // 1 2 4 3 5
    // 2 2 4 5 11
    sort(a,a+n);
    sort(b,b+n);
    map<pair<int,int>,int>mp;
    for(int i=0;i<n;i++){
        mp[a[i]]=b[i].first;
    }    
    for(int i=0;i<n;i++){
        ans[c[i].second]=mp[c[i]];
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}