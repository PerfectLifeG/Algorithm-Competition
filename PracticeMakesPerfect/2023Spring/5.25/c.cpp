#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
void solve(){
    string s;cin>>s;
    string ans="";
    char flag='0';
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){ans+='0';flag='0';}
        if(s[i]=='?'){ans+=flag;}
        if(s[i]=='1'){ans+='1';flag='1';}
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}