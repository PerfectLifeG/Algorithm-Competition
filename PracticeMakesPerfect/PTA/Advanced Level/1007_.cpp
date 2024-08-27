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
    vector<int>a(n+1);
    vector<int>s(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    vector<int>l(n+1);
    int mn=1e18;
    int mx=a[1];
    int idx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,s[i]-s[idx]);
        if(mn>s[i]){
            mn=s[i];
            l[i]=idx;
            idx=i;
        }else{
            l[i]=idx;
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i]-s[l[i]]==mx){
            idx=i;
            break;
        }
    }
    if(mx<0){
        cout<<0<<' '<<a[1]<<' '<<a[n]<<endl;
    }
    else cout<<mx<<' '<<a[l[idx]+1]<<' '<<a[idx]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}