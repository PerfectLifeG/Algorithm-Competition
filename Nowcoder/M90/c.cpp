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
    if(s.size()==1){
        if(s[0]=='1')cout<<2<<endl;
        else cout<<1<<endl;
        return;
    }
    string ans;
    int flag=0;
    for(int i=1;i<s.size();i++){
        if(s[i]=='0'){
            ans+='1';
        }else {
            if(ans.size())ans+='0';
            else if(i==s.size()-1){
                if(s[i]=='1')ans+='2';
                else ans+='1';
            }
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