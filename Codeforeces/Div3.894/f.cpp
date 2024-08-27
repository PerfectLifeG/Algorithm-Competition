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
void solve()
{
    int w,f;cin>>w>>f;
    int n;cin>>n;
    vector<int>a(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(w>f)swap(w,f);
    int l=0,r=1e6;
    while(l+1!=r){
        int mid=l+r>>1;
        int m=min(mid*w,sum);
        vector<int>dp(m+1);
        for(int i=1;i<=n;i++){
            for(int j=m;j>=a[i];j--){
                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
            }
        }
        if(sum-dp[m]<=mid*f)r=mid;
        else l=mid;
    }
    cout<<r<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}