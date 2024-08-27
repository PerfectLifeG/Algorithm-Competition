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
string s,t;
struct hash{
    #define ll unsigned long long
    const int P=131;
    ll h1[N]={};
    ll h2[N]={};
    ll p[N]={};
    void init(){
        int n=s.size()-1;
        p[0]=1;
        for(int i=1;i<=n;i++){
            p[i]=p[i-1]*P;
            h1[i]=h1[i-1]*P+s[i];
        }
        for(int i=n;i>=1;i--){
            h2[i]=h2[i+1]*P+s[i];
        }
    }
    ll get(int l,int r){
        ll res=h1[r]-h1[l-1]*p[r-l+1];
        return res;
    }
    ll get2(int l,int r){
        ll res=h2[l]-h2[r+1]*p[r-l+1];
        return res;
    }
}hs;
struct hash2{
    #define ll unsigned long long
    const int P=131;
    ll h1[N]={};
    ll h2[N]={};
    ll p[N]={};
    void init(){
        int n=t.size()-1;
        p[0]=1;
        for(int i=1;i<=n;i++){
            p[i]=p[i-1]*P;
            h1[i]=h1[i-1]*P+t[i];
        }
        for(int i=n;i>=1;i--){
            h2[i]=h2[i+1]*P+t[i];
        }
    }
    ll get(int l,int r){
        ll res=h1[r]-h1[l-1]*p[r-l+1];
        return res;
    }
    ll get2(int l,int r){
        ll res=h2[l]-h2[r+1]*p[r-l+1];
        return res;
    }
}hs2;

void solve(){
    int n,m;cin>>n>>m;
    if(n>m){
        swap(n,m);
        cin>>t>>s;
    }else cin>>s>>t;
    s=' '+s;
    t=' '+t;

    hs.init();
    hs2.init();
    set<int>pre{1000000000};
    set<int>suf{1000000000};
    vector<int>p1;
    vector<int>p2;
    for(int i=1;i<=n;i++){
        if(s.substr(1,i)==t.substr(m-i+1))p1.push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(t.substr(1,i)==s.substr(n-i+1))p2.push_back(i);
    }
    for(auto i:p1){
        // cout<<i<<' '<<hs.get(1,i)<<' '<<hs.get2(1,i)<<endl;
        // cout<<i<<' '<<hs2.get(m-i+1,m)<<' '<<hs2.get2(m-i+1,m)<<endl;
        // cout<<s.substr(1,i)<<' '<<t.substr(m-i+1)<<endl;
        if(hs.get(1,i)==hs.get2(1,i)&&hs2.get(m-i+1,m)==hs2.get2(m-i+1,m)){
            pre.insert(i);
        }
    }
    for(auto i:p2){
        if(hs.get(n-i+1,n)==hs.get2(n-i+1,n)&&hs2.get(1,i)==hs2.get2(1,i)){
            suf.insert(n-i+1);
        }
    }
    // for(auto i:pre)cout<<i<<' ';cout<<endl;
    // for(auto i:suf)cout<<i<<' ';cout<<endl;
    int ans=-1;
    for(auto i:pre){
        if(i==1e9)break;
        int t=*suf.upper_bound(i);
        // cout<<i<<' '<<t<<endl;
        if(t!=1e9)ans=max(ans,n-t+1+i);
        // cout<<ans<<endl;
    }
    if(ans==-1)cout<<-1<<endl;
    else cout<<ans*2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}