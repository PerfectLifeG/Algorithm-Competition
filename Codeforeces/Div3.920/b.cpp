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
    string s,f;cin>>s>>f;
    int ans=0;
    int t1=0,t2=0;
    for(int i=0;i<n;i++){
        if(s[i]!=f[i]){
            if(s[i]=='1')t1++;
            if(f[i]=='1')t2++;
        }
    }
    cout<<max(t1,t2)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}