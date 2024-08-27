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
    vector<int>a(1e8+10);
    for(int i=0;i<=1e8;i++){
        if(i%3==0)a[i]=a[i/3]+1;
        else if(i>0)a[i]=a[i-1]+1;
        if(i==0)a[i]=1;
    }
    int l,r;
    cin>>l>>r;
    int ans=0;
    for(int i=l;i<=r;i++){
        ans=max(a[i],ans);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}