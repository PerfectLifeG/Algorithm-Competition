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
void solve()
{
    int n;cin>>n;
    string a,b;cin>>a>>b;
    int ca=0,cb=0;
    for(auto i:a)if(i=='1')ca++;
    for(auto i:b)if(i=='1')cb++;
    if(ca+cb<=n){
        cout<<string(ca+cb,'1');
        for(int i=ca+cb;i<n;i++){
            cout<<'0';
        }cout<<endl;
        return;
    }
    int t=ca+cb-n;
    for(int i=0;i<n-t;i++){
        cout<<1;
    }
    cout<<string(t,'0');
    cout<<endl;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}