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
const int INF=0x3f3f3f3f;
struct Node{
    string a,b;
    int c;
    bool operator<(const Node& n )const{
        return a<n.a;
    }
};
int cmp1(Node a,Node b){
    return a.a<b.a;
}
int cmp2(Node a,Node b){
    if(a.b!=b.b){
        return a.b<b.b;
    }else return a.a<b.a;
}
int cmp3(Node a,Node b){
    if(a.c!=b.c){
        return a.c<b.c;
    }else return a.a<b.a;
}
void solve(){
    int n,op;cin>>n>>op;
    vector<Node>v[4];
    for(int i=0;i<n;i++){
        string a,b;int c;
        cin>>a>>b>>c;
        v[1].push_back({a,b,c});
        v[2].push_back({a,b,c});
        v[3].push_back({a,b,c});
    }
    sort(all(v[1]),cmp1);
    sort(all(v[2]),cmp2);
    sort(all(v[3]),cmp3);
    for(auto i:v[op]){
        cout<<i.a<<' '<<i.b<<' '<<i.c<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}