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
    if(n==1){
        cout<<1<<endl;
        return;
    }
    int cnt=(n-1)/2;
    cout<<196<<string(n-3,'0')<<endl;
    for(int i=0;i<cnt;i++){
        cout<<1<<string(i,'0')<<6<<string(i,'0')<<9<<string(n-3-i*2,'0')<<endl;
    }
    for(int i=0;i<cnt;i++){
        cout<<9<<string(i,'0')<<6<<string(i,'0')<<1<<string(n-3-i*2,'0')<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}