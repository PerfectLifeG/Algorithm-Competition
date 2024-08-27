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
    vector<int>pre(1+n);
    vector<int>suf(n+2);
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    set<int>s1;
    set<int>s2;
    for(int i=0;i<n;i++){
        s1.insert(a[i]);
        pre[i]=s1.size();
    }
    for(int i=n-1;i>=0;i--){
        s2.insert(a[i]);
        suf[i]=s2.size();
    }
    int mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,pre[i]+suf[i+1]);
    }cout<<mx<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}