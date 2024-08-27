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
    string s;cin>>s;
    int c1=0;
    int c0=0;
    int ans=1;
    int t=0;
    int cnt=1;
    for(int i=0;i<s.size();){
        int j=i+1;
        while(j<s.size()&&s[i]=='1'&&s[i]==s[j]){
            c1++;
            j++;
        }
        while(j<s.size()&&s[i]=='0'&&s[i]==s[j]){
            c0++;
            j++;
        }
        t+=c1+c0;
        cnt=cnt*(c1+1)%mod;
        cnt=cnt*(c0+1)%mod;
        c1=0,c0=0;
        i=j;
    }
    for(int i=2;i<=t;i++){
        cnt=cnt*i%mod;
    }
    cout<<t<<' '<<cnt%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}