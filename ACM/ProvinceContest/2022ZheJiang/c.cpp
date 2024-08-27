#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=1000010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    // if(n==1){
    //     cout<<0<<endl;
    //     return;
    // }
    vector<double>a(n+1);
    vector<double>s(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    sort(a.begin()+1,a.end());
    int ans=0;
    for(int i=1;i<=n;i++){
        double x=0;
        x=s[i]*1.0/i;
        auto p=upper_bound(a.begin()+1,a.begin()+1+i,x);
        if(p==a.begin()+1+i)continue;
        cout<<i<<' '<<x<<' '<<*p<<' '<<ans<<endl;
        ans=max(ans,i-(p-a.begin())+1);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}