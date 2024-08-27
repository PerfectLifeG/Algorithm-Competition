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
    int n,m;cin>>n>>m;
    vector<array<int,3>>v[n];
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        int op;cin>>op;
        int len,t;cin>>len>>t;
        v[a].push_back({b,len,t});
        if(op==0){
            v[b].push_back({a,len,t});
        }
    }
    int st,ed;cin>>st>>ed;

    vector<int>d(n,INF);d[st]=0;
    vector<int>ti(n,INF);ti[st]=0;
    function<void(int)> Dijkstra=[&](int flag){
        vector<int>book(n);
        priority_queue<PII,vector<PII>,greater<PII>>q;
        q.push({0,st});
        while(q.size()){
            auto [dis,t]=q.top();
            q.pop();
            if(book[t])continue;
            book[t]=1;
            for(auto [j,d1,d2]:v[t]){
                if(book[j])continue;
                if(flag){
                    if(d[j]>dis+d1){
                        d[j]=dis+d1;
                        q.push({d[j],j});
                    }
                }else{
                    if(ti[j]>dis+d2){
                        ti[j]=dis+d2;
                        q.push({ti[j],j});
                    }
                }
            }
        }
    };

    Dijkstra(0);Dijkstra(1);
    // for(int i=0;i<n;i++)cout<<d[i]<<' ';cout<<endl;
    // for(int i=0;i<n;i++)cout<<ti[i]<<' ';cout<<endl;
    // return;

    int mnti=INF;
    vector<int>ans1;
    vector<int>ans2;
    vector<int>tmp;
    function<void(int,int,int)> dfs1=[&](int t,int len,int time){
        if(len>d[t])return;
        if(t==ed){
            if(time<mnti){
                mnti=time;
                ans1=tmp;
            }
            return;
        }
        tmp.push_back(t);
        for(auto [j,a,b]:v[t]){
            dfs1(j,len+a,time+b);
        }
        tmp.pop_back();
    };
    function<void(int,int)> dfs2=[&](int t,int time){
        if(time>ti[t])return;
        if(t==ed){
            if(!ans2.size()||ans2.size()>tmp.size()){
                ans2=tmp;
            }
            return;
        }
        tmp.push_back(t);
        for(auto [j,a,b]:v[t]){
            dfs2(j,time+b);
        }
        tmp.pop_back();
    };

    dfs1(st,0,0);
    dfs2(st,0);
    if(ans1==ans2){
        cout<<"Distance = "<<d[ed]<<"; ";
        cout<<"Time = "<<ti[ed]<<": ";
        for(auto i:ans1){
            cout<<i<<" -> ";
        }cout<<ed<<endl;
    }else{
        cout<<"Distance = "<<d[ed]<<": ";
        for(auto i:ans1){
            cout<<i<<" -> ";
        }cout<<ed<<endl;
        cout<<"Time = "<<ti[ed]<<": ";
        for(auto i:ans2){
            cout<<i<<" -> ";
        }cout<<ed;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}