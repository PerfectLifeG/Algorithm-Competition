#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>ru(n+1);
    vector<int>a(n+1);
    vector<int>v[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ru[a[i]]++;
        v[i].push_back(a[i]);
    }
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]!=i){
                no;
                return;
            }
        }
        yes;
        return;
    }
    function<int(int,int)> dfs=[&](int t,int fa)->int{
        int cnt=1;
        for(auto j:v[t]){
            if(j==fa||ru[j]==0)continue;
            ru[j]=0;
            cnt+=dfs(j,t);
        }
        return cnt;
    };
    function<void()> bfs=[&](){
        queue<int>q;
        for(int i=1;i<=n;i++){if(!ru[i])q.push(i);}
        while(q.size()){
            auto t=q.front();
            q.pop();
            for(auto j:v[t]){
                if(--ru[j]==0){q.push(j);}
            }
        }
    };

    bfs();
    // for(int i=1;i<=n;i++)cout<<ru[i]<<endl;
    for(int i=1;i<=n;i++){
        if(ru[i]){
            ru[i]=0;
            int cnt=dfs(i,0);
            if(cnt!=k){
                no;
                return;
            }
        }
    }
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}