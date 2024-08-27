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
void solve(){
    int n,f,a,b;cin>>n>>f>>a>>b;
    int lst;cin>>lst;
    f=f-min(b,lst*a);
    for(int i=0;i<n-1;i++){
        int t;cin>>t;
        if(f<=0){continue;}
        int tt=(t-lst);
        f-=min(b,tt*a);
        lst=t;
    }
    if(f<=0)no;
    else yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}