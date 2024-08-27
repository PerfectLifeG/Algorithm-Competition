#include<bits/stdc++.h>
using namespace std;
const int N=500010,INF=0x3f3f3f3f;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
typedef pair<int,int> PII;
struct Node
{
    int l;
    int r;
    bool operator<(const Node n)const{
        if(l==n.l)return r<n.r;
        return l>n.l;
    }
}node[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        multiset<int>s{INF,-INF};
        for(int i=0;i<n;i++){
            int l,r;cin>>l>>r;
            node[i].l=l;
            node[i].r=r;
        }
        sort(node,node+n);
        for(int i=0;i<n;i++)s.insert(node[i].r);
        int ans=INF;int mx=-INF;
        for(int i=0;i<n;i++){
            s.erase(s.find(node[i].r));
            ans=min({ans,abs(node[i].l-max(mx,*prev(s.upper_bound(node[i].l)))),abs(node[i].l-max(mx,*s.lower_bound(node[i].l)))});
            mx=max(mx,node[i].r);
        }
        cout<<ans<<endl;
    }
    return 0;
}