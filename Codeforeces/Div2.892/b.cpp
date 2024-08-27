#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int T;cin>>T;
    int mn=1e9;
    vector<int>ans;
    while(T--){
        int n;cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            mn=min(mn,a[i]);
        }
        sort(all(a));
        if(n>=2){
            ans.push_back(a[1]);
        }else ans.push_back(a[0]);
    }
    sort(all(ans));
    // for(auto i:ans)cout<<i<<' ';
    //     cout<<endl;
    int r=mn;
    for(int i=1;i<ans.size();i++){
        r+=ans[i];
    }
    cout<<r<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}