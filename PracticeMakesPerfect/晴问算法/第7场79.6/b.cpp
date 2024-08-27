#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
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
    int n,k;cin>>n>>k;
    vector<PII>v;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    int ans=0;

    int t1=0,t2=0;
    sort(all(v),[&](PII a,PII b){
        return a.x+a.y>b.x+b.y;
    });
    for(int i=0;i<k;i++){
        t1+=v[i].x;
        t2+=v[i].y;
    }
    ans=max(ans,abs(t1)+abs(t2));

    sort(all(v),[&](PII a,PII b){
        return -a.x+a.y>-b.x+b.y;
    });
    t1=0,t2=0;
    for(int i=0;i<k;i++){
        t1+=v[i].x;
        t2+=v[i].y;
    }
    ans=max(ans,abs(t1)+abs(t2));

    sort(all(v),[&](PII a,PII b){
        return a.x-a.y>b.x-b.y;
    });
    t1=0,t2=0;
    for(int i=0;i<k;i++){
        t1+=v[i].x;
        t2+=v[i].y;
    }
    ans=max(ans,abs(t1)+abs(t2));

    sort(all(v),[&](PII a,PII b){
        return -a.x-a.y>-b.x-b.y;
    });
    t1=0,t2=0;
    for(int i=0;i<k;i++){
        t1+=v[i].x;
        t2+=v[i].y;
    }
    ans=max(ans,abs(t1)+abs(t2));
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}