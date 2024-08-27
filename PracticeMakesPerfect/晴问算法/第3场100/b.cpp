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
void solve(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    set<PII>st[m];
    for(int i=0;i<m;i++){
        int l,r;cin>>l>>r;
        // cout<<l<<' '<<r<?<endl;
        // cout<<s<<endl;
        reverse(s.begin()+l,s.begin()+r+1);
        // cout<<s<<endl;
        int x=0,y=0;
        st[i].insert({x,y});
        for(auto j:s){
            if(j=='L'){
                x--;
            }
            if(j=='R'){
                x++;
            }
            if(j=='U'){
                y++;
            }
            if(j=='D'){
                y--;
            }
            // cout<<x<<' '<<y<<endl;
            st[i].insert({x,y});
        }
    }
    int q;cin>>q;
    while(q--){
        int v;int x,y;
        cin>>v>>x>>y;
        // cout<<v<<' '<<x<<' '<<y<<endl;
        if(st[v].count({x,y})){
            yes;
        }else no;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}