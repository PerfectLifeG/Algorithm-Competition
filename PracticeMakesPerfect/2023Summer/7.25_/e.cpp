#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=1e17;
int d[N];
int book[N];
int dfs(int t,vector<vector<int>>& v){
    if(book[t])return d[t];
    int sum=0;
    for(int i=0;i<v[t].size();i++){
        int j=v[t][i];
        book[t]=1;
        sum+=dfs(j,v);
    }
    d[t]=min(sum,d[t]);book[t]=1;
    return d[t];
}
void solve()
{
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>d[i];
        book[i]=0;
    }
    vector<vector<int>>v(n+1);
    while(k--){
        int a;cin>>a;
        d[a]=0;
        book[a]=1;
    }
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        if(!a){
            book[i]=1;
        }
        for(int j=0;j<a;j++){
            int t;cin>>t;
            v[i].push_back(t);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dfs(i,v)<<" \n"[i==n];
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}