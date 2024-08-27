#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin()+1,x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
struct Node{
    int a,b;
};
void solve(){
    int n,k;cin>>n>>k;
    priority_queue<int>q;
    vector<Node>v(n+1);
    vector<int>a(n+1);
    vector<int>b(n+1);
    vector<int>pre(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        v[i]={a[i],b[i]};
    }
    sort(all(v),[&](Node &a,Node &b){
        if(a.b==b.b)return a.a>b.a;
        return a.b>b.b;
    });
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+max(0ll,v[i].b-v[i].a);
    }

    int ans=0;
    int sum=0;
    if(k==0)ans=max(ans,pre[n]);
    for(int i=1;i<=n;i++){
        q.push(v[i].a);
        sum+=v[i].a;
        if(q.size()>k){
            sum-=q.top();
            q.pop();
        }
        if(q.size()==k)ans=max(ans,pre[n]-pre[i]-sum);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}