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
    int n=s.size();
    vector<int>suf(n+1);
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            suf[i]=suf[i+1]+1;
        }else suf[i]=suf[i+1];
    }
    int i=0;
    while(i<s.size()&&s[i]=='0')i++;
    int ans=0;
    if(i<s.size())ans++,i++;
    int t=0;
    for(;i<s.size();i++){
        if(s[i]=='0'){
            t=max(t,suf[i+1]-(n-(i+1)-suf[i+1]));
        }else{
            t=max({t,suf[i+1]-(n-(i+1)-suf[i+1]),suf[i]-(n-(i)-suf[i])});
        }
    }
    cout<<ans+t<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}