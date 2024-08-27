#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Node{
    int id,vir,tal;
    bool operator<(const Node& n)const{
        if(vir+tal!=n.vir+n.tal){
            return vir+tal>n.vir+n.tal;
        }
        if(vir!=n.vir){
            return vir>n.vir;
        }
        return id<n.id;
    }
};
void solve(){
    int n,l,h;cin>>n>>l>>h;
    set<Node>v1;
    set<Node>v2;
    set<Node>v3;
    set<Node>v4;
    for(int i=0;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        if(b>=l&&c>=l){
            if(b>=h&&c>=h)v1.insert({a,b,c});
            else if(b>=h&&c<h)v2.insert({a,b,c});
            else if(b<h&&c<h&&b>=c)v3.insert({a,b,c});
            else v4.insert({a,b,c});
        }
    }
    cout<<v1.size()+v2.size()+v3.size()+v4.size()<<endl;
    for(auto [a,b,c]:v1){
        printf("%08d %d %d\n",a,b,c);
    }
    for(auto [a,b,c]:v2){
        printf("%08d %d %d\n",a,b,c);
    }
    for(auto [a,b,c]:v3){
        printf("%08d %d %d\n",a,b,c);
    }
    for(auto [a,b,c]:v4){
        printf("%08d %d %d\n",a,b,c);
    }
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}