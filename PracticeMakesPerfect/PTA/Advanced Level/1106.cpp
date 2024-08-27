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
const int N=100010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
vector<int>v[N];
void solve(){
    int n;cin>>n;
    double p,r;cin>>p>>r;r=0.01*r+1;
    for(int i=0;i<n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int a;cin>>a;
            v[i].push_back(a);
        }
    }
    int cnt=0;
    int ans=INF;
    function<void(int,int)> dfs=[&](int t,int depth){
        int flag=1;
        for(auto j:v[t]){
            dfs(j,depth+1);
            flag=0;
        }
        if(flag){
            if(ans>depth){
                cnt=1;
                ans=depth;
            }else if(ans==depth)cnt++;
        }
    };
    dfs(0,0);
    cout<<fixed<<setprecision(4)<<p*pow(r,ans)<<' '<<cnt<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}