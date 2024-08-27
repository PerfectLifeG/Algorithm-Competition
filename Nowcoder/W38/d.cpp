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
    int n,k;cin>>n>>k;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);        
    }
    int flag=0;
    vector<int>p;
    for(int i=1;i<n;i++){
        p.push_back(abs(v[i]-v[i-1]));
        if(abs(v[i]-v[i-1])==k){
            flag=1;
        }
    }
    int ans=0;
    for(auto i:p){
        // cout<<i<<' ';
        if(i<=k)continue;
        i-=k;
        ans+=i/k+(bool)(i%k);
        flag=1;
        cout<<ans<<endl;
    }
    if(!flag)cout<<ans+1<<endl;
    else cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}