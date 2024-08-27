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
    int n,p;cin>>n>>p;
    vector<int>a(n);
    vector<int>b(n);
    vector<PII>v(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        v[i]={b[i],a[i]};
    }
    sort(all(v));
    int ans=0;
    int i=0;
    int m=n;
    for(;i<n;i++){
        if(m<=0||v[i].x>=p){
            break;
        }
        if(m<=v[i].y){
            ans+=(m-1)*v[i].x+p;
        }else ans+=v[i].y*v[i].x;
        m-=v[i].y;
    }
    if(m<=0)cout<<ans<<endl;
    else cout<<ans+m*p<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}