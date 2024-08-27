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
    int n;cin>>n;
    map<int,PII,greater<int>>mp;
    vector<PII>v;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;y=-y;
        v.push_back({x,y});
    }
    sort(all(v));
    vector<int>a(n);
    for(int i=0;i<n;i++){
        a[i]=v[i].y;
        if(mp.count(a[i])){
            mp[a[i]]={min(i,mp[a[i]].x),max(i,mp[a[i]].y)};
        }else mp[a[i]]={i,i};
    }

    int ans=mp.begin()->first;
    int mn=INF;
    int mx=mp.begin()->first;
    int l=mp.begin()->second.x,r=mp.begin()->second.y;
    for(int i=l;i<=r;i++){
        mn=min(mn,a[i]);
    }
    int x=0;
    for(auto it=mp.begin();it!=mp.end();){
        auto [i,j]=*it;
        while(l>j.x){l--;mn=min(mn,a[l]);}
        while(r<j.y){r++;mn=min(mn,a[r]);}
        if(x+i-(++it)->first>=mn){
            ans=min(ans,mx-mn);
            break;
        }else{
            ans=it->first;
            x+=i-it->first;
        }
        // cout<<i<<' '<<j.x<<' '<<j.y<<' '<<l<<' '<<r<<' '<<mn<<' '<<ans<<endl;
    }
    cout<<-ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}