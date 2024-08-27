#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=1000010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int root[N];
int val[N];
int find(int a){
    if(a==root[a]) return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a),rb=find(b);
    if(ra==rb){
        val[a]=b;
        return;
    }
    root[ra]=rb;
}
void solve(){
    int n,m;cin>>n>>m;
    unordered_map<int,int>mp;
    vector<int>v(n);
    vector<PII>v2;
    for(int i=0;i<n;i++){
        cin>>v[i];
        val[v[i]]=v[i];
        mp[v[i]]=1;
    }
    unordered_map<int,int>mp2;
    while(m--){
        int x,y;cin>>x>>y;
        v2.push_back({x,y});
        if(mp[x]==1){
            if(mp[y]==1){
                merge(x,y);
            }else if(mp2[y]!=0){
                merge(x,mp2[y]);
            }else{
                val[x]=y;
                mp2[y]=x;
            }
            mp[x]=0;
        }else if(mp2[x]!=0){
            if(mp[y]==1){
                merge(mp2[x],y);
            }else{
                val[mp2[x]]=y;
                mp2[y]=mp2[x];
                mp2[x]=0;
            }
        }
        // cout<<mp[x]<<' '<<mp[y]<<' '<<mp2[x]<<' '<<mp2[y]<<' '<<val[x]<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<val[find(v[i])]<<' ';
    }cout<<endl;
    for(int i=0;i<n;i++){
        root[v[i]]=v[i];
        val[v[i]]=v[i];
    }
    for(int i=0;i<m;i++){
        root[v2[i].x]=v2[i].x;
        root[v2[i].y]=v2[i].y;
        val[v2[i].x]=v2[i].x;
        val[v2[i].y]=v2[i].y;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    for(int i=0;i<=N-1;i++)root[i]=i;
    while(_--)solve();
    return 0;
}