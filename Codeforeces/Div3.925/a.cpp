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
    int a;cin>>a;
    if(26*2<a){
        cout<<char('a'+(a-26*2-1))<<'z'<<'z'<<endl;
    }else if(a>27)
        cout<<'a'<<char('a'+(a-26-2))<<'z'<<endl;
    else cout<<'a'<<'a'<<char('a'+(a-2-1))<<endl;
    // }else cout<<'a'<<'a'<<'z'<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}