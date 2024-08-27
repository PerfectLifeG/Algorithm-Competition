#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define x first
#define y second
struct Node{
    int a,b,c;
    bool operator<(const Node &n)const{
        if (a != n.a) {
            return a > n.a;
        }
        else if (b != n.b) {
            return b > n.b;
        }
        else return c > n.c;
    }
};
void solve(){
    int n,m,k,qq;cin>>n>>m>>k>>qq;
    priority_queue<Node,vector<Node>,less<Node>>q;
    vector<int>v(k);
    queue<PII>win[n];
    for(int i=0;i<k;i++){
        cin>>v[i];
    }
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            if(i*n+j>=k)break;
            win[j].push({v[i*n+j],i*n+j});
        }
    }
    vector<int>ans(k);
    for(int i=0;i<n&&i<k;i++){//这个n我调了1h
        q.push({v[i],i,i});
        ans[i]=v[i];
    }
    int idx=n*m;
    while(q.size()){
        auto t=q.top();
        q.pop();
        if(ans[t.c]!=-1)ans[t.c]=t.a;
        if(idx<k){
            win[t.b].push({v[idx],idx});
        }
        if(win[t.b].size()){
            q.push({win[t.b].front().x+t.a,t.b,win[t.b].front().y});
            if(t.a>=540)ans[win[t.b].front().y]=-1;
            win[t.b].pop();
        }
        idx++;
    }
    while(qq--){
        int a;cin>>a;a--;
        if(ans[a]==-1){printf("Sorry\n");continue;}//题目是真傻逼范围误导
        int h=ans[a]/60+8;
        int m=ans[a]%60;
        printf("%02lld:%02lld\n",h,m);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}