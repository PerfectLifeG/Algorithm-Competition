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
    int f=0;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            f=i;
            break;
        }
    }
    char x;
    if(s[f]=='z')x='a';
    else x='z';
    string ans=s.substr(0,f)+x+s.substr(f);
    cout<<ans<<endl;;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}