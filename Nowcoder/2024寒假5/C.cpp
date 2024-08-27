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
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<a[0]-1<<endl;
        return;
    }
    int ans=a[0]-1+a[n-1]-1;
    a[0]=a[n-1]=1;
    int lst=0;
    for(int i=0;i<n-1;i++){
        int mn=min(a[i],a[i+1])-1;
        mn-=lst;mn=max(0ll,mn);
        lst=mn;
        ans+=mn;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}