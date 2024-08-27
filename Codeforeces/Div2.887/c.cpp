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
    int n,k;cin>>n>>k;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]>1){
        cout<<1<<endl;
        return;
    }
    int ans=1;int t=1;
    while(k){
        if(t>=n)ans+=t;
        else if(ans+t<a[t+1])ans+=t;
        else {
            t++;
            while(t<=n-1&&ans+t>=a[t+1]){
                t++;
            }
            ans+=t;
        }
        k--;
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