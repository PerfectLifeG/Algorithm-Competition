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
    int a,b;cin>>a>>b;
    if(a+b>1023){
        int t=a+b-1024;
        cout<<-(1024)+t<<endl;
    }else if(a+b<-1024){
        int t=-1024-a-b;
        cout<<1024-t<<endl;
    }else cout<<a+b<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}