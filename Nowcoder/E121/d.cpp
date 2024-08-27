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
    vector<array<int,3>>ans;
    int x,y;cin>>x>>y;
    ans.push_back({1,x,y});
    ans.push_back({1,x,y});
    int d=x/__gcd(x,y)*y;
    if(d==x||d==y){
        cout<<0<<endl;
        return;
    }
    int g=__gcd(x,y);
    int cnt=0;
    int tt=g*2;
    while(tt<=d){
        cnt++;
        tt*=2;
    }
    d/=g;

    int t=g;
    for(int i=1;i<=cnt;i++){
        ans.push_back({2,t,t});
        ans.push_back({2,t,t});
        t*=2;
    }
    int flag=-1;
    for(int i=0;i<=cnt;i++){
        if(((d>>i)&1)){
            t=(1<<i)*g;
            flag=i;
            break;
        }
    }
    for(int i=0;i<=cnt;i++){
        if(((d>>i)&1)&&i!=flag){
            ans.push_back({2,t,((1ll<<i)*g)});
            t=t+((1<<i)*g);
        }
    }

    cout<<ans.size()<<endl;
    int sum=0;
    for(auto [a,b,c]:ans){
        cout<<a<<' '<<b<<' '<<c<<endl;
        sum=b+c;
    }
    if(sum!=d*g)while(1);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}