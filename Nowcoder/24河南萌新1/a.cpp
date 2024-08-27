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
unordered_map<int,int>mp;
int n;
int ans=0;
void solve(){
    cin>>n;
    int t=0;
    for(int i=60;i>=2;i--){
        if((n>>i)&1){
            ans++;
            t=max(t,i-1);
        }
    }
    if((n>>1)&1)ans++;
    if(n&1)ans++;
    cout<<ans+t<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}