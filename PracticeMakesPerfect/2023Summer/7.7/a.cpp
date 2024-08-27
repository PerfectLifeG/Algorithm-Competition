#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
void solve()
{
    int n;cin>>n;
    if(n==3){
        cout<<1<<endl;
        return;
    }
    if(n==4){
        cout<<2<<endl;
        return;
    }
    if(n&1)
    cout<<n/2<<endl;
    else cout<<n/2-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}