#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
    int x;cin>>x;
    int t;
    if(x==1){
        cout<<-1<<endl;
        return;
    }
    else if(x&1){
        t=x-1;
        cout<<x-1<<endl;
    }else{
        t=x-lowbit(x);
        if(t==0){
            cout<<-1<<endl;
            return;
        }
        cout<<t<<endl;
    }
    // cout<<__gcd(x,t)<<' '<<(x^t)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}