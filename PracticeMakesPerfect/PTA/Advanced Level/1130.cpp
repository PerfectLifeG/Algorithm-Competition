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
unordered_map<string,int>mp;
void solve(){
    int n;cin>>n;
    string val[n+1];
    mp["+"]=1,mp["-"]=1,mp["*"]=2,mp["/"]=2,mp["%"]=2;
    vector<int>L(n+1,-1);
    vector<int>R(n+1,-1);
    vector<int>book(n+1);
    for(int i=1;i<=n;i++){
        cin>>val[i];
        int a,b;cin>>a>>b;
        L[i]=a;
        R[i]=b;
        if(a!=-1)book[a]=1;
        if(b!=-1)book[b]=1;
    }
    int root;
    for(int i=1;i<=n;i++)if(!book[i]){root=i;break;}
    vector<string>ans;
    function<void(int,string)> dfs=[&](int t,string s){
        int flag=0;
        if(t!=root&&R[t]!=-1)flag=1;
        if(flag)ans.push_back("(");
        if(L[t]!=-1){
            dfs(L[t],val[t]);
        }
        ans.push_back(val[t]);
        if(R[t]!=-1){
            dfs(R[t],val[t]);
        }
        if(flag)ans.push_back(")");
    };
    dfs(root,"+");
    for(auto i:ans)cout<<i;
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}