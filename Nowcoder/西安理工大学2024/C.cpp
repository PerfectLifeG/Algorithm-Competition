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
    int x,y,z;cin>>x>>y>>z;
    double a=x*y*1.0/z+z*y*1.0/x+x*z*1.0/y;
    double b=x+y+z;
    if(x==y&&y==z&&x==z){
        cout<<'='<<endl;
    }else cout<<'>'<<endl;
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}