#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=300010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N],q[N];
void solve()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int len=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int l=0,r=len+1;
        while(l+1!=r){
            int mid=l+r>>1;
            if(q[mid]<a[i]){
                l=mid;
            }else r=mid;
        }
        // cout<<a[i]<<' '<<l<<endl;
        q[l+1]=a[i];
        if(l+1>len)len++;
        if(l==1)ans++;
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