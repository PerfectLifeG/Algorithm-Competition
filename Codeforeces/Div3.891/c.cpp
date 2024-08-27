#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n;cin>>n;
    int a[n*(n-1)/2];
    for(int i=0;i<n*(n-1)/2;i++)cin>>a[i];
    sort(a,a+n*(n-1)/2);
    // int t=a[0];
    // int i=0;
    // cout<<t<<' ';
    // 2 2 2 2 2 2 2 2 2 2
    // 2 2 2 2 2
    int t=n;
    for(int i=0;i<n*(n-1)/2&&t!=1;i+=t){
        cout<<a[i]<<' ';
        t--;
    }
    cout<<1000000000<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}