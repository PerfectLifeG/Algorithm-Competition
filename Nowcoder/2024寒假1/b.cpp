#include<bits/stdc++.h>
using namespace std;
// #define int long long
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
    unordered_map<int,int>mp[2];
    int L=2;
    int R=2;
    for(int i=0;i<n;i++){
        int r,c;cin>>r>>c;
        r--;
        // if(!L&&!R)continue;
        mp[r][c]=1;
        if(c<0&&L){
            L=1;
            if(mp[r^1].count(c+1)||mp[r^1].count(c)||mp[r^1].count(c-1)){
                L=0;
            }
        }
        else if(c>0&&R){
            R=1;
            if(mp[r^1].count(c+1)||mp[r^1].count(c)||mp[r^1].count(c-1)){
                R=0;
            }
        }else if(c==0){
            L=min(L,1);
            R=min(R,1);
            if(mp[r^1].count(c-1)){
                L=0;
            }
            if(mp[r^1].count(c+1)){
                R=0;
            }
        }
    }
    int ans=3;
    if(mp[0].count(-1))ans--;
    if(mp[0].count(1))ans--;
    if(mp[1].count(0))ans--;
    // cout<<L<<' '<<R<<endl;
    cout<<min(ans,L+R)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}