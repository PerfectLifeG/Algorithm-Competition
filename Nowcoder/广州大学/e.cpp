#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=2e6+10;
const int mod=998244353;

char buf[1 << 21], *p1 = buf, *p2 = buf, obuf[1 << 21], *o = obuf, of[35];
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
 
inline int read()
{
  int s = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) s = s * 10 + c - '0';
  return s * f;
}

int h[N],e[N],ne[N],id;
void add(int a,int b){
    e[id]=b;
    ne[id]=h[a];
    h[a]=id++;
}

int cnt[N];
int dfn[N];
int adfn[N];
int son[N];
int val[N];
int sz[N];
int book[N];
int idx=1;
int dfs1(int t){
    sz[t]=1;
    dfn[t]=idx;
    adfn[idx++]=t;
    for(int i=h[t];~i;i=ne[i]){
        int j=e[i];
        sz[t]+=dfs1(j);
        if(sz[j]>sz[son[t]])son[t]=j;
    }
    return sz[t];
}
int ans,now;
bool dfs2(int t){
    bool f=0;
    for(int i=h[t];~i;i=ne[i]){
        int j=e[i];
        if(j==son[t])continue;
        if(dfs2(j))f=1;
    }
    if(son[t])if(dfs2(son[t]))f=1;
    if(!f)for(int i=h[t];~i;i=ne[i]){
        int j=e[i];
        if(j==son[t])continue;
        for(int q=dfn[j];q<dfn[j]+sz[j];q++){
            int p=adfn[q];
            if(!cnt[val[p]])cnt[val[p]]=1;
            else{
                f=1;
                break;
            }
        }
        if(f)break;
    }
    if(!f&&!cnt[val[t]])ans++,cnt[val[t]]=1;
    else f=1;
    if(!book[t]){
        cnt[val[t]]=0;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            for(int q=dfn[j];q<dfn[j]+sz[j];q++){
                int p=adfn[q];
                cnt[val[p]]=0;
            }
        }
    }
    return f;
}
void solve(){
    int n;n=read();
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++)val[i]=read();
    for(int i=2;i<=n;i++){
        int a;a=read();
        add(a,i);
    }
    dfs1(1);
    for(int i=1;i<=n;i++)book[son[i]]=1;
    dfs2(1);
    printf("%d",ans);
}
signed main(){
    int _=1;
    while(_--)solve();
    return 0;
}