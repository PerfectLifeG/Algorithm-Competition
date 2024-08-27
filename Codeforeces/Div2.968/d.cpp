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
    int n,m;cin>>n>>m;
    int mx=0;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        unordered_map<int,int>mp;
        for(int j=0;j<k;j++){
            int a;cin>>a;
            mp[a]=1;
        }
        int mex;
        int f=0;
        for(int i=0;i<=k+1;i++){
            if(!mp.count(i)){
                if(f==0){
                    f=1;
                    continue;
                }
                mex=i;
                break;
            }
        }
        // cout<<i<<' '<<mex<<endl;
        mx=max(mx,mex);
    }
    // cout<<mx<<endl;
    // int ans=0;
    if(m<=mx)cout<<(m+1)*mx<<endl;
    else if(m>mx)cout<<mx*mx+(mx+m)*(m-mx+1)/2<<endl;;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}