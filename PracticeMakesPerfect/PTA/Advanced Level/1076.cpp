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
    int n,k;cin>>n>>k;
    vector<int>v[n+1];
    for(int i=1;i<=n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int a;cin>>a;
            v[a].push_back(i);
        }
    }

    auto bfs=[&](int st){
        vector<int>book(n+1,-1);
        book[st]=0;
        queue<int>q;
        q.push(st);
        int cnt=0;
        while(q.size()){
            auto t=q.front();
            q.pop();
            if(book[t]>k)continue;
            cnt++;
            for(auto j:v[t]){
                if(book[j]!=-1)continue;
                book[j]=book[t]+1;
                q.push(j);
            }
        }
        return cnt-1;
    };

    int Q;cin>>Q;
    while(Q--){
        int a;cin>>a;
        cout<<bfs(a)<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}