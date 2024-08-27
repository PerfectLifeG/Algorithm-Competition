#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    s=' '+s+' ';
    for(int i=1;i<s.size()-1;i++){
        if(s[i]=='L'){if(s[i-1]!='L')s[i-1]='1';if(s[i+1]!='L')s[i+1]='1';}

    }
    for(int i=1;i<s.size()-1;i++){
        if(s[i]=='.')s[i]='C';
        if(s[i]=='1')s[i]='.';
    }
    cout<<string(s.begin()+1,s.end()-1);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}