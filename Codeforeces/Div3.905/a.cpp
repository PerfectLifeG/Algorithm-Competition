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
    string s;cin>>s;
    int ans=1e18;
    // for(int i=0;i<=9;i++){
        int t=0;
        int now=1;
        for(auto j:s){
            // cout<<now<<' '<<t<<' ';
            if(now==0&&j=='0'){
                continue;
            }
            else if(now==0){
                t+=10-(j-'0');
            }else if(j=='0')t+=10-now;
            else t+=abs(j-'0'-now);
            now=j-'0';
        }
        // cout<<endl;
        ans=min(ans,t);
    cout<<ans+4<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}