#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=100010;
vector<int>v[N];
int u[N];
double now[N];
void solve(){
    int n;double p,r;
    cin>>n>>p>>r;r=0.01*r+1;
    for(int i=0;i<n;i++){
        int m;cin>>m;
        if(m==0)cin>>u[i];
        for(int j=0;j<m;j++){
            int a;cin>>a;
            v[i].push_back(a);
        }
    }
    double ans=0;
    function<void(int,int)> dfs=[&](int t,int fa){
        int flag=1;
        for(int j:v[t]){
            // if(j==t)continue;
            now[j]=now[t]*r;
            dfs(j,t);
            flag=0;
        }
        if(flag)ans+=p*now[t]*u[t];
    };
    now[0]=1;
    dfs(0,-1);
    printf("%.1lf",ans);

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}