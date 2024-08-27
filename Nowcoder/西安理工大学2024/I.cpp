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
    int ji=0,ou=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a&1)ji++;
        else ou++;
    }
    // 2 1 2 2 1 1 2 2 2
    if(ji)cout<<"halo\n";
    // else if(ji>=ou)cout<<"halo\n";
    else cout<<"parry\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}