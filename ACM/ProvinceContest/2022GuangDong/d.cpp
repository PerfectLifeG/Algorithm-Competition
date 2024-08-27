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
    int n,m;cin>>n>>m;
    int ans=0;
    vector<PII>v(n);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        if(n==1){
            cout<<b<<endl;
            return;
        }
        v[i]={a,b};
        ans+=a;
    }
    int t;
    if(m-n>=n-1) t=n;
    else t=m-n;
    sort(v.begin(),v.end(),[&](PII a,PII b){
        return a.y-a.x>b.y-b.x;
    });
    for(int i=0;i<t&&i<v.size();i++){
        if(v[i].y-v[i].x>=0){
            ans+=v[i].y-v[i].x;
        }
        else {
            if(n-i==1){
                ans=max(ans+v[i].y-v[i].x,ans+v[i-1].x-v[i-1].y);
            }
            break;
        }
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