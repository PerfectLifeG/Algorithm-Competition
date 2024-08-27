#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin()+1,x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>v(m+1);
    vector<int>suf(m+2);
    vector<int>pre(m+2);
    for(int i=1;i<=m;i++){
        cin>>v[i];
    }
    sort(all(v));
    for(int i=1;i<=m;i++){
        pre[i]=pre[i-1]+v[i];
    }
    for(int i=m;i>=1;i--){
        suf[i]=suf[i+1]+v[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            if((pre[i-1]+suf[j+1])%n==(pre[j]-pre[i-1]+n)%n){
                yes;
                return;
            }
        }
    }
    no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}