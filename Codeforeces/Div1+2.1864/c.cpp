#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define lowbit(x) (x&-x)
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int x;cin>>x;
    vector<int>ans;
    while(x!=0){
        ans.push_back(x);
        x-=lowbit(x);
    }
    int t=ans.back();
    while(t!=1){
        ans.push_back(t/2);
        t/=2;
    }
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