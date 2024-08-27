#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;

void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    int ans=1;
    for(int i=0;i<n/2;i++){
        if(s[i]!='?'&&s[n-i-1]!='?'&&s[i]!=s[n-i-1]){
            cout<<0<<endl;
            return;
        }
        if(s[i]=='?'&&s[n-i-1]=='?'){
            ans=ans*26%mod;
        }
    }
    if(n&1&&s[n/2]=='?'){
        ans=ans*26%mod;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}