#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=100010,M=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int h[N],e[M],ne[M],idx;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int ru[N];int n;
vector<int>ans;
int c[N];
void topsort(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(ru[i]==0){q.push(i);ans.push_back(i);}
    }

    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(--ru[j]==0){q.push(j);ans.push_back(j);}
        }
    }
}
vector<int>ans1;
int bfs(int a){
    queue<int>q;q.push(a);
    int mn=c[a];
    int id=a;
    ru[a]=0;ans1.push_back(a);
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(ru[j]==0)continue;
            ru[j]=0;
            {q.push(j);if(mn>c[j]){mn=c[j];id=j;};ans1.push_back(j);}
        }
    }
    return id;
}
void solve(){
    cin>>n;
    ans.clear();
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        ru[a]++;
        add(i,a);
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    topsort();
    // for(auto i:ans)cout<<i<<' ';cout<<endl;
    for(int i=1;i<=n;i++){
        if(ru[i]>0){
            ans1.clear();
            int t=bfs(i);
            // for(auto i:ans1)cout<<i<<' ';cout<<endl;
            int j=0;
            for(;j<ans1.size();j++){
                if(ans1[j]==t)break;
            }
            j++;
            for(int k=j;k<ans1.size();k++){
                ans.push_back(ans1[k]);
            }
            for(int k=0;k<j;k++){
                ans.push_back(ans1[k]);
            }
        }
    }
    for(auto i:ans)cout<<i<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}