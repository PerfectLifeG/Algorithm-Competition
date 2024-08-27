#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    int mx=0,mx2=0;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    int ans=0;
    if(n==1){
        if(a[0]>0){
            cout<<a[0]<<endl;
        }else cout<<0<<endl;
        return;
    }
        if(a[n-1]>0)ans+=a[n-1];
        if(a[n-2]>0)ans+=a[n-2];
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}