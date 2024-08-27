#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int n,k;
int a[N],trie[N*31][2],id[N*31],idx=1;
void insert(int x,int f){
    int t=0;
    for(int i=k-1;i>=0;i--){
        int j=x>>i&1;
        if(!trie[t][j])trie[t][j]=idx++;
        t=trie[t][j];
    }
    id[t]=f;
}
int flag;
int query(int x){
    int t=0;int ret=0;
    for(int i=k-1;i>=0;i--){
        int j=x>>i&1;
        if(trie[t][j]){
            ret<<=1;
            ret+=j;
            t=trie[t][j];
        }else{
            ret<<=1;
            ret+=!j;
            t=trie[t][!j];
        }
    }
    // cout<<x<<' '<<ret<<endl;
    flag=id[t];
    return ret;
}
void solve()
{
    cin>>n>>k;
    idx=1;for(int i=0;i<=n*k;++i)trie[i][0]=trie[i][1]=0;
    int ans1,ans2;
    int v1,v2;
    int ans=-1e18;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(i){
            int t=query(a[i]);
            // cout<<t<<' '<<a[i]<<' '<<~(t^a[i])<<endl;
            if((~(t^a[i]))>ans){
                // cout<<t<<' '<<a[i]<<' '<<~(t^a[i])<<endl;
                ans1=flag,ans2=i+1;
                v1=t,v2=a[i];
                ans=~(t^a[i]);
            }
        }
        // cout<<ans1<<' '<<ans2<<endl;
        insert(a[i],i+1);
    }
    ans=0;
    for(int i=k-1;i>=0;i--){
        int j=v1>>i&1;int k=v2>>i&1;
        ans<<=1;
        if(j==k){
            ans+=!j;
        }
    }
    cout<<ans1<<' '<<ans2<<' '<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}