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
vector<int>v[N+1];
int book[N+1];
int fa[N+1];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++)book[i]=INF;
    for(int i=1;i<=n-1;i++){
        int a;cin>>a;
        fa[i+1]=a;
    }
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int>q;
    book[1]=1;
    q.push(1);
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(auto j:v[t]){
            if(book[j]<=book[t]+1)continue;
            book[j]=book[t]+1;
            q.push(j);
            int f=fa[j];
            while(book[j]<book[f]){
                q.push(f);
                book[f]=book[j];
                f=fa[f];
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(book[i]==INF)cout<<"-1 ";
        else cout<<book[i]-1<<' ';
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}