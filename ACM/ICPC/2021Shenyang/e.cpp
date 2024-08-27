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
int nx[N];
string p=" edgnb";
int ans=0;
void kmp(string &p,string &s){
    for(int i=2,j=0;i<p.size();i++){
        while(j && p[i]!=p[j+1])j=nx[j];
        if(p[i]==p[j+1])j++;
        nx[i]=j;
    }
    for(int i=1,j=0;i<s.size();i++){
        while(j && s[i]!=p[j+1])j=nx[j];
        if(s[i]==p[j+1])j++;
        if(j==p.size()-1){
            //匹配成功
            ans++;
        }
    }
}
void solve(){
    ans=0;
    string s;cin>>s;s=' '+s;
    kmp(p,s);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}