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
    int n,k;cin>>n>>k;
    string s;
    int idx=0;
    for(int i=0;i<k;i++){
        idx%=26;
        s+='a'+idx;s+='a'+idx;
        idx++;
    }
    for(int i=2*k;i<n;i++){
        idx%=26;
        s+='a'+idx;
        idx++;
    }
    cout<<s<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}