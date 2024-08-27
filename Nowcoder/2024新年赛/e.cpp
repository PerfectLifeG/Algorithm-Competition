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
int isprime(int n){
    for(int i=2;i<=n/i;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
void solve(){
    int n,m,k;cin>>n>>m>>k;
    if(m<2*k){
        cout<<"Bong\n";
    }else {
        // if(m<3*k){
            if(n&1){
                if(!isprime(m)||k==1)cout<<"Bing\n";
            }
            else cout<<"Bong\n";
        // }else cout<<"Bong\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}