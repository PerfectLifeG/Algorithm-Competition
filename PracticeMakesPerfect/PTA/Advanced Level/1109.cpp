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
struct Node{
    string s;
    int h;
    bool operator<(const Node& n)const
    {
        if(h!=n.h)return h<n.h;
        return s>n.s;
    }
};
void solve(){
    int n,k;cin>>n>>k;
    vector<Node>v;
    for(int i=0;i<n;i++){
        string s;int h;
        cin>>s>>h;
        v.push_back({s,h});
    }
    sort(all(v));
    int idx=v.size()-1;
    // for(auto i:v)cout<<i.s<<' ';cout<<endl;
    vector<int>ans;
    int t=n/k;
    for(int p=k-1;p>=0;p--){
        deque<string>q;
        int m=n-p*t;n-=m;
        q.push_back(v[idx--].s);
        for(int i=0;i<m-1;i+=2){
            q.push_front(v[idx--].s);
            if(i+1==m-1)break;
            q.push_back(v[idx--].s);
        }
        cout<<q.front();
        q.pop_front();
        while(q.size()){
            cout<<' '<<q.front();
            q.pop_front();
        }
        cout<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}