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
    cout<<"1\n3485 1000000000\n";
    for(int i=1;i<=3485;i++){
        cout<<i<<' ';
        for(int j=1;j<=i;j++){
            cout<<j<<' ';
        }cout<<endl;
    }
}
signed main(){
    freopen("in.txt","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}