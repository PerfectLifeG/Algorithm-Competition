#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin()+1,x.begin()+n+1
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
    vector<int>a(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=n;
    int pre=a[0];
    int suf=0;
    int ans=0;
    while(l<r){
        while(l<r&&pre>suf){r--;suf+=a[r];}
        if(l<r&&pre==suf)ans=l+n-r+1;
        l++;
        pre+=a[l];
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}