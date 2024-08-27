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
    int n,m;cin>>n>>m;
    vector<int>v[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<PII>p;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        p.push_back({b,a});
    }
    sort(all(p));

    queue<PII>q;
    vector<int>book(n+1,-1);
    int ts=p[0].x;int idx=0;

    while(1){
        // while(q.size()){
            queue<PII>tmp;
            while(q.size()){
                auto [t,fa]=q.front();
                q.pop();
                for(auto j:v[t]){
                    if(j==fa)continue;
                    if(book[j]!=-1){
                        cout<<book[j]+book[t]+1<<endl;
                        return;
                    }
                    book[j]=book[t]+1;
                    if(book[j]==ts)tmp.push({j,t});
                    else q.push({j,t});
                }
            }
            q=tmp;
            // if(q.empty()||book[q.front().x]==ts)break;
        // }
        while(idx<m&&ts==p[idx].x){
            if(book[p[idx].y]!=-1){
                cout<<p[idx].x*2<<endl;
                return;
            }
            book[p[idx].y]=ts;
            q.push({p[idx].y,p[idx].y});
            idx++;
        }
        if(idx<m)ts=p[idx].x;
        else ts=INF;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}