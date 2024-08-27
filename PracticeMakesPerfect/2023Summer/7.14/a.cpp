#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int inf=0x3f3f3f3f;
void solve()
{
    int n;
    cin>>n;
    vector<PII>q(n+1);
    for(int i=0;i<n;i++) cin>>q[i].first;
    for(int i=0;i<n;i++) cin>>q[i].second;
    sort(q.begin(),q.end());
    int ans=0;
    for(int i=1;i*i<=2*n;i++){
        vector<int>qq(n+1);
        for(auto w:q){
            int f=w.first;
            int s=w.second;
            int t=f*i-s;
            if(t>=1&&t<=n) ans+= qq[t];
            if(i==f) qq[s]++;
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}