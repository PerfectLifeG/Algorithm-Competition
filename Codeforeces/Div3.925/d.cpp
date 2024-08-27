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
const int INF=0x3f3f3f3f;
void solve(){
    int n,x,y;cin>>n>>x>>y;
    map<pair<int,int>,int>mp;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[{a[i]%x,a[i]%y}]++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int tx=(x-a[i]%x)%x;
        int ty=a[i]%y;
        ans+=mp[{tx,ty}];
        if(tx==a[i]%x&&ty==a[i]%y)ans--;
    }
    cout<<ans/2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}