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
    int n,k;cin>>n>>k;
    string s;cin>>s;
    int t=s.find('I');
    int l=t-1,r=t+1;
    while(k--){
        string op;cin>>op;
        if(op=="backspace"){
            if(l==-1)continue;
            if(r<n){
                if(s[l]=='('&&s[r]==')'){
                    r++;
                }
            }
            l--;
        }else {
            if(r==n)continue;
            r++;
        }
    }
    string ans="";
    if(l!=-1)ans+=s.substr(0,l+1);ans+='I';
    if(r!=n)ans+=s.substr(r);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}