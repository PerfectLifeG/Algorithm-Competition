#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
vector<int>ans;int n;
int ru[110];
int h[110],e[N],ne[N],idx;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void topsort(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(ru[i]==0)q.push(i);
    }
    while(q.size()){
        auto t=q.front();
        q.pop();
        ans.push_back(t);
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(--ru[j]==0)q.push(j);
        }
    }
}
void solve()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int a;
        while(cin>>a,a){
            ru[a]++;
            add(i,a);
        }
    }
    topsort();
    for(auto i:ans)cout<<i<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}