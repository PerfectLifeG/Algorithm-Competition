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
    int cnt=0;
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]&1){
            cnt++;
            mx=max(mx,a[i]);
        }
    }
    if(cnt==n||cnt==0){
        cout<<0<<endl;
        return;
    }
    sort(all(a));
    int ans=0;
    int f=0;
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            if(a[i]>mx){
                f=1;
            }
            ans++;
            mx+=a[i];
        }
    }
    cout<<ans+f<<endl;
    // ji ji ou ji ou
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}