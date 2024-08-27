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
void solve()
{
    int n,k;cin>>n>>k;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<PII>v;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v.push_back({j-i+1,abs(b[j]-a[i])+abs(b[j]-a[i])});
        }
    }
    sort(all(v),[&](PII i,PII j){
        if(i.x==j.x)return i.y>j.y;
        return i.x<j.x;
    });
    int t=0;
    for(int i=0;i<k;i++){
        t+=v[i].y;
        if(t==k)break;
        ans+=v[i].x;
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