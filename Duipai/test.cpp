#include <bits/stdc++.h>

using namespace std;

#define int long long
#define rep(a,b,c) for (a = b;a <= c; a ++)
#define rrep(a,c,b) for (a = c;a >= b; a --)
#define all(a) a.begin(), a.end()
const int N = 1e6+10;
const int mod = 1e9+7;

int dp[N];
int last[N];

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
        p1[0]=p2[0]=1;
        for(int i=1;i<s.size();i++){
            p1[i]=p1[i-1]*P1%mod1;
            p2[i]=p2[i-1]*P2%mod2;
            h1[i]=(h1[i-1]*P1+s[i])%mod1;
            h2[i]=(h2[i-1]*P2+s[i])%mod2;
        }
    }
    pair<ll,ll> get(int l,int r){//下标从1开始
        ll res1=((h1[r]-h1[l-1]*p1[r-l+1])%mod1+mod1)%mod1;
        ll res2=((h2[r]-h2[l-1]*p2[r-l+1])%mod2+mod2)%mod2;
        return make_pair(res1,res2);
    }
};


void solve(){
    int n,m;cin>>n>>m;
    // for(int i=0;i<=n;i++)dp[i]=0,last[i]=0;
    string s;cin>>s;
    string t;cin>>t;

    int pre=-1;
    int idx=0;
    for(int i=0;i<s.size();i++){
        // cout<<i<<' '<<idx<<' '<<s[i]<<' '<<t[idx]<<endl;
        if(s[i]==t[idx]){
            idx++;
        }
        if(idx==m){pre=i+1;break;}
    }

    int lst=-2;
    idx=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]==t[idx]){
            idx++;
        }
        if(idx==m){lst=i-1;break;}
    }
    // cout<<lst<<' '<<pre<<endl;


    int p=lst-pre+1;
    string a;a+=' ';
    for(int i=1;i<=p;i++){
        a+=s[i+pre-1];
    }
    for(int i=1;i<=p;i++){
        if(!last[a[i]]){
            dp[i]=dp[i-1]*2+1;
        }
        else{
            dp[i]=(dp[i-1]*2-dp[last[a[i]]-1]);
        }
        dp[i]=(dp[i]+mod)%mod;
        last[a[i]]=i;
    }
    int ans=0;
    // cout<<lst<<' '<<pre<<endl;
    if(p>=0)ans+=dp[p]+1;ans%=mod;
    // cout<<ans<<endl;
    // cout<<p<<' '<<dp[p]<<endl;
    if(pre==-1||lst==-2){
        cout<<0<<endl;
        return;
    }
    

    string tt=t;    
    reverse(tt.begin(),tt.end());
    Hash hs1(t);
    Hash hs2(tt);


    // cout<<lst<<' '<<pre<<endl;
    int ppp=0;
    if(lst<pre)ppp=pre-lst-1;
    int cnt=0;
    // cout<<ppp<<endl;
    // cout<<t<<endl;
    for(int i=0;i<m;i++){
        // cout<<m-i<<' '<<m<<' '<<1<<' '<<1+i<<endl;
        if(hs1.get(m-i,m)==hs2.get(1,1+i)){
            // cout<<i+1<<endl;
            if(i+1>=ppp)cnt++;
            // if(p==0&&i+1==m)cnt--;
        // cout<<t.substr(m-i-1,i+1)<<endl;
        }
    }
    ans+=cnt;ans%=mod;
    cout<<ans<<endl;
}

signed main(){
    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
    
}