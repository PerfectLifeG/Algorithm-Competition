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
const int N=3e3+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;

unordered_map<int,int>mp;
int L[N],R[N];
vector<int>v;
int dfs(int x){
    if(mp.count(x))return mp[x];
    int len=R[x]-L[x]+1;
    vector<int>dp(len+1);
    for(int i=1;i<=len;i++){
        if(i+L[x]-1==R[v[i+L[x]-1]]&&L[v[i+L[x]-1]]>L[x]){ 
            dp[i]=max(dp[L[v[i+L[x]-1]]-L[x]]+dfs(v[i+L[x]-1]),dp[i-1]+x);
        }else{
            dp[i]=dp[i-1]+x;
        }
    }
    return mp[x]=dp[len];
}

void solve(){
    int n;cin>>n;
    v.push_back(0);
    for(int i=1;i<=2*n;i++){
        int a;cin>>a;
        v.push_back(a);
        if(!L[a])L[a]=i;
        else R[a]=i;
    }
    L[0]=0,R[0]=2*n+1;
    cout<<dfs(0)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}