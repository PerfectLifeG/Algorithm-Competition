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
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>pre(n);
    unordered_map<int,int>mp;
    int mx=0;
    for(int i=0;i<n;i++){
        mp[v[i]]++;
        pre[i]=(int)(mp.size());
        mx=max(mx,pre[i]);
    }
    int ans=0;
    int book[n+1]={};
    int cnt=0;
    int idx=1;
    for(int i=n-1;i>=0;i--){
        if(book[v[i]]!=idx){book[v[i]]=idx;cnt++;}
        if(cnt==mx){
            ans++;
            idx++;
            cnt=0;
            if(i-1>=0)mx=pre[i-1];
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