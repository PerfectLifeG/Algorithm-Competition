#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,d;cin>>n>>d;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    vector<int>b(n);
    for(int i=0;i<n;i++){
        int l=a[i];
        int r=l+d;
        for(int j=0;j<n;j++){
            if(a[j]<l)b[j]=l;
            else if(a[j]>=l&&a[j]<=r)b[j]=a[j];
            else b[j]=r;
        }
        int cnt=0;
        // for(int j=0;j<n;j++){
        //     cout<<b[j]<<' ';
        // }
        // cout<<endl;
        for(int j=1;j<n;j++){
            cnt+=abs(b[j-1]-b[j]);
        }
        ans=max(ans,cnt);
        // cout<<l<<' '<<r<<' '<<ans<<endl;
    }
    for(int i=0;i<n;i++){
        int r=a[i];
        int l=r-d;
        for(int j=0;j<n;j++){
            if(a[j]<l)b[j]=l;
            else if(a[j]>=l&&a[j]<=r)b[j]=a[j];
            else b[j]=r;
        }
        int cnt=0;
        // for(int j=0;j<n;j++){
        //     cout<<b[j]<<' ';
        // }
        // cout<<endl;
        for(int j=1;j<n;j++){
            cnt+=abs(b[j-1]-b[j]);
        }
        ans=max(ans,cnt);
        // cout<<l<<' '<<r<<' '<<ans<<endl;
    }


    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}