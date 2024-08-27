#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int a,b;cin>>a>>b;
    vector<array<int,3>>ans;
    
    function<void(int,int,int,int)> dfs=[&](int x,int y,int a,int b){
        if(a==b){
            ans.push_back({x,y,a});
            return;
        }else if(a>b){
            ans.push_back({x,y,b});
            dfs(x+b,y,a-b,b);
        }else{
            ans.push_back({x,y,a});
            dfs(x,y+a,a,b-a);
        }
    };

    dfs(0,0,a,b);
    cout<<"Yes"<<endl;
    cout<<ans.size()<<endl;
    for(auto [u,v,w]:ans){
        cout<<u<<' '<<v<<' '<<w<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}