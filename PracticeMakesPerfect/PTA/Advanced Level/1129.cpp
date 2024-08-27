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
const int N=50010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
vector<int>cnt(N);  
struct Node{
    int v;
    bool operator<(const Node& n)const{
        if(cnt[v]!=cnt[n.v]){
            return cnt[v]>cnt[n.v];
        }
        return v<n.v;
    }
};
void solve(){
    int n,k;cin>>n>>k;
    vector<int>book(n+1);
    priority_queue<Node,vector<Node>,less<Node>>q;
    int first;cin>>first;
    q.push({first});
    book[first]=1;
    cnt[first]=1;
    for(int i=1;i<n;i++){
        int a;cin>>a;
        cout<<a<<':';
        vector<int>tmp;
        while(q.size()){
            tmp.push_back(q.top().v);
            q.pop();
        }
        sort(all(tmp),[&](int a,int b){
            if(cnt[a]!=cnt[b]){
                return cnt[a]>cnt[b];
            }
            return a<b;
        });
        for(auto j:tmp){
            cout<<' '<<j;
            q.push({j});
        }cout<<endl;
        if(!book[a]){
            cnt[a]++;
            if(q.size()<k){
                book[a]=1;
                q.push({a});
            }else{
                if(cnt[a]>cnt[q.top().v]||cnt[a]==cnt[q.top().v]&&a<q.top().v){
                    book[q.top().v]=0;
                    q.pop();
                    q.push({a});
                    book[a]=1;
                }
            }
            continue;
        }
        cnt[a]++;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}