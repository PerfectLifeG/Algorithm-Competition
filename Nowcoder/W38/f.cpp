#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
vector<int>dp(N);
vector<int>dp2(N);
void manercher(vector<int>& t){
    vector<int>s;s.push_back(-1);s.push_back(0);
    for(int i=0;i<t.size();i++){
        s.push_back(t[i]);
        s.push_back(0);
    }
    s.push_back(-2);
    int r=0,mid;
    for(int i=1;i<s.size();i++){
        if(i<r)dp[i]=min(dp[mid*2-i],r-i+1);
        else dp[i]=1;
        while(s[i-dp[i]]==s[i+dp[i]])dp[i]++;
        if(i+dp[i]>r){
            mid=i;
            r=i+dp[i]-1;
        }
    }
    for(int i=1;i<s.size();i++){
        if(i&1)dp[i]=min(dp[i],4ll);
        else dp[i]=min(dp[i],3ll);
    }
}
void solve(){
    int n,q;cin>>n>>q;
    vector<int>v;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        v.push_back(t);
    }
    manercher(v);
    for(int i=1;i<N-1;i++){
        if(dp[i]==4||dp[i]==3)
        dp2[i+dp[i]-1]=i-dp[i]+1;
    }
    for(int i=1;i<=n;i++){
        dp2[i*2]=max(dp2[i*2-2],dp2[i*2]);
    }
    while(q--){
        int l,r;cin>>l>>r;
        if(dp2[2*r]>=2*l)yes;
        else no;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}