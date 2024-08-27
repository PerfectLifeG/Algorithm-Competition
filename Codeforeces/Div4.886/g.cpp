#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n;cin>>n;
    map<int,int>mp[4];
    int ans=0;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        ans+=mp[1][a]++;
        ans+=mp[2][b]++;
        ans+=mp[3][b-a]++;
        ans+=mp[0][b+a]++;
    }
    cout<<ans*2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}