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
    int n,k;cin>>n>>k;
    int ans=0;
    if(k>0){
        k-=n;
        ans=1;
        if(k>0){
            for(int i=n-1;i>=1;i--){
                ans++;
                if(k-i>0)k-=i;
                else break;
                if(k>0){
                    ans++;
                    if(k-i>0)k-=i;
                    else break;
                }
            }
        }
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