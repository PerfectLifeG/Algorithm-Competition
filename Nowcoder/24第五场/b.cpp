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
    int n,m,a,b;cin>>n>>m>>a>>b;
    if(n>m)swap(n,m);
    if(n==1&&m==2){
        yes;
    }else if(a==1&&b==0){
        if(n==1&&m%2==0){
            yes;
        }else no;
    }else if((n*m)&1){
        no;
    }else if(a==0&&b==0){
        no;
    }else if(a==0&&b==1){
        if(n==1){
            no;
        }else if(n%2==0||m%2==0){
            yes;
        }else no;
    }else{
        if((n*m)%2==0){
            yes;
        }else no;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}