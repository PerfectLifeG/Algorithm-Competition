#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10000;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
int b[N];
int s[N];
void solve(){
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>v;
    int ans=0;
    for(int i=1;i<n;i++){
        v.push_back(abs(a[i]-a[i-1]));
        ans+=abs(a[i]-a[i-1]);
    }
    sort(all(v));
    int q=1;
    for(int i=v.size()-1;i>=0&&q<k;i--){
        // cout<<v[i]<<'.'<<endl;
        q++;
        ans-=v[i];
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}