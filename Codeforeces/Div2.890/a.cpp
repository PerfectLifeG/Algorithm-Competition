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
    int ans=0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;){
        int j=i+1;
        while(j<n&&a[j]>=a[j-1]){
            j++;
        }
        // cout<<i<<' '<<j<<endl;
        if(j==n)break;
        ans=max({a[j-1],ans});
        i=j;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}