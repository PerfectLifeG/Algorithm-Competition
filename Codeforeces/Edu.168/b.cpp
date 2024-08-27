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
    string s[2];cin>>s[0]>>s[1];
    string t="...x.x";
    int ans=0;
    if(n<3){
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<n-1;i++){
        string tt;tt+=s[0][i-1];tt+=s[0][i];tt+=s[0][i+1];tt+=s[1][i-1];tt+=s[1][i];tt+=s[1][i+1];
        // cout<<i<<' '<<tt<<endl;
        if(tt==t){
            ans++;
        }
        tt="";
        tt+=s[1][i-1];tt+=s[1][i];tt+=s[1][i+1];tt+=s[0][i-1];tt+=s[0][i];tt+=s[0][i+1];
        if(tt==t){
            ans++;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}