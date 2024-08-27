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
    int n,q;cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int x;cin>>x;
    }

    int tr[n+1]={};
    int book[n+1]={};
    int dp[n+1]={};
    vector<int>p(n+1);int idx=1;
    function<void(int)> build=[&](int u){
        if(u>n)return;
        cin>>tr[u];
        p[idx++]=tr[u];
        book[tr[u]]=u;
        build(u*2);
        build(u*2+1);
        if(u*2<=n){
            if(dp[u*2]&dp[u*2+1]){
                if(tr[u*2]/2==tr[u]&&tr[u*2+1]/2==tr[u])dp[u]=1;
            }
        }
        else dp[u]=1;
    };
    build(1);

    // for(int i=1;i<=n;i++)cout<<i<<' '<<dp[i]<<' '<<tr[i]<<' '<<book[i]<<endl;
    while(q--){
        int x,y;cin>>x>>y;
        int tx=x,ty=y;
        x=p[x],y=p[y];
        swap(p[tx],p[ty]);
        // cout<<x<<' '<<y<<endl;
        int px=book[x],py=book[y];
        swap(tr[px],tr[py]);
        swap(book[x],book[y]);
        // cout<<x<<' '<<y<<' '<<px<<' '<<py<<endl;
        while(px){
            if(px*2<=n){
                if(dp[px*2]&dp[px*2+1]){
                    if(tr[px*2]/2==tr[px]&&tr[px*2+1]/2==tr[px])dp[px]=1;
                    else dp[px]=0;
                }else dp[px]=0;
            }else dp[px]=1;
            px/=2;
        }
        while(py){
            if(py*2<=n){
                if(dp[py*2]&dp[py*2+1]){
                    if(tr[py*2]/2==tr[py]&&tr[py*2+1]/2==tr[py])dp[py]=1;
                    else dp[py]=0;
                }else dp[py]=0;
            }else dp[py]=1;
            py/=2;
        }

    // for(int i=1;i<=n;i++)cout<<i<<' '<<dp[i]<<' '<<tr[i]<<' '<<book[i]<<endl;

        if(dp[1])yes;
        else no;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}