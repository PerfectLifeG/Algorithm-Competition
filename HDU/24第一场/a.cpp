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

struct Hash{
    #define ll long long
    const int P1=131;
    const int mod1=1e9+7;
    const int P2=13331;
    const int mod2=1e9+9;
    string s;
    vector<ll>h1,h2,p1,p2;
    Hash(string t){
        s=' '+t;
        h1.resize(s.size());h2.resize(s.size());
        p1.resize(s.size());p2.resize(s.size());
        init();
    }
    void init(){
        p1[0]=p2[0]=1;
        for(int i=1;i<s.size();i++){
            p1[i]=p1[i-1]*P1%mod1;
            p2[i]=p2[i-1]*P2%mod2;
            h1[i]=(h1[i-1]*P1+s[i])%mod1;
            h2[i]=(h2[i-1]*P2+s[i])%mod2;
        }
    }
    pair<ll,ll> get(int l,int r){
        ll res1=((h1[r]-h1[l-1]*p1[r-l+1])%mod1+mod1)%mod1;
        ll res2=((h2[r]-h2[l-1]*p2[r-l+1])%mod2+mod2)%mod2;
        return make_pair(res1,res2);
    }
};
void solve(){
    string a,b;cin>>a>>b;
    int n=a.size(),m=b.size();a+=a;
    Hash h1(a),h2(b);
    h1.init();h2.init();
    a=' '+a,b=' '+b;
    map<PII,int>mp;
    for(int i=1;i<=n;i++){
        mp[h1.get(i,i+n-1)]++;
    }
    int ans=0;
    for(int i=1;i+n-1<=m;i++){
        if(mp.count(h2.get(i,i+n-1)))ans++;
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