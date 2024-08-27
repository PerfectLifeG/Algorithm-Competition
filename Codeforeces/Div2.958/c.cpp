#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define lowbit(x) (x&(-x))
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>ans;
    ans.push_back(n);
    int lst=0;
    while(n){
        int t=n;
        n-=lowbit(n);
        if(n+lst)ans.push_back(n+lst);
        lst+=lowbit(t);
    }
    reverse(all(ans));
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}