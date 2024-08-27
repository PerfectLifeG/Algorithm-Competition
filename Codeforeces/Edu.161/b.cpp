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
    vector<int>a(n);
    map<int,int>mp;
    map<int,int>mp2;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
        mp2[a[i]]++;
    }
    for(auto [i,j]:mp){
        mp[i]=j*(j-1)/2;
    }
    int idx=1;
    vector<int>s(n+1);
    unordered_map<int,int>mp3;
    for(auto [i,j]:mp){
        mp3[idx]=i;
        s[idx]=j;
        idx++;
    }
    for(int i=1;i<idx;i++){
        s[i]+=s[i-1];
    }
    int ans=0;
    for(int i=1;i<idx;i++){
        int t=mp2[mp3[i]];
        ans+=t*(s[idx-1]-s[i])+t*(t-1)*(t-2)/6;
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