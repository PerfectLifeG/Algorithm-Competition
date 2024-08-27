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
void print(__int128 x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}

void solve(){
    int x,y;cin>>x>>y;
    if(x%y==0){
        cout<<y<<' '<<x/y<<endl;
        return;
    }
    __int128 d=__gcd(2*x,y);
    __int128 a=2*x;
    __int128 b=y;
    __int128 ans=a/d;
    print(y);putchar(' ');
    print(ans);putchar('\n');
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}