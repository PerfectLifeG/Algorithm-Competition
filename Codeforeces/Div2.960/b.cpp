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
    int n,x,y;cin>>n>>x>>y;
    vector<int>ans(n+1);
    for(int i=y;i<=x;i++){
        ans[i]=1;
    }
    int f=-1;
    for(int i=y-1;i>=1;i--){
        ans[i]=f;
        f=-f;
    }
    f=-1;
    for(int i=x+1;i<=n;i++){
        ans[i]=f;
        f=-f;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}