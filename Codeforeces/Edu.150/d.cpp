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
    int n;cin>>n;
    vector<PII>v;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    sort(all(v));
    // for(auto i:v)cout<<i.x<<' '<<i.y<<endl;
    int ans=0;
    for(int i=0;i<v.size();){
        int j=i+1;
        int mn=min(v[i].y,v[j].y);
        int mx=max(v[i].y,v[j].y);
        if(j<v.size()&&v[j].x<=v[i].y)j++;
        else ans++;
        while(j<v.size()&&v[j].x<=mx){
            // cout<<i<<' '<<j<<' '<<mn<<' '<<mx<<endl;
            if(v[j].y>=mx){ans++;j++;continue;}
            if(v[j].x<=mn)mx=max(mn,v[j].y),mn=min(mn,v[j].y);
            ans++;
            j++;
        }
        // cout<<i<<' '<<ans<<endl;
        i=j;
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