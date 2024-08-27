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
    int n,q;cin>>n>>q;
    vector<int>st(n+1);st[1]=1;
    for(int i=2;i<=n;i++){
        cin>>st[i];
    }
    while(q--){
        int a;cin>>a;
        // cout<<a<<' ';
        // cout<<*lower_bound(st.begin(),st.end(),a)<<endl;
        cout<<prev(upper_bound(st.begin(),st.end(),a))-st.begin()<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}