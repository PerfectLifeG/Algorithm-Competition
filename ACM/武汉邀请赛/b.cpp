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
    int n;cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        sum+=a;
    }
    int ans=0;
    for(int i=30;i>=0;i--){
        int t=(1ll<<i);
        if((t-1)*n<sum){
            ans+=t;
            sum-=min(sum/t,n)*t;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}