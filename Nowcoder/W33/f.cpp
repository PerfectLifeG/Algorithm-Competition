#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++){cin>>a[i];b[i]=a[i];}
    int l,r;
    if(n&1) l=n/2,r=n/2;
    else l=n/2-1,r=n/2;
    l--,r++;
    for(;r<n;l--,r++){
        int mx=0;
        if(a[r]<=a[r-1])mx=max(mx,a[r-1]-a[r]+1);
        if(a[l+1]<=a[l])mx=max(mx,a[l+1]-a[l]+1);
        a[l]+=mx;
        a[r]+=mx;
        cout<<l<<' '<<r<<endl;
    }
    int ans=0;
    for(int i=0;i<n-1;i++){
        ans+=b[i]-a[i];
        b[i+1]+=b[i]-a[i];
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}