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
    int n,k;cin>>n>>k;

    vector<array<int,3>>v;
    for(int i=0;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        v.push_back({c,b,a});
    }
    sort(all(v),[&](array<int,3> a,array<int,3> b){
        if(a[0]!=b[0]){
            return a[0]>b[0];
        }
        return a[1]>b[1];
    });
    int sum=0;
    for(auto [a,b,c]:v){
        if()
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}