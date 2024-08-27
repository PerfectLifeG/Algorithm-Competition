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
void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(n);
    unordered_map<int,int>st;
    for(int i=0;i<n;i++){
        cin>>a[i];
        st[a[i]]++;
        v[a[i]].push_back(i);
    }
    while(m--){
        int x,y;cin>>x>>y;
        if(x==y)continue;
        if(!st.count(x))continue;
        st.erase(x);st[y]++;
        if(v[x].size()<=v[y].size()){
            for(auto i:v[x])v[y].push_back(i);
        }else{
            for(auto i:v[y])v[x].push_back(i);
            swap(v[x],v[y]);
        }
        v[x].clear();
    }
    for(auto [i,x]:st){
        for(auto j:v[i]){
            a[j]=i;
        }
        v[i].clear();
    }
    for(int i=0;i<n;i++)cout<<a[i]<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}