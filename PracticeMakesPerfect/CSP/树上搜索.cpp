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
    int n,Q;cin>>n>>Q;
    vector<int>book(n+1);
    vector<int>val(n+1);
    vector<int>v[n+1];
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=2;i<=n;i++){
        int fa;cin>>fa;
        v[fa].push_back(i);
    }
    vector<int>son(n+1);
    int sum=0;
    function<int(int,int)> dfs=[&](int t,int fa)->int{
        son[t]=val[t];
        for(auto j:v[t]){
            if(j==fa||book[j])continue;
            son[t]+=dfs(j,t);
        }
        return son[t];
    };

    int x;
    function<int(int,int)> dfs2=[&](int t,int fa)->int{
        if(t==x)return 1;
        for(auto j:v[t]){
            if(j==fa)continue;
            if(dfs2(j,t))return 1;
        }
        return 0;
    };
    dfs(1,1);

    int p=son[1];
    while(Q--){
        cin>>x;
        book.assign(n+1,0);sum=p;int root=1;
        for(int i=1;i<=n;i++){
            dfs(root,root);
            // cout<<root<<endl;
            int mn=INF,idx;
            int cnt=0;
            // for(int j=1;j<=n;j++)cout<<son[j]<<' ';cout<<endl;
            for(int j=1;j<=n;j++){
                if(son[j]!=INF)cnt++;
                if(mn>abs(sum-2*son[j])){
                    mn=abs(sum-2*son[j]);
                    idx=j;
                }
            }
            // cout<<idx<<' '<<cnt<<endl;
            if(cnt==1)break;
            if(dfs2(idx,idx)){
                root=idx;
                sum=son[idx];
            }else{
                book[idx]=1;
                sum-=son[idx];
            }
            cout<<idx<<' ';
            for(int j=1;j<=n;j++){
                son[j]=INF;
            }
        }
        cout<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}