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
void solve(){
    int n;cin>>n;
    vector<PII>v;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    int a,b,c,d;cin>>a>>b>>c>>d;
    int x=(a-c)*(a-c)+(b-d)*(b-d);
    // cout<<x<<endl;
    int mn=1e19;
    for(int i=0;i<n;i++){
        mn=min(mn,(v[i].first-c)*(v[i].first-c)+(v[i].second-d)*(v[i].second-d));
    }
    // int p=sqrt(mn);
    // if(p*p<mn)p++;
    // int q=sqrt(x);
    // if(q*q<x)q++;
    // cout<<p<<' '<<q<<endl;
    if(mn>x)yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}