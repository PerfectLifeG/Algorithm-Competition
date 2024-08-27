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
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){cout<<0<<endl;return;}
    int cnt=0;
    int flag=0;
    int flag2=0;
    for(int i=0;i<n;){
        // cout<<i<<' '<<cnt<<endl;
        int j=i+1;
        if(a[j]>=a[j-1])flag=1;
        while(j<n&&a[j]<a[j-1]){
            j++;
            flag2=1;
        }
        if(i&&j!=i+1&&a[i-1]<=a[i]){cnt++;}
        int t=j;
        j=i+1;
        while(j<n&&a[j]>a[j-1]){
            flag=1;
            j++;
        }
        t=max(t,j);
        i=t;
        cnt++;
    }
    if(!flag&&!flag2){cout<<n-1<<endl;return;}
    int ans=cnt-flag;
    cnt=0;flag=0;
    for(int i=1;i<n;){
        int j=i+1;
        if(a[j]>=a[j-1])flag=1;
        while(j<n&&a[j]<a[j-1]){
            j++;
            flag2=1;
        }
        if(i&&j!=i+1&&a[i-1]<=a[i]){cnt++;}
        int t=j;
        j=i+1;
        while(j<n&&a[j]>a[j-1]){
            flag=1;
            j++;
        }
        t=max(t,j);
        i=t;
        cnt++;
    }
    // cout<<ans<<' '<<cnt-flag+1<<endl;
    cout<<min(cnt-flag+1,ans)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}