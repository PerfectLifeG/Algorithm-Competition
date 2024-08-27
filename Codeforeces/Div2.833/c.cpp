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
    vector<int>zero;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0)zero.push_back(i);
        if(i)a[i]+=a[i-1];
    }
    int ans=0;
    for(int i=0;i<(zero.size()==0?n:zero[0]);i++){
        ans+=(a[i]==0);
    }

    int mx=0;
    zero.push_back(n);
    for(int i=0;i<zero.size()-1;i++){
        map<int,int>mp;
        int mx=0;
        for(int j=zero[i];j<zero[i+1];j++){
            mx=max(mx,++mp[a[j]]);
        }
        ans+=mx;
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