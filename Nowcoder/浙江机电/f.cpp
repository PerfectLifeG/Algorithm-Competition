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
    int n,m;cin>>n>>m;
    string s;
    cin>>s;
    string t;
    for(int i=0;i<m;i++){
        string op;
        cin>>op;
        if(op=="cx"){
            int l,r;cin>>l>>r;
            t=s.substr(l-1,r-l+1);
            s=s.substr(0,l-1)+s.substr(r);
            // cout<<s<<' '<<t<<endl;
        }else if(op=="cc"){
            int l,r;cin>>l>>r;
            t=s.substr(l-1,r-l+1);
            // cout<<s<<' '<<t<<endl;
        }else{
            int idx;cin>>idx;
            if(idx>s.size())continue;
            s=s.substr(0,idx)+t+s.substr(idx);
        }
    }
    cout<<s<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}