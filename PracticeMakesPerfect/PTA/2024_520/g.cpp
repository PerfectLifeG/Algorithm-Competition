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
const int N=1e6;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    set<PII>st;
    for(int i=1;i*i<=n;i++){
        if(n%(i*i)!=0)continue;
        int k=n/(i*i);
        int y1=(-2*k+sqrt(4*k*n))/(2*k);
        int y2=(-2*k-sqrt(4*k*n))/(2*k);
        if(y1!=0)st.insert({y1*k,y1});
        if(y2!=0)st.insert({y2*k,y2});
    }
    for(auto [i,j]:st){
        cout<<'('<<i<<','<<' '<<j<<')'<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}