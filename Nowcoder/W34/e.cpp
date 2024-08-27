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
char op[2]={'d','p'};
void solve(){
    int n;cin>>n;
    string s;cin>>s;s=' '+s;
    vector<int>v[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int flag=1;
    int id=1;
    function<void()> bfs=[&](){
        vector<int>book(n+1);
        queue<int>q;q.push(id);
        book[id]=1;
        while(q.size()){
            auto t=q.front();
            q.pop();
            for(auto j:v[t]){
                if(book[j])continue;
                book[j]=1;
                if(s[j]==s[t]){flag=0;return;}
                q.push(j);
                if(s[t]=='d')s[j]='p';
                if(s[t]=='p')s[j]='d';
            }
        }
    };

    for(int i=1;i<=n;i++){
        if(s[i]!='?'){id=i;break;}
    }
    if(s[id]=='?')s[id]='d';
    bfs();
    if(!flag)cout<<-1<<endl;
    else cout<<s<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}