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
    int n,q;cin>>n>>q;
    string s;cin>>s;
    int a=0,b=0;
    for(auto i:s)if(i=='(')a++;else b++;
    s=' '+s;
    string ss=s;
    int aa=a,bb=b;
    while(q--){
        a=aa,b=bb,s=ss;
        int t;cin>>t;
        if(s[t]=='(') ss[t]=')',s[t]=')',a--,aa--,b++,bb++;
        else ss[t]='(',s[t]='(',a++,aa++,b--,bb--;
        cout<<s<<' '<<endl<<a<<' '<<b<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    while(T--){
        solve();
    }
    return 0;
}