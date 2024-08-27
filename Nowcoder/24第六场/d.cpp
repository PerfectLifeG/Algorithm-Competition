#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int M=400010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;


int root[N];
int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a),rb=find(b);
    if(ra<rb)swap(ra,rb);
    root[ra]=rb;
}

int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int id[N], dcc_cnt;
bool is_bridge[M];
int d[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void tarjan(int u, int from)
{
    dfn[u] = low[u] = ++ timestamp;
    stk[ ++ top] = u;

    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j, i);
            low[u] = min(low[u], low[j]);
            if (dfn[u] < low[j])
                is_bridge[i] = is_bridge[i ^ 1] = true;
        }
        else if (i != (from ^ 1))
            low[u] = min(low[u], dfn[j]);
    }

    if (dfn[u] == low[u])
    {
        ++ dcc_cnt;
        int y;
        do {
            y = stk[top -- ];
            id[y] = dcc_cnt;
        } while (y != u);
    }
}


vector<PII>edge1;
vector<PII>edge2;
void solve(){
    int n,m;cin>>n>>m;
    memset(h, -1, sizeof h);
    for(int i=0;i<=n;i++)root[i]=i;
    for(int i=0;i<m;i++){
        int a,b;string s;cin>>a>>b>>s;
        if(s=="Lun"){
            edge1.push_back({a,b});
            add(a,b);
            add(b,a);
        }else{
            edge2.push_back({a,b});
        }
    }

    for(int i=1;i<=n;i++){
        if(!dfn[i])
        tarjan(i,-1);
    }
    // for(int i=1;i<=n;i++)cout<<id[i]<<' ';cout<<endl;

    vector<PII>ans;
    for(auto [a,b]:edge1){
        if(id[a]==id[b]){
            merge(a,b);
            ans.push_back({a,b});
        }
    }

    for(auto [a,b]:edge2){
        if(find(a)!=find(b)){
            merge(a,b);
            ans.push_back({a,b});
        }
    }

    for(int i=1;i<=n;i++){
        if(find(i)!=find(1)){
            no;
            return;
        }
    }

    yes;
    cout<<ans.size()<<endl;
    for(auto [a,b]:ans){
        cout<<a<<' '<<b<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}