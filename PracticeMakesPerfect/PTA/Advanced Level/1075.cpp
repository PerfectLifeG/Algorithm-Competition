#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=10010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Node{
    int id;
    vector<int>v;
    int sum;
    int cnt;
}node[N];
int idx;
void solve(){
    int n,k,m;cin>>n>>k>>m;
    vector<int>pro(k+1);
    for(int i=1;i<=k;i++){
        cin>>pro[i];
    }
    unordered_map<int,int>mp;
    while(m--){
        int a,b,c;cin>>a>>b>>c;
        if(mp.count(a)){
            node[mp[a]].v[b]=max(node[mp[a]].v[b],c);
        }else {
            mp[a]=idx++;
            node[mp[a]].id=a;
            node[mp[a]].v.resize(k+1,-2);
            node[mp[a]].v[b]=c;
        }
    }
    vector<int>ans;
    for(auto [p,j]:mp){
        int sum=-1,cnt=0;
        auto &t=node[j].v;
        for(int i=1;i<t.size();i++){
            if(t[i]>=0){
                if(sum==-1)sum=0;
                sum+=t[i];
                if(t[i]==pro[i])cnt++;
            }else if(t[i]==-1)t[i]=0;
        }
        node[j].sum=sum;
        node[j].cnt=cnt;
        if(sum!=-1)ans.push_back(p);
    }
    sort(all(ans),[&](int a,int b){
        auto &ta=node[mp[a]];
        auto &tb=node[mp[b]];
        if(ta.sum!=tb.sum){
            return ta.sum>tb.sum;
        }
        if(ta.cnt!=tb.cnt){
            return ta.cnt>tb.cnt;
        }
        return ta.id<tb.id;
    });
    int rank=0;
    int lst=-1;
    for(int i=0;i<ans.size();i++){
        auto &t=node[mp[ans[i]]];
        if(t.sum!=lst)rank=i+1;
        cout<<rank;
        printf(" %05d %d",t.id,t.sum);
        for(int j=1;j<t.v.size();j++){
            if(t.v[j]!=-2){
                cout<<' '<<t.v[j];
            }else cout<<" -";
        }
        lst=t.sum;
        cout<<endl;
    }
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}