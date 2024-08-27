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
set<int>st;
void solve()
{
    int n;cin>>n;
    int l=2,r=1e10;
    while(l+1!=r){
        int mid=l+r>>1;
        if(mid*(mid-1)/2>n){
            r=mid;
        }else l=mid;
    }
    if(l*(l-1)/2==n)cout<<l<<endl;
    else cout<<l+n-l*(l-1)/2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}