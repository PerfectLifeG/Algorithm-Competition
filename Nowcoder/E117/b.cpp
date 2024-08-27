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
void solve(){
    int l,r,k;
    cin>>l>>r>>k;
    if(k==0){
        cout<<(r-l+1)%2<<endl;
        return;
    }
    if(l==r){
        if(l&1){
            cout<<1<<endl;
        }else cout<<0<<endl;
        return;
    }
    int ans=0;
    // 3 4 5 6
    // 1 2 3 4
    // if(l%2==0)l--;
    // if(r&1)r--;
    // 8 9 10 11 12
    // 1 2 3 4 5
    int t=r-l+1;
    // 2 3 4 5 6
    // 1 2 3 4 5
    if(t%2==0&&r%2==0){
        ans=t/2;
    }
    else if(t%2==0&&r%2!=0){
        ans=t/2;
    }
    else if(t%2!=0&&r%2!=0){
        ans=(t+1)/2;
    }else{
        ans=t/2;
    }
    // cout<<ans<<endl;
    cout<<ans%2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}