#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>v[n+1];
    vector<int>v2[n+1];
    vector<int>ru(n+1);
    vector<int>book(n+1);
    vector<int>book2(n+1);//huan
    vector<int>cnt(n+1);//huan

    for(int i=1;i<=n;i++){
        int a;cin>>a;
        v[i].push_back(a);
        ru[a]++;
        v2[a].push_back(i);
    }

    queue<int>q;
    for(int i=1;i<=n;i++){
        if(!ru[i]){
            q.push(i);
        }
    }
    while(q.size()){
        auto t=q.front();
        book[t]=1;
        q.pop();
        for(auto j:v[t]){
            if(--ru[j]==0){
                q.push(j);
            }
        }
    }
    vector<int>r;
    for(int i=1;i<=n;i++){
        if(!book[i]){
            r.push_back(i);
        }
    }

    function<int(int,int)> dfs1=[&](int t,int sz)->int{
        book2[t]=1;
        for(auto j:v[t]){
            if(book[j]||book2[j])continue;
            int p=dfs1(j,sz+1);
            cnt[t]=max(cnt[t],p);
        }
        return cnt[t]=max(cnt[t],sz);
    };

    int tt=0;
    function<void(int,int)> dfs2=[&](int t,int dep){
        for(auto j:v2[t]){
            if(!book[j])continue;
            dfs2(j,dep+1);
        }
        tt=max(tt,dep);
    };

    int ans=0;
    for(auto i:r){
        dfs1(i,1);
        tt=0;
        dfs2(i,0);
        ans=max(tt+cnt[i],ans);
        // cout<<i<<' '<<cnt[i]<<' '<<tt<<endl;
    }
    cout<<ans<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}