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
const int N=30010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
struct Node{
    string name;
    int a=-1,b=-1,c=-1,d=-1;
    bool operator<(const Node& n)const{
        if(d!=n.d)return d>n.d;
        return name<n.name;
    }
}node[N];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    unordered_map<string,int>mp;
    int idx=0;
    for(int i=0;i<n;i++){
        string a;int b;
        cin>>a>>b;
        if(!mp.count(a))mp[a]=idx++;
        node[mp[a]].a=b;
        node[mp[a]].name=a;
    }
    for(int i=0;i<m;i++){
        string a;int b;
        cin>>a>>b;
        if(!mp.count(a))mp[a]=idx++;
        node[mp[a]].b=b;
        node[mp[a]].name=a;
    }
    for(int i=0;i<k;i++){
        string a;int b;
        cin>>a>>b;
        if(!mp.count(a))mp[a]=idx++;
        node[mp[a]].c=b;
        node[mp[a]].name=a;
    }
    for(int i=0;i<idx;i++){
        if(node[i].c>=node[i].b)node[i].d=node[i].c;
        else node[i].d=round(0.4*node[i].b+0.6*node[i].c);
    }
    sort(node,node+idx);
    for(int i=0;i<idx;i++){
        if(node[i].a>=200&&node[i].d>=60)
        cout<<node[i].name<<' '<<node[i].a<<' '<<node[i].b<<' '<<node[i].c<<' '<<node[i].d<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}