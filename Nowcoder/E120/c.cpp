#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    vector<PII>v(n);
    vector<int>p(n);
    vector<int>now(n);
    for(int i=0;i<n;i++){cin>>a[i];v[i]={a[i],i};now[i]=i;p[i]=i;}
    sort(all(a));
    sort(all(v));
    if(n&1){
        if(a[n/2]+a[n/2]!=a[0]+a[n-1]){
            no;
            return;
        }
    }
    for(int i=0;i<n/2;i++){
        if(a[i]+a[n-i-1]!=a[0]+a[n-1]){
            no;
            return;
        }
    }
    vector<PII>ans;
    for(int i=0;i<n;i++){
        if(p[i]!=v[i].y){
            ans.push_back({i+1,now[v[i].y]+1});
            int t=p[i];
            swap(p[i],p[now[v[i].y]]);
            swap(now[t],now[v[i].y]);
        }
    }
    yes;
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i.x<<' '<<i.y<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}