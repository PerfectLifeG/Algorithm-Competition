#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.begin()+n
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
    vector<int>v(2*n+1);
    vector<int>s(2*n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(all(v));
    for(int i=n+1;i<=2*n;i++){
        v[i]=v[i-n];
    }
    for(int i=1;i<=2*n;i++){
        s[i]=s[i-1]+v[i];
    }
    int ans=INF;
    for(int i=1;i<=n;i++){
        for(int j=i;j<i+n;j++){
            ans=min(ans,abs(s[i+n-1]-s[j-1]-(s[j-1]-s[i-1])));
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}