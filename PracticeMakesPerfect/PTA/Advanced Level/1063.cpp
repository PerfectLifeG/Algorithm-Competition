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
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    unordered_map<int,int>mp[n+1];
    for(int i=1;i<=n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int a;cin>>a;
            mp[i][a]++;
        }
    }
    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;
        int nc=0,nt=mp[b].size();
        for(auto [i,j]:mp[a]){
            if(mp[b].count(i)){
                nc++;
            }else nt++;
        }
        cout<<fixed<<setprecision(1)<<(1.0*nc/nt*100)<<'%'<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}