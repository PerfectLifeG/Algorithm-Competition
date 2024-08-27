#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N];
void solve()
{
    int n;cin>>n;
    int t=1e9;
    int flag=0;
    cin>>a[0];
    int lst=a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        t=min(t,a[i]-lst+1);
        lst=a[i];
    }
    // cout<<t<<endl;
    if(t<0)cout<<0<<endl;
    else cout<<(t+1)/2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}