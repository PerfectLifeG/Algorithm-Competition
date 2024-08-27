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
const int N=10010;
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
        if(a>b)swap(a,b);
        if(a==b)return;
        siz[a]+=siz[b];
        root[b]=a;
    }
    int size(int a){
        return siz[find(a)];
    }
};
void solve(){
    int n;cin>>n;
    DSU dsu(N);
    set<int>st;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        int a;cin>>a;
        st.insert(a);
        for(int j=1;j<k;j++){
            int b;cin>>b;
            st.insert(b);
            dsu.merge(a,b);
        }
    }
    int cnt=0;int ans=0;
    for(auto i:st){
        if(dsu.find(i)==i){cnt++;ans+=dsu.size(i);}
    }
    cout<<cnt<<' '<<ans<<endl;
    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;
        if(dsu.find(a)!=dsu.find(b))no;
        else yes;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}