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
    vector<int>v(n+1);
    vector<int>pre(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        pre[i]=v[i]^pre[i-1];
    }
    int mx=0;
    int t=v[n-1];
    for(int i=n-1;i>=2;i--){
        t|=v[i];
        mx=max(mx,pre[i-1]+t);
    }
    cout<<mx+v[n]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}