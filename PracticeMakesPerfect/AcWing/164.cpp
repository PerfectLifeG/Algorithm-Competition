#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=30100;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int h[N],e[N],ne[N],idx;
int ru[N];int n,m;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bitset<N>bs[N];
void bfs(){
    queue<int>q;
    for(int i=1;i<=n;i++){bs[i][i]=1;if(ru[i]==0)q.push(i);}
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(--ru[j]==0)q.push(j);
            bs[j]|=bs[t];
        }
    }
}
void solve()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;cin>>a>>b;
        add(b,a);
        ru[a]++;
    }
    bfs();
    for(int i=1;i<=n;i++){
        cout<<bs[i].count()<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}