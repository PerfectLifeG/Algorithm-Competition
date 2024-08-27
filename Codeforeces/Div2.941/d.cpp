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
    vector<int>ans;
    int t=1;
    int i=0;
    int p=log2(k);
    for(;i<p;i++){
        ans.push_back(t);
        t*=2;
    }
    //1 2 4 8 16 32
    //6 1
    ans.push_back(k+1);
    ans.push_back(2*k+1);
    if((1<<p)!=k)ans.push_back(k-(t-1)-1);
    // t=1;
    t*=2;
    while(ans.size()!=25){
        ans.push_back(t);
        t*=2;
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<' ';
    }cout<<endl;
    // 9
    // 1 2 4 
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}