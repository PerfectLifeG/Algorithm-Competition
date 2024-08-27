#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    // 3 6 9 12 15 18
    // 1 2 4
    // 1 2 4 5 7 8 10 11 13 14 16

    // 3 6 9 12 15

    // 12


    // 1 2 5

    // 1 2 8
    
    // 1 13 14
    if(n-5>4&&(n-5)%3!=0){
        yes;
        cout<<1<<' '<<4<<' '<<n-5<<endl;
    }else if(n-3>2&&(n-3)%3!=0){
        yes;
        cout<<1<<' '<<2<<' '<<n-3<<endl;
    }
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}