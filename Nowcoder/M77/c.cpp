#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=1e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,m,k;cin>>n>>m>>k;
    int mx=0;
    vector<int>v(N);
    vector<int>v2(N);
    int now=0;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        v[a]++;
        v2[b]++;
    }
    int ans=0;
    int t=0;
    for(int i=0;i<n;i++){
        t+=v[i]-v2[i];
        ans=max(ans,t/k+(bool)(t%k));
    }
    cout<<ans<<endl;
    }
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}