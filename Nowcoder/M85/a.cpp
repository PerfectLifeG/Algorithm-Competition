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
    int n;cin>>n;
    // 1 2
    // 2 3

    // 3 4
    // 4 5
    
    // 5 6
    // 6 7
    
    // 7 8
    // 8 9
    
    // 9 10
    // 10 11

    // 11 12
    // 12 13

    // 13 14
    // 14 15

    // 15 16
    // 16 17
    int t=n;
    if(n%2==0)
    int t--;
    if(n&1)
    cout<<2*t+1<<endl;
    else cout<<2*t+2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}