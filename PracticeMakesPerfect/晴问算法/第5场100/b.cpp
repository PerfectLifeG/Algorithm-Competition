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
const int INF=0x3f3f3f3f3f3f3f3f;
struct DSU {
    std::vector<int> root, siz;
    DSU(int n){
        root.resize(n);
        iota(root.begin(), root.end(), 0);
        siz.assign(n, 1);
    }
    int find(int a){
        if(a==root[a]) return a;
        return root[a]=find(root[a]);
    }
    void merge(int a,int b){
        a=find(a),b=find(b);
        if(a==b)return;
        if(a>b)swap(a,b);
        siz[a]+=siz[b];
        root[b]=a;
    }
    int size(int a){
        return siz[find(a)];
    }
};
void solve(){
    int n,m;cin>>n>>m;
    DSU dsu(n+1);
    int ans=n,cnt=1;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        if(dsu.find(a)!=dsu.find(b))ans--;
        dsu.merge(a,b);
        cnt=max(cnt,dsu.size(a));
        cnt=max(cnt,dsu.size(b));
        cout<<ans<<' '<<cnt<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}