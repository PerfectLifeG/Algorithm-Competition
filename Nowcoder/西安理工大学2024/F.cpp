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
struct BIT {
    #define lowbit(x) (x&(-x))
    int n;
    vector<int>tr;
    BIT(int size){
        n = size;
        tr.resize(size + 1, 0);
    }
    void add(int t,int val){
        for(int i=t;i<=n;i+=lowbit(i)){
            tr[i]+=val;
        }
    }
    int query(int t){
        int ret=0;
        for(int i=t;i;i-=lowbit(i)){
            ret+=tr[i];
        }
        return ret;
    }
};
void solve(){
    int n,q,m;cin>>n>>q>>m;
    BIT tr(N);
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tr.add(a[i],1);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=tr.query(m/a[i]);
        if(a[i]<=m/a[i])ans++;
    }
    ans/=2;
    while(q--){
        int op;cin>>op;
        if(op==1){
            int p,x;cin>>p>>x;
            // cout<<a[p]<<' '<<x<<' ';
            // cout<<m/a[p]<<' '<<m/x<<endl;
            ans-=tr.query(m/a[p]);
            tr.add(a[p],-1);
            tr.add(x,1);
            ans+=tr.query(m/x);
            // ans+=-tr.query(min(N-1,x*m-1))+tr.query(min(N-1,a[p]*m-1));
            a[p]=x;
        }else{
            cout<<ans<<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}