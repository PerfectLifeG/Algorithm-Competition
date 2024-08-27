#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>v[n+1];
    for(int i=0;i<n-1;i++){
        int a,b,c;cin>>a>>b>>c;
        v[a].push_back({b});
        v[b].push_back({a});
    }
    vector<int>len(n+1);
    int mx=0;
    function<void(int,int)>dfs=[&](int t,int fa){
        int mx1=0,mx2=0;
        for(auto j:v[t]){
            if(j==fa)continue;
            dfs(j,t);
            len[t]=max(len[t],len[j]+1);
            if(mx1<=len[j]+1){
                mx2=mx1;
                mx1=len[j]+1;
            }else{
                mx2=max(mx2,len[j]+1);
            }
        }
        mx=max(mx,mx1+mx2);
    };
    dfs(1,0);
    cout<<mx<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}