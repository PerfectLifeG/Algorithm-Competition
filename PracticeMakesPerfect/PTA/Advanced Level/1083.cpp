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
    string a,b;
    int c;
    bool operator<(const Node& n)const{
        return c>n.c;
    }
};
void solve(){
    int n;cin>>n;
    vector<Node>v(n);
    for(int i=0;i<n;i++){
        string a,b;int c;
        cin>>a>>b>>c;
        v[i]={a,b,c};
    }
    sort(all(v));
    vector<Node>ans;
    int l,r;cin>>l>>r;
    for(int i=0;i<n;i++){
        if(v[i].c>=l&&v[i].c<=r){
            ans.push_back(v[i]);
        }
    }
    if(ans.empty())cout<<"NONE\n";
    for(auto i:ans){
        cout<<i.a<<' '<<i.b<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}