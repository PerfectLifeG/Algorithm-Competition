#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010,INF=3e8+10;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
void solve(){
    int n,m;cin>>n>>m;
    set<double>s{INF,-INF};;
    for(int i=0;i<n;i++){
        double k;cin>>k;
        s.insert(k);
    }
    // for(auto i:s)cout<<i<<' ';
    // cout<<endl;
    for(int j=0;j<m;j++){
        int a,b,c;cin>>a>>b>>c;
        if(c<=0){no;continue;}
        double t=sqrt(4*a*c);
        double k1=b+t;double k2=b-t;
        int p=*prev(s.lower_bound(k1));
        if(p>k2){
            yes;
            cout<<p<<endl;
        }else no;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}