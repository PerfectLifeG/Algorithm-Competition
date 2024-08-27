#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=10000;
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
    vector<int>s(N);
    vector<int>area(N);
    set<int>st;
    for(int i=0;i<n;i++){
        int id,fa,ma;cin>>id>>fa>>ma;
        if(fa!=-1){dsu.merge(id,fa);st.insert(fa);}
        if(ma!=-1){dsu.merge(id,ma);st.insert(ma);}
        st.insert(id);
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int child;cin>>child;
            dsu.merge(id,child);
            st.insert(child);
        }
        int a,b;cin>>a>>b;
        s[id]+=a;
        area[id]+=b;
    }
    unordered_map<int,int>mp;
    for(auto i:st){
        mp[dsu.find(i)]++;
        if(i!=dsu.find(i)){
            s[dsu.find(i)]+=s[i];
            area[dsu.find(i)]+=area[i];
        }
    }
    vector<int>ans;
    for(auto [i,j]:mp)ans.push_back(i);
    sort(all(ans),[&](int a,int b){
        if(1.0*area[a]/dsu.size(a)!=1.0*area[b]/dsu.size(b))return 1.0*area[a]/dsu.size(a)>1.0*area[b]/dsu.size(b);
        return a<b;
    });
    cout<<ans.size()<<endl;
    for(auto i:ans){
        printf("%04d",i);
        cout<<fixed<<setprecision(3)<<' '<<dsu.size(i)<<' '<<1.0*s[i]/dsu.size(i)<<' '<<1.0*area[i]/dsu.size(i)<<endl;
    }
}   
signed main(){
    int _=1;
    while(_--)solve();
    return 0;
}