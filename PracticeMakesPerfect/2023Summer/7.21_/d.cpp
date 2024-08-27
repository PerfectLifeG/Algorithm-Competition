#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N];
void solve()
{
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;){
        int j=i+1;
        int cnt=1;
        while(j<n&&a[j]-a[j-1]<=k){
            cnt++;
            j++;
        }
        i=j;
        ans=max(ans,cnt);
        // cout<<i<<' '<<cnt<<endl;
    }
    cout<<n-ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}