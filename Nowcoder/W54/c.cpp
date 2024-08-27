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
    vector<int>a(n);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){cin>>a[i];mp[a[i]]++;}
    int now=n;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!mp.count(i)){
            cout<<ans<<endl;
            return;
        }else{
            now=min(now,mp[i]);
            ans+=now;
        }
    }
    cout<<ans<<endl;


}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}