#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin()+1,x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,q,st;cin>>n>>q>>st;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    sort(all(v));
    for(int i=1;i<=n;i++){
        v[i]+=v[i-1];
    }
    vector<int>s(n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+v[i];
    // for(auto i:v)cout<<i<<' ';cout<<endl;
    // for(auto i:s)cout<<i<<' ';cout<<endl;
    while(q--){
        int m;cin>>m;
        int t=m+s[n];
        int l=-1,r=n+1;
        while(l+1!=r){
            int mid=l+r>>1;
            // cout<<l<<' '<<r<<' '<<s[n]-s[mid]<<endl;
            if((n-mid)*st+s[n]<=t)r=mid;
            else l=mid;
        }
        cout<<v[r]+st<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}