#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x&(-x))
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

int tr[N+1];
void add(int u,int val){
    for(int i=u;i<=N;i+=lowbit(i)){
        tr[i]+=val;
    }
}
int query(int u){
    int res=0;
    for(int i=u;i;i-=lowbit(i)){
        res+=tr[i];
    }
    return res;
}

void solve(){
    int n,x;cin>>n>>x;
    vector<int>v1,v2;
    vector<array<int,3>>a;
    for(int i=0;i<n;i++){
        int l,r,y;cin>>l>>r>>y;
        a.push_back({l,r,y});
        v1.push_back(l);
        v1.push_back(r);
        v2.push_back(y);
    }
    unordered_map<int,int>mp1,mp2;
    sort(all(v1));sort(all(v2));
    v2.erase(unique(v2.begin(),v2.end()),v2.end());
    int idx=1;
    for(auto i:v2)mp2[i]=idx++;
    v1.erase(unique(v1.begin(),v1.end()),v1.end());
    idx=1;
    for(auto i:v1)mp1[i]=idx++;

    vector<vector<int>> v(idx);
    for(int i=0;i<n;i++){
        v[mp1[a[i][0]]].push_back(a[i][2]);
        v[mp1[a[i][1]]].push_back(-a[i][2]);
    }

    int ans=0;
    multiset<int>st{-INF,INF};
    for(int i=1;i<idx;i++){
        // cout<<i<<endl;
        for(auto j:v[i]){
            // cout<<i<<' '<<j<<' '<<mp2[abs(j)]<<endl;
            if(j>0){
                add(mp2[j],j);
                st.insert(j);
            }else{
                add(mp2[-j],j);
                st.erase(st.find(-j));
            }
        }
        // cout<<st.size()<<endl;
        // cout<<endl;
        int w=x;
        int lst=0;
        while(1){
            int p=*prev(st.upper_bound(w));
            // cout<<w<<' '<<lst<<' '<<p<<' '<<mp2[p]<<' '<<query(mp2[p])<<endl;
            if(p==-INF||mp2[p]<=lst)break;
            w+=query(mp2[p])-query(lst);
            lst=mp2[p];
        }
        ans=max(ans,w);
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;


}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}