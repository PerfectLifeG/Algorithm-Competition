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
    vector<int>a(n+1);
    map<int,vector<int>>mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]].push_back(0);
    }
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        mp[a[x]].push_back(i);
        a[x]=y;
        mp[a[x]].push_back(i);
    }

    int ans=0;
    for(auto &[x,y]:mp){
        ans+=m*(m+1)/2;
        if(y.size()%2==0)y.push_back(m+1);
        int cnt=0;
        for(int i=0;i<y.size();i+=2){
            if(!i)cnt+=y[i];
            else cnt+=y[i]-y[i-1];
        }
        ans-=cnt*(cnt-1)/2;
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