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
    int ans=0;
    int n=s.size();
    for(int i=0;i<n/2;i++){
        int mn=1e9;
        for(int j=0;j<26;j++){
            mn=min(mn,(s[i]-('a'+j)+26)%26+(s[n-1-i]-('a'+j)+26)%26);
        }
        ans+=mn;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}