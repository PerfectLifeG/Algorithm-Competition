#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Node{
    int a;
    int b;
    int id;
    bool operator<(const Node& n)const
    {
        if(a<=10&&n.a<=10)return b>n.b;
        return a<n.a;
    }
};
void solve()
{
    int n;cin>>n;
    // cout<<n<<'.'<<endl;
    Node node[n+1];
    if(n==1){cin>>node[0].a>>node[0].b;cout<<1<<endl;return;}
    for(int i=0;i<n;i++){
        cin>>node[i].a>>node[i].b;
        // cout<<node[i].a<<' '<<node[i].b<<endl;
        node[i].id=i+1;
    }
    sort(node,node+n);
    // for(int i=0;i<n;i++)cout<<node[i].a<<endl;
    cout<<node[0].id<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}