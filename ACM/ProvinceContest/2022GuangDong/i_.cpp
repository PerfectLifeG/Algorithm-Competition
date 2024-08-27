#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=1000100;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    unordered_map<int,PII>mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;cin>>a;
            mp[a]={i,j};
        }
    }
    set<PII>st;
    st.insert({0,0});
    st.insert({n-1,m-1});
    for(int i=0;i<n*m;i++){
        if(mp[i].x==0&&mp[i].y==0||mp[i].x==n-1&&mp[i].y==m-1)continue;
        auto t=st.lower_bound(mp[i]);
        // cout<<t->x<<' '<<t->y<<endl;
        // cout<<prev(t)->x<<' '<<prev(t)->y<<endl;
        if(mp[i].x>=prev(t)->x&&mp[i].x<=t->x&&mp[i].y>=prev(t)->y&&mp[i].y<=t->y){
            st.insert(mp[i]);
        }else {
            cout<<i<<endl;
            return;
        }
    }
    cout<<n*m<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}