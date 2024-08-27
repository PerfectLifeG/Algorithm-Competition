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
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    double ans=1e9+10;
    double eps=1e-6;
    double l=0,r=ans;
        // cout<<l<<' '<<r<<' '<<ans<<endl;
    function<int(double)> check=[&](double mid)->int{
        for(int i=1;i<=n;i++){
            if((int)(mid*i)>v[i-1])return 0;
        }
        return 1;
    };

    while(l+eps<r){
        double mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    printf("%.10lf",l);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}