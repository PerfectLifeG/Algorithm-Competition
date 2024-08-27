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
    string s;cin>>s;
    int sum=0;
    for(auto i:s)sum+=i-'0';
    int ans=0;
    if(sum%9==0)ans++;
    for(int i=s.size()-1;i>=0;i--){
        sum-=(s[i]-'0');
        if(sum%9==0)ans++;
    }
    cout<<ans-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}