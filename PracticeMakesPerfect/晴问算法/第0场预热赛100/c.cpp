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
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    auto cal=[&](int t,int flag){
        int ans=1;
        while(1){
            int j=t+1;
            if(flag){while(j<n&&__gcd(v[t],v[j])==1){
                    j++;
                }
                if(j==n)break;
                ans++;
                t=j;
                flag^=1;
            }
            if(!flag){while(j<n&&__gcd(v[t],v[j])!=1){
                    j++;
                }
                if(j==n)break;
                t=j;ans++;
                flag^=1;
            }
        }
        return ans;
    };
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max({ans,cal(i,0),cal(i,1)});
    }
    cout<<ans<<endl;
    // cout<<max(cal(0),cal(1))<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}