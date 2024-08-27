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
    int d,k;cin>>d>>k;
    int x=(long double)(d)/(sqrtl(2.0)*k);
    int p=x;
    x*=2;
    if((p*k+k)*(p*k+k)+p*k*k*p<=d*d)x++;
    // cout<<x<<endl;
    if(x&1){
        cout<<"Parry\n";
    }else cout<<"Mercedes\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}