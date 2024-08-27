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
const int N=1e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
vector<int>v[N];
int root[N];
void solve(){
    int n,m;cin>>n>>m;
    int ans=0;
    vector<int>a(n+2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)if(a[i]!=a[i-1])ans++;
    while(m--){
        int op;cin>>op;
        if(op==1){
            int x,y;cin>>x>>y;
            if(x==y)continue;
            int tx=x,ty=y;
            x=root[x],y=root[y];
            if(v[x].size()<=v[y].size()){
                for(auto i:v[x]){
                    if(a[i-1]==y)ans--;
                    if(a[i+1]==y)ans--;
                }
                for(auto i:v[x])a[i]=y;
                v[y].insert(v[y].end(),v[x].begin(),v[x].end());
                v[x].clear();
            }else{
                for(auto i:v[y]){
                    if(a[i-1]==x)ans--;
                    if(a[i+1]==x)ans--;
                }
                for(auto i:v[y])a[i]=x;
                v[x].insert(v[x].end(),v[y].begin(),v[y].end());
                v[y].clear();
                swap(root[tx],root[ty]);
            }
        }else{
            cout<<ans<<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    for(int i=0;i<N;i++)root[i]=i;
    while(_--)solve();
    return 0;
}