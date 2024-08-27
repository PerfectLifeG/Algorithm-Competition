#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a1[N],b1[N],a2[N],b2[N];
set<pair<PII,PII>>s;
void dfs(int a1,int b1,int a2,int b2,int cnt){
    if(cnt==20)return;
    s.insert({{a1,b1},{a2,b2}});
    dfs(a1+a2,b1+b2,a2,b2,cnt+1);
    dfs(a1,b1,a2+a1,b2+b1,cnt+1);
}
void solve()
{
    // 6a+41b  43a+294b
    //         // 37a+253b
    // 6a+41b  1a+7b
    // a+6b    a+7b
    // a+6b    b
    // a       b

    // 5063 36305
    // 5063 864
    // 743 864
    // 743 121
    // 17      121
    // 17      2
    // 1       2
    // 1   0

    // // 15a+16b
    // 32  255
    // 32  31
    // 1   31
    // 1   0


    // 6
    // 1 1
    // 5063 36305
    // 1 2
    // 1 1
    // 5063 36305
    // 1 3
    // 1 1
    // 5063 36305
    // 3 1
    // 1 1
    // 5063 36305
    // 2 1
    // 1 1
    // 5063 36305
    // 17 2
    // 1 1
    // 5063 36305
    // 17 121

    dfs(1,0,0,1,0);
    for(auto i:s){
        cout<<i.first.first<<"a+"<<i.first.second<<"b , "<<i.second.first<<"a+"<<i.second.second<<'b'<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}