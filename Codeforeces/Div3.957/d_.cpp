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
    int n,m,k;cin>>n>>m>>k;
    string s;cin>>s;s=' '+s+'L';
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,0});
    for(int i=1;i<=n+1;i++){
        while(q.size()&&((i-q.top().y)>m||(q.top().x)>k))q.pop();
        if(q.empty())break;
        auto t=q.top();
        if(s[i]=='W'){
            if(t.x+1<=k)q.push({t.x+1,i});
        }else if(s[i]=='L'){
            if(t.x<=k)q.push({t.x,i});
        }
    }
    if(q.size())yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}