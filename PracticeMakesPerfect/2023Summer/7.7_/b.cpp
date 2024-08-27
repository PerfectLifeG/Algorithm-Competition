#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
struct Node{
    int a,b;
}node[N];
int cmp(Node n1,Node n2){
    return n1.a>n2.a;
}
void solve()
{
    int n;cin>>n;
    int mn=1e9;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>node[i].a>>node[i].b;
        if(node[i].a>node[i].b)ans++;
    }
    // int ans=0;
    // for(int i=0;i<n;i++){
    //     if(node[i].a==mn)ans++;
    // }
    // sort(node,node+n);
    // if()
    cout<<ans<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}