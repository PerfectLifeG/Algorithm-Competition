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
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    int ans=0;
    for(auto &[i,j]:mp){
        for(int k=1;k<=j;k++){
            int t=0;
            if(mp.count(i+1)){
                t=mp[i+1];
            }
            int x=(m-(k*i))/(i+1);
            if(x<0)x=0;
            t=min(t,x);
            if(t*(i+1)+k*i<=m)
            ans=max(ans,t*(i+1)+k*i);
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