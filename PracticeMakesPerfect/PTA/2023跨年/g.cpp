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
    int n;cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        vector<int>v;
        for(int i=1;i<=x/i;i++){
            if(x%i==0){
                if(i&1)v.push_back(i);
                if(x/i!=i&&(x/i)&1)v.push_back(x/i);
            }
        }
        sort(all(v));
        // for(auto j:v)cout<<j<<' ';cout<<endl;
        if(v.size()==1)ans+=v[0];
        else ans+=v[(int)v.size()-2];
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}