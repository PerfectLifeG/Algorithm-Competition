#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,m;cin>>n>>m;
    if(n==1){
        cout<<(m+1)/2<<endl;
        return;
    }
    if(m==1){
        cout<<(n+1)/2<<endl;
        return;
    }
    if(n%3==0||m%3==0){
        cout<<2<<endl;
    }else cout<<1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}