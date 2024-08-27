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
const int N=5e5+10;
const int M=1e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int n;
int val[N];
int dfn[N];int idx=1;
int adfn[N];int sz[N];
int son[N];int book[N];
int cnt[M];
int h[M],e[M],ne[M],idx2;
int ans[N];

int tr[M+1];
void add1(int t,int val){
    for(int i=t;i<M;i+=lowbit(i)){
        tr[i]+=val;
    }
}
int query1(int t){
    int res=0;
    for(int i=t;i;i-=lowbit(i)){
        res+=tr[i];
    }
    return res;
}

void add(int a,int b){
    e[idx2]=b;
    ne[idx2]=h[a];
    h[a]=idx2++;
}
int dfs1(int t,int fa){
    sz[t]=1;
    dfn[t]=idx;
    adfn[idx++]=t;
    for(int i=h[t];~i;i=ne[i]){
        int j=e[i];
        if(j==fa)continue;
        sz[t]+=dfs1(j,t);
        if(sz[j]>sz[son[t]])son[t]=j;
    }
    return sz[t];
}

// int x,p,sum;
void dfs2(int t,int fa){
    for(int i=h[t];~i;i=ne[i]){
        int j=e[i];
        if(j==fa||j==son[t])continue;
        dfs2(j,t);
    }

    if(son[t]) dfs2(son[t],t);
    for(int i=h[t];~i;i=ne[i]){
        int j=e[i];
        if(j==fa||j==son[t])continue;
        for(x=dfn[j];x<dfn[j]+sz[j];x++){
            p=adfn[x];
            int x=(sum-cnt[val[p]])*val[p];
            ans[t]+=x-query(val[p]-1)+-query(M)-query(val[p])+query(val[p]-1);
            add(val[p],val[p]);
            cnt[val[p]]++;
            sum++;
        }
    }

    st.insert(val[t]);
    cnt[val[t]]++;
    // x=0,sum=0;
    ans[t]=query(M);
    // for(auto &i:st){
    //     // cout<<t<<' '<<i<<' '<<lst<<' '<<cnt[i]<<' '<<ans[t]<<endl;
    //     ans[t]+=((x)*i-sum)*cnt[i]*i*2;
    //     sum+=i*cnt[i];
    //     x+=cnt[i];
    // }

    if(!book[t]){
        st.erase(val[t]);
        cnt[val[t]]--;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(j==fa)continue;
            for(x=dfn[j];x<dfn[j]+sz[j];x++){
                p=adfn[x];
                st.erase(val[p]);
                cnt[val[p]]--;
            }
        }
    }
}

void solve(){
    memset(h,-1,sizeof(h));
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<=n;i++)cin>>val[i];
    dfs1(1,1);
    for(int i=1;i<=n;i++)book[son[i]]=1;
    dfs2(1,1);
    int res=0;
    for(int i=1;i<=n;i++){
        // cout<<ans[i]<<' ';
        res^=ans[i];
    }
    cout<<res<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}