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
    int n,st1,st2;cin>>n>>st1>>st2;
    vector<int>v[n+1];
    vector<int>du(n+1);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        du[a]++;
        du[b]++;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int>q;
    for(int i=1;i<=n;i++)if(du[i]==1)q.push(i);
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(auto j:v[t]){
            if(du[j]>1&&--du[j]==1){
                q.push(j);
            }
        }
    }
    vector<int>book(n+1);
    vector<int>book2(n+1);
    q.push(st1);
    book[st1]=1;
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(auto j:v[t]){
            if(book[j])continue;
            book[j]=book[t]+1;
            q.push(j);
        }
    }
    q.push(st2);
    book2[st2]=1;
    if(du[st2]>1&&book2[st2]<book[st2]){
        yes;
        return;
    }
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(auto j:v[t]){
            if(book2[j])continue;
            book2[j]=book2[t]+1;
            if(du[j]>1&&book2[j]<book[j]){
                yes;
                return;
            }
            q.push(j);
        }
    }
    no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}