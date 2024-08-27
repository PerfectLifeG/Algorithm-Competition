#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
// int a[N];
struct Node{
    int a;
    int id;
    bool operator<(const Node &n)const{
        if(a==n.a)return id<n.id;
        return a>n.a;
    }
};
void solve()
{
    int n,k;cin>>n>>k;
    vector<int>a(n+1);
    priority_queue<Node,vector<Node>,less<Node>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]%=k;
        if(a[i]==0)a[i]=k;
        Node node;
        node.a=a[i];node.id=i;
        q.push(node);
    }
    vector<int>ans;
    while(q.size()){
        ans.push_back(q.top().id);
        q.pop();
    }
    for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<' ';
        cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}