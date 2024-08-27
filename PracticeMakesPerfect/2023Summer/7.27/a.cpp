#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Node{
    int a,b;
    int id;
    int s;
    bool operator<(const Node &n)const
    {
        return s>n.s;
    }
};
void solve()
{
    int n;cin>>n;
    Node node[n];
    // priority_queue<Node,vector<Node>,less<Node>>q;
    for(int i=0;i<n;i++){
        cin>>node[i].a>>node[i].b;
        node[i].s=node[i].a+node[i].b;
        // q.push();
    }
    sort(node,node+n);
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            a+=node[i].a;
        }else b+=node[i].b;
    }
    cout<<a-b<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}