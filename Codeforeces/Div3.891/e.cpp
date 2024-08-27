#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Node{
    int v;
    int id;
    bool operator<(const Node &n)const
    {
        return v<n.v;
    }
};
void solve()
{
    int n;cin>>n;
    Node node[n+1];
    vector<int>a(n+1);
    vector<int>sum(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        node[i]={a[i],i};
    }
    sort(node+1,node+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+node[i].v;
    }
    vector<int>ans(n+1);
    for(int i=1;i<=n;i++)ans[node[i].id]=(i-1)*node[i].v-sum[i-1]+n+sum[n]-sum[i]-(n-i)*node[i].v;
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}