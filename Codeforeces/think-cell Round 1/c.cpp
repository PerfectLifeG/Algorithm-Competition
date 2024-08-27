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
    int n;cin>>n;
    vector<int>v(n+1);
    vector<int>ans;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i]+=i;
        ans.push_back(v[i]);
    }
    sort(all(ans),greater<>());
    for(int i=0;i<ans.size();i++){
        if(i>0&&ans[i-1]<=ans[i]){
            cout<<ans[i-1]-1<<' ';
            ans[i]=ans[i-1]-1;
        }
        else cout<<ans[i]<<' ';
    }cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}