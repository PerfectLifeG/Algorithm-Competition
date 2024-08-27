#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define int long long
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int a[N];
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==2){
        cout<<a[0]*a[1]<<endl;
        return;
    }
    sort(a,a+n);
    int mx=0;
    mx=max(a[0]*a[1],a[n-1]*a[n-2]);
    cout<<mx<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}