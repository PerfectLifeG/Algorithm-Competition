#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin()+1,x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(n+m+2);
    vector<int>b(n+m+2);
    vector<PII>v(n+m+2);
    for(int i=1;i<=n+m+1;i++){
        cin>>a[i];
    }


    int sum=0;
    for(int i=1;i<=n+m+1;i++){
        cin>>b[i];
        sum+=b[i];
    }
    for(int i=1;i<=n+m+1;i++){
        v[i]={i,a[i]-b[i]};
    }
    sort(all(v),[&](PII a1,PII a2){
        return a1.y>a2.y;
    });
    vector<int>pre(n+m+2);
    for(int i=1;i<=n+m+1;i++){
        pre[i]=pre[i-1]+v[i].y;
    }


    int ans[n+m+2];
    for(int i=1;i<=n+m+1;i++){
        if(i<=n){
            ans[v[i].x]=pre[n+1]+sum-a[v[i].x];
        }else ans[v[i].x]=pre[n]+sum-b[v[i].x];
    }

    for(int i=1;i<=n+m+1;i++)cout<<ans[i]<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}