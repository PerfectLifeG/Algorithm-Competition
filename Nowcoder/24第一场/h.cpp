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
    string a;int b,c;
    bool operator<(const Node& n)const{
        if(b==n.b)return c<n.c;
        return b>n.b;
    }
};
void solve(){
    int n;cin>>n;
    map<string,PII>t1;
    map<string,PII>t2;
    map<string,int>mp1;
    map<string,int>mp2;
    vector<Node>v1;
    vector<Node>v2;
    for(int i=0;i<n;i++){
        string a;int b,c;cin>>a>>b>>c;
        if(a=="lzr010506")v1.push_back({a,b,c});
        mp1[a]++;
        t1[a]={b,c};
    }
    int m;cin>>m;
    for(int i=0;i<m;i++){
        string a;int b,c;cin>>a>>b>>c;
        if(a=="lzr010506")v2.push_back({a,b,c});
        mp2[a]++;
        t2[a]={b,c};
    }
    for(auto &[i,j]:mp1){
        if(!mp2.count(i)){
            v1.push_back({i,t1[i].first,t1[i].second});
        }
    }
    for(auto &[i,j]:mp2){
        if(!mp1.count(i)){
            v2.push_back({i,t2[i].first,t2[i].second});
        }
    }
    sort(all(v1));
    sort(all(v2));
    // for(auto i:v1)cout<<i.a<<' ';cout<<endl;
    // for(auto i:v2)cout<<i.a<<' ';cout<<endl;
    int ans=1e9;
    for(int i=0;i<v1.size();i++){
        if(v1[i].a=="lzr010506"){
            ans=i+1;
            break;
        }
    }
    for(int i=0;i<v2.size();i++){
        if(v2[i].a=="lzr010506"){
            ans=min(ans,i+1);
            break;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}