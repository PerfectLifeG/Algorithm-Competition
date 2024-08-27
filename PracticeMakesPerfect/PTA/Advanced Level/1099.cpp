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
void solve(){
    int n;cin>>n;
    vector<int>L(n);
    vector<int>R(n);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        L[i]=a;
        R[i]=b;
    }
    vector<int>cnt(n);
    vector<int>son(n,1);
    function<int(int)> dfs=[&](int t)->int{
        if(L[t]!=-1){
            son[t]+=dfs(L[t]);
            cnt[t]=son[L[t]];
        }
        if(R[t]!=-1){
            son[t]+=dfs(R[t]);
        }
        return son[t];
    };
    dfs(0);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(all(v));
    vector<int>val(n);
    function<void(int,int,int)> dfs2=[&](int root,int l,int r){
        if(l>r)return;
        val[root]=v[l+cnt[root]];
        if(L[root]!=-1){
            dfs2(L[root],l,l+cnt[root]-1);
        }
        if(R[root]!=-1){
            dfs2(R[root],l+cnt[root]+1,r);
        }
    };
    dfs2(0,0,n-1);
    // for(int i=0;i<n;i++)cout<<val[i]<<' ';return;

    queue<int>q;
    q.push(0);
    vector<int>ans;
    while(q.size()){
        auto t=q.front();
        ans.push_back(val[t]);
        q.pop();
        if(L[t]!=-1){
            q.push(L[t]);
        }
        if(R[t]!=-1){
            q.push(R[t]);
        }
    }
    cout<<ans[0];
    for(int i=1;i<ans.size();i++)cout<<' '<<ans[i];
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}