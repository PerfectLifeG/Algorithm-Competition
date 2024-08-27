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
    string s;cin>>s;
    string p;
    for(int i=0;i<s.size();i++){
        p+=s[i];
        int f=0;
        while(s[i]=='0'){i++;f=1;}
        if(f)i--;
    }
    int cnt1=0,cnt2=0;
    for(auto i:p)if(i=='1')cnt1++;else cnt2++;
    if(cnt2<cnt1)yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}