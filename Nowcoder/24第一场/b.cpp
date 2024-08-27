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
const int N=1e5+7;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
vector<array<int,3>>edge;
vector<int>vv;
int mp[N];
int flag;
int k;
unordered_map<int,int>g;
int prim(){
    vector<int>book(k);
    vector<int>d(k,INF);d[0]=0;
    int res=0;
    for(int kk=0;kk<k;kk++){
        int t,mn=INF;
        for(int i=0;i<k;i++){
            if(!book[i]&&mn>=d[i]){
                mn=d[i];
                t=i;
            }
        }
        if(book[t])continue;
        book[t]=1;
        res+=mn;
        if(res>=INF/2){flag=1;return 0;}
        for(int j=0;j<k;j++){
            if(!book[j]){
                d[j]=min(d[j],g[min(vv[t],vv[j])|(max(vv[t],vv[j])<<31ll)]);
            }
        }
    }
    return res;
}
int root[N];
int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a),rb=find(b);
    root[ra]=rb;
}
int kruskal(){
    int res=0;
    int cnt=0;
    for(auto [w,i,j]:edge){
        if(mp[i]!=-1&&mp[j]!=-1){
            if(find(i)!=find(j)){
                merge(i,j);
                res+=w;
                cnt++;
            }
        }
    }
    if(cnt!=k-1)flag=1;
    return res;
}
void solve(){
    int n,m,q;cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        if(a<b)swap(a,b);
        int x=(a<<31ll)|b;
        if(!g.count(x))g[x]=c;
        else g[x]=min(g[x],c);
        edge.push_back({c,a,b});
    }
    sort(all(edge));
    for(int i=0;i<N;i++)mp[i]=-1;
    while(q--){
        cin>>k;
        vv.clear();
        for(int i=0;i<k;i++){int a;cin>>a;vv.push_back(a);mp[a]=i;root[a]=a;}
        int ans=0;flag=0;
        if(k*k>=n){
            ans=kruskal();
        }else{
            ans=prim();
        }
        if(flag)cout<<-1<<endl;
        else cout<<ans<<endl;
        for(int i=0;i<k;i++)mp[vv[i]]=-1;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}