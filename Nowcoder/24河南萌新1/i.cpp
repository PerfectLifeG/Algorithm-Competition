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
    int n,t;cin>>n>>t;
    vector<int>a(n);
    int ans=1e9;
    int mx=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i]==mx){
            ans=min(ans,(n-i)%n);
        }
    }
    if(ans<=t)cout<<ans<<endl;
    else{
        ans=0;
        int mn=a[0];
        for(int i=1;i<=t;i++){
            if(a[n-i]>mn){
                mn=a[n-i];
                ans=i;
            }
        }
        cout<<ans<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}