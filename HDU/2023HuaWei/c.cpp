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
    int n,x,y,r;cin>>n>>x>>y>>r;
    int v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    set<int>st;
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            st.insert(i*x+j*y);
        }
    }
    // for(auto i:st)cout<<i<<' ';cout<<endl;
    sort(v,v+n);
    int ans=0;
    int i=0;
    for(;i<n;i++){
        if(r<=0)break;
        if(r>=v[i]){
            int t=*prev(st.upper_bound(v[i]));
            r-=t;
            v[i]-=t;
            ans+=v[i]*v[i];
        }else{
            int t=*st.lower_bound(r);
            if(t>v[i])t=*prev(st.upper_bound(r));
            v[i]-=t;
            r-=t;
            ans+=v[i]*v[i];
        }
    }
    if(r>0){cout<<-1<<endl;return;}
    for(;i<n;i++)ans+=v[i]*v[i];
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}