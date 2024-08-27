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
    char s[17];
    int a,b;
};
int cmp(Node &n,Node &n2){
    return n.a<n2.a;
}
int cmp2(Node &n,Node &n2){
    return n.b>n2.b;
}
void solve()
{
    int n;cin>>n;
    Node node[n];
    for(int i=0;i<n;i++){
        // string s;cin>>node[i].s;
        int a,b,c,d,e,f;
        // scanf("%s")
        scanf("%s %d:%d:%d %d:%d:%d",&node[i].s,&a,&b,&c,&d,&e,&f);
        int t=a*3600+b*60+c;
        node[i].a=t;
        t=d*3600+e*60+f;
        node[i].b=t;
        // cout<<node[i].a<<' '<<node[i].b<<' '<<node[i].s<<endl;
        // cout<<d<<' '<<e<<' '<<f<<endl;
    }
    sort(node,node+n,cmp);
    cout<<node[0].s<<' ';
    sort(node,node+n,cmp2);
    cout<<node[0].s;
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}