#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=100010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int s[N],trie[N*8][2],idx=1;
void insert(int x,int val){
    int t=0;
    for(int i=7;i>=0;i--){
        int j=x>>i&1;
        if(!trie[t][j])trie[t][j]=idx++;
        t=trie[t][j];
    }
}
int query(int x){
    int t=0,res=0;
    for(int i=7;i>=0;i--){
        int j=x>>i&1;
        if(cnt[trie[t][!j]]){
            res+=!j<<i;
            t=trie[t][!j];
        }else{
            res+=j<<i;
            t=trie[t][j];
        }
    }
    return res^x;
}
void solve()
{
    int n;cin>>n;
    for(int i=0;i<=n*8;i++)trie[i][0]=trie[i][1]=0;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        s[i]=s[i-1]^a;
    }
    insert(s[0],1);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i>m)insert(s[i-m-1],-1);
        ans=max(ans,query(s[i]));
        insert(s[i],1);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}