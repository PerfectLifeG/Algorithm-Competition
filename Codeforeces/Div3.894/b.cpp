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
    int n;cin>>n;
    vector<int>ans;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ans.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]>=ans.back()){
            ans.push_back(a[i]);
        }else {ans.push_back(a[i]);ans.push_back(a[i]);}
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<' ';
    }cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}