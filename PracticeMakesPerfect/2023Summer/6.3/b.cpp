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
PII a[N];
int cmp(PII a,PII b){
    if(a.first==b.first)return a.second>b.second;
    return a.first<b.first;
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int b,c;cin>>b>>c;
        a[i]={b,c};
    }
    sort(a,a+n,cmp);
    int now=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(now<a[i].first){
            ans+=a[i].second;
            if(a[i].first>a[i-1].first)now=0;
            now++;
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