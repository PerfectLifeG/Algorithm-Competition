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
const int N=3e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
struct Hash{
    #define ll long long
    const int mod=1e9+7;
    const int P=131;
    string s;
    ll h[N]={},p[N]={};
    Hash(string t){
        s=' '+t;
        init();
    }
    void init(){
        p[0]=1;
        for(int i=1;i<s.size();i++){
            p[i]=p[i-1]*P%mod;
            h[i]=(h[i-1]*P+s[i])%mod;
        }
    }
    ll get(int l,int r){
        ll res=(h[r]-h[l-1]*p[r-l+1]%mod+mod)%mod;
        return res;
    }
};
vector<int>dp(N);
unordered_map<int,int>mp1;
unordered_map<int,int>mp2;
void manercher(string &t){
    Hash hs(t);hs.init();
    string s="$#";
    for(int i=0;i<t.size();i++){
        s+=t[i];s+='#';
    }
    s+='^';
    int r=0,mid;
    for(int i=1;i<s.size();i++){
        if(i<r)dp[i]=min(dp[mid*2-i],r-i+1);
        else dp[i]=1;
        while(s[i-dp[i]]==s[i+dp[i]])dp[i]++;//最多执行n次O(n)
        if(i+dp[i]>r){
            mid=i;
            r=i+dp[i]-1;
        }
    }

    for(auto i:s)cout<<i<<' ';cout<<endl;
    for(int i=0;i<s.size();i++){
        // cout<<dp[i]<<' ';
        int l=i-dp[i]+1,r=i+dp[i]-1;
        if(s[l]=='#')l++;
        if(s[r]=='#')r--;
        if(l<=r){
            cout<<l/2<<' '<<r/2<<endl;
            cout<<t.substr(l/2,r/2-l/2+1)<<endl;
        }
        // cout<<endl;
    }
    cout<<endl;

}
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    manercher(s);
    // manercher(s+s);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}