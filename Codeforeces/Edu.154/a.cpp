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
int prime[N];
int book[N];
int cnt;
void solve()
{
    string s;cin>>s;
    int f=0;
    for(auto i:s)if(i=='1'||i=='3'){f=i-'0';break;}
    if(f==1){
        cout<<13<<endl;
    }else cout<<31<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;

    cin>>_;
    while(_--)solve();
    return 0;
}