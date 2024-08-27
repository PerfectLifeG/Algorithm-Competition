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
void solve(){
    int n,q;cin>>n>>q;
    unordered_map<int,int>lst;
    unordered_map<int,int>lst2;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    int dp[n+1]={};
    for(int i=1;i<=n;i++){
        if(lst.count(v[i])&&i-lst[v[i]]>=2){
            dp[i]=max(lst[v[i]],dp[i-1]);
        }else if(lst.count(v[i])&&i-lst[v[i]]==1){
            if(lst2[i-1]>=1){
                dp[i]=max(lst2[i-1],dp[i-1]);
            }else dp[i]=dp[i-1];
        }else dp[i]=dp[i-1];
        lst2[i]=lst[v[i]];
        lst[v[i]]=i;
    }
    while(q--){
        int l,r;cin>>l>>r;
        if(dp[r]>=l)yes;
        else no;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}