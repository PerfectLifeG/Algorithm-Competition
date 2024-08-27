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
    int n,m;cin>>n>>m;
    vector<int>v(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        v[b]=max(v[b],a);   
    }
    for(int i=1;i<=n;i++){
        v[i]=max(v[i-1],v[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=i-v[i];
    }
    cout<<ans<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}