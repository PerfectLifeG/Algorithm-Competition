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
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=2;i--){
        int sum=0;
        for(int j=1;j<=i;j++){
            sum+=a[j];
        }
        // sum=sum*1.0/i;
        // sum=sum+0.5;
        // int x=a[i]-sum;
        // cout<<i<<' '<<sum<<' '<<a[i]<<' '<<x<<endl;
        while(a[i]*i>sum){
            a[i]--;
            a[i-1]++;
        }
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
        ans=ans*a[i]%mod;
    }
    cout<<endl;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}