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
    int n,k;cin>>n>>k;
    int t=2*n-2;
    // cout<<n<<' '<<k<<' '<<t<<endl;
    if(k<=t*2){
        cout<<(k+1)/2<<endl;
    }else cout<<(k-t*2)+t<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}