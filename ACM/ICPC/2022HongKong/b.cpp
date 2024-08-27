#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>v[n+1];
    int root;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        if(a==0){root=i;continue;}
        v[a].push_back(i);
    }
    vector<int>cnt(n+1);
    function<int(int,int)>dfs=[&](int t,int fa)->int{
        cnt[t]=1;
        int mx=1,c=0;
        // cout<<t<<' '<<cnt[t]<<endl;
        for(auto j:v[t]){
            if(j==fa)continue;
            int r=dfs(j,t);
            if(r==mx){
                c++;
            }else if(r>mx){
                mx=r;
                c=1;
            }
        }
        if(c>1){
            cnt[t]=mx+1;
        }else cnt[t]=mx;
        return cnt[t];
    };
    dfs(root,0);
    // cout<<root<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<i<<' '<<cnt[i]<<endl;
    // }
    cout<<cnt[root]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}