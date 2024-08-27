#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x&(-x))
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
    int a;cin>>a;
    if((a^lowbit(a))!=0){
        cout<<lowbit(a)<<' '<<(a^lowbit(a))<<endl;
    }else{
        int x=lowbit(a);
        cout<<a+1<<' '<<((a+1)^a)<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}