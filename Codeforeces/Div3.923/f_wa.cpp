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
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<PII>v[n+1];
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    vector<int>ans;
    vector<int>book(n+1);
    function<int(int,int)> dfs1=[&](int t,int fa)->int{
        if(book[t]==1){
            book[t]=2;
            return t;
        }
        book[t]=1;
        for(auto [j,w]:v[t]){
            if(j==fa)continue;
            if(book[j]==3)continue;
            int p=dfs1(j,t);
            if(p){
                book[t]=2;
                return p;
            }
        }
        return 0;
    };
    vector<int>tmp;
    int mn=1e9;
    function<void(int,int,int)> dfs2=[&](int t,int fa,int now){
        // cout<<t<<' '<<now<<' '<<book[t]<<endl;
        if(book[t]==3){
            if(now<mn){
                mn=now;
                ans=tmp;
            }
            return;
        }
        book[t]=3;
        tmp.push_back(t);
        for(auto [j,w]:v[t]){
            // cout<<t<<' '<<fa<<' '<<j<<' '<<w<<' '<<book[j]<<endl;
            if(j==fa)continue;
            if(book[j]<2)continue;
            dfs2(j,t,min(now,w));
        }
    };
    for(int i=1;i<=n;i++){
        if(!book[i]){
            int t=dfs1(i,-1);
    // for(int i=1;i<=n;i++)cout<<i<<' '<<book[i]<<endl;
        // cout<<t<<endl;
            if(t){
                tmp.clear();
                dfs2(t,-1,1e9);
            }
    // for(int i=1;i<=n;i++)cout<<i<<' '<<book[i]<<endl;
        }
    }


    cout<<mn<<' '<<ans.size()<<endl;
    for(auto i:ans)cout<<i<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}