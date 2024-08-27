#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int h[N],e[N*2],ne[N*2],idx;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int book[N];
int n;
int son[N];
int dfs(int t){
    int flag=0;
    for(int i=h[t];~i;i=ne[i]){
        int j=e[i];
        if(book[j])continue;
        book[j]=1;
        son[t]+=dfs(j);
        flag=1;
    }
    if(!flag){son[t]=1;return 1;}
    return son[t];
}
void solve(){
    cin>>n;
    memset(book,0,sizeof(book));
    memset(son,0,sizeof(son));
    memset(h,-1,sizeof(h));
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    book[1]=1;
    dfs(1);
    int q;cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<son[a]*son[b]<<endl;;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}