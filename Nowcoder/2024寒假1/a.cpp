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
void solve(){
    int n;cin>>n;
    string ss;cin>>ss;
    int d=0,f=0,s=0,D=0,F=0,S=0;
    for(int i=0;i<n;i++){
        if(ss[i]=='d')d=1;
        if(ss[i]=='f'&&d)f=1;
        if(ss[i]=='s'&&f)s=1;
        if(ss[i]=='D')D=1;
        if(ss[i]=='F'&&D)F=1;
        if(ss[i]=='S'&&F)S=1;
    }
    cout<<S<<' '<<s<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}