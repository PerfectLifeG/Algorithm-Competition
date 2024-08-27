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
    map<int,int>mp;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        int x;cin>>x;
        mp[v[i]]=x;
    }
    int ans=0;
    for(auto &[i,j]:mp){
        int ma=j,mb=0;
        if(mp.count(i+1))mb=mp[i+1];
        int b=0;
        int a=min(ma,m/i);
        if(m>a*i){
            b=min(mb,(m-a*i)/(i+1));
            mb-=b;
            if(a*i+b*(i+1)<m){
                int t=min({a,mb,m-a*i-b*(i+1)});
                b+=t;
                a-=t;
            }
        }
        ans=max(ans,a*i+b*(i+1));
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