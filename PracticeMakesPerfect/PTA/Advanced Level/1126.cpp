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
    vector<int>v[n+1];
    vector<int>degree(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    vector<int>book(n+1);
    function<void(int)> dfs=[&](int t){
        book[t]=1;
        for(auto j:v[t]){
            if(book[j])continue;
            dfs(j);
        }
    };
    dfs(1);
    int flag=1;
    for(int i=1;i<=n;i++)if(!book[i]){flag=0;break;}
    cout<<degree[1];
    int cnt=degree[1]&1;
    for(int i=2;i<=n;i++){
        cout<<' '<<degree[i];
        cnt+=degree[i]&1;
    }cout<<endl;
    if(flag){
        if(cnt==2){
            cout<<"Semi-Eulerian\n";
        }else if(cnt==0)cout<<"Eulerian\n";
        else cout<<"Non-Eulerian\n";
    }else{
        cout<<"Non-Eulerian\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}