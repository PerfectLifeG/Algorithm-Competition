#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int mod=998244353;
const int INF=0x3f3f3f3f;
const int N=2e5+10;
int h[N],ne[N],e[N];
int idx;
int d[N];
int book[N];
int st[N];
void add(int x,int y)
{
    e[idx]=y;
    ne[idx]=h[x];
    h[x]=idx++;
}
int ans;
int n,m,k;
void bfs(){
    queue<int>q;
    book[1]=1;
    q.push(1);
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];
            if(book[j]){
                ans=ans+max(0,k-d[j])+max(0,k-d[t]);
                continue;
            }
            if(d[t]+1==d[j]){
                book[j]=1;
                q.push(j);
            }else{
                ans=ans+max(0,k-d[j])+max(0,k-d[t]);
            }
        }
    }
}
void solve()
{
    cin>>n>>m>>k;
    while(m--){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    queue<int>q;
    for(int i=1;i<=n;i++)d[i]=1e9;
    d[1]=0;
    st[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=h[u];~i;i=ne[i])
        {
            int j=e[i];
            if(st[j])continue;
            d[j]=d[u]+1;
            q.push(j);
            st[j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(d[i]<=k)ans++;
    }
    bfs();
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}