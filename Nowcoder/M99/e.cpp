#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>h(n);
    vector<int>x(n);
    vector<PII>v;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int i=0;i<n;i++){
        cin>>x[i];
        v.push_back({x[i],h[i]});
    }
    sort(all(v));

    vector<int>ans;
    for(int i=0;i<n;){
        int len=v[i].x+v[i].y;
        int j=i+1;
        while(j<n&&len>=v[j].x){
            len=max(len,v[j].x+v[j].y);
            j++;
        }
        ans.push_back(j-i);
        // cout<<j-i<<endl;
        i=j;
    }
    sort(all(ans),greater<int>());
    // for(auto i:ans)cout<<i<<' ';cout<<endl;
    int sum=0;
    for(int i=0;i<m&&i<ans.size();i++){
        sum+=ans[i];
    }
    cout<<sum<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}