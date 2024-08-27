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
const int INF=0x3f3f3f3f;
int a[N];
int q[N];
void solve(){
    int n;cin>>n;
    for(int i=0;i<=n;i++)q[i]=0;
    for(int i=0;i<n;i++)cin>>a[i];
    int len=0;
    for(int i=n-1;i>=0;i--){
        int l=0,r=len+1;
        while(l+1!=r){
            int mid=l+r>>1;
            if(q[mid]<=a[i]){
                l=mid;
            }else r=mid;
        }
        q[l+1]=a[i];
        if(l+1>len)len++;
    }
    for(int i=1;i<=len;i++)cout<<q[i]<<' ';cout<<endl;
    int idx=1;
    vector<int>v;
    int ans=0;
    for(int i=n-1;i>=0;i--){
        if(idx<=len&&q[idx]==a[i]){
            idx++;
        }else {
            v.push_back(a[i]);
        }
    }
    // for(auto i:v)cout<<i<<' ';cout<<endl;
    for(int i=v.size()-2;i>=0;i--){
        if(v[i]>v[i+1])ans++;
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