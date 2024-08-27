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
const int mod=1e9+7;
const int INF=0x3f3f3f3f3f3f3f3f;
int dp[5010][5010];
void solve(){
    int n,m,Q,x;cin>>n>>m>>Q>>x;
    vector<int>v[n+1];
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int>book(n+1);
    book[x]=1;
    queue<int>q;
    q.push(x);
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(auto j:v[t]){
            if(book[j])continue;
            book[j]=book[t]+1;
            q.push(j);
        }
    }
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        if(i==x)continue;
        // cout<<i<<' '<<book[i]<<endl;
        mp[book[i]]++;
    }
    vector<int>p;p.push_back(0);
    for(auto [i,j]:mp)p.push_back(j);
    // for(auto i:p)cout<<i<<' ';cout<<endl;
    
    int idx=p.size()-1;
    dp[0][0]=1;
    for(int i=1;i<=idx;i++){
        for(int j=0;j<=i;j++){
            dp[i][j]=dp[i-1][j];
            if(j)dp[i][j]+=dp[i-1][j-1]*p[i]%mod;
            dp[i][j]%=mod;
        }
    }

    while(Q--){
        int k;cin>>k;
        cout<<dp[idx][k]<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}