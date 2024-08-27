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
    string s;cin>>s;
    int a=0,e=0,c=0,p=0,t=0;
    for(auto i:s){
        if(i=='A')a++;
        if(i=='C')c++;
        if(i=='E')e++;
        if(i=='P')p++;
        if(i=='T')t++;
    }
    c/=2;
    cout<<min({a,c,e,p,t})<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}