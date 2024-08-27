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
    int n;cin>>n;
    string s;cin>>s;
    string ans;
    vector<int>v(n);
    for(int i=n-1;i>=0;i--){
        int now=0;
        unordered_map<char,int>mp;
        for(int j=i;j>=0;j--){
            // cout<<j<<' '<<s[j]<<endl;
            if(mp.count(s[j])){
                v[j]=mp[s[j]];
            }else {
                v[j]=now;
                mp[s[j]]=v[j];
                now++;
            }
            // cout<<j<<' '<<s[j]<<' '<<v[j]<<endl;
        }
        string t="";
        for(int j=0;j<=i;j++){
            // cout<<j<<' '<<v[j]<<endl;
            t+=v[j]+'a';
        }
        // cout<<t<<endl;
        ans=max(t,ans);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}