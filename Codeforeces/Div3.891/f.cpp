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
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        mp[a]++;
    }
    int q;cin>>q;
    while(q--){
        int x,y;cin>>x>>y;
        int dt=x*x-4*y;
        // cerr<<x<<' '<<y<<' '<<dt<<endl;
        if(dt<0){
            cout<<0<<' ';
            continue;
        }else if(dt==0){
            if(x%2==0){
                cout<<mp[x/2]*(mp[x/2]-1)/2<<' ';
            }else cout<<0<<' ';
            continue;
        }
        int i=(1.0*sqrt(dt)+x)/2;
        int j=x-i;
        // cerr<<i<<' '<<y<<endl;
        if(i*j!=y)cout<<0<<' ';
        else cout<<mp[i]*mp[j]<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}