#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int t1=0,t2=0;
    for(int i=0;i<5;i++){
        int a;cin>>a;
        t1+=a;
    }
    for(int i=0;i<5;i++){
        int a;cin>>a;
        t2+=a;
    }
    if(t1>=t2){
        cout<<"Blue"<<endl;
    }else cout<<"Red"<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}