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
    int now=0;
    for(int i=0;i<9;i++){
        int t;cin>>t;
        t+=now;
        if(i==8)cout<<t;
        else if(i%2==0){cout<<t%2<<' ';now=t/2;}
        else {cout<<t%3<<' ';now=t/3;}
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}