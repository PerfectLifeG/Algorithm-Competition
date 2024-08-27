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
    int n;cin>>n;
    string ans;int mx=0;
    unordered_map<string,int>mp;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        mp[s]++;
        if(mp[s]>mx){
            mx=mp[s];
            ans=s;
        }
    }
    if(mx*2>n){
        cout<<ans<<endl;
    }else cout<<"uh-oh\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}