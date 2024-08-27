#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,m;cin>>n>>m;
    vector<int>f(n+1);
    vector<int>v(n+1),w(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    vector<int>a(m+1);
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            for(int j=m;j>=v[i];j--){
                f[j]=max(f[j],f[j-v[i]]+w[i]);
            }
        }
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