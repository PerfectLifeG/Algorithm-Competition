#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int a,b;cin>>a>>b;
    int flag=1;
    while(k--){
        int c,d;cin>>c>>d;
        if(c<=n&&d<=m){
            if((abs(c-a)+abs(b-d))%2==0){
                flag=0;
            }
        }
    }
    if(flag)yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}