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
    set<int>s[10];
    for(int i=0;i<10000;i++){
        // cout<<i*8<<' ';
        int t=i*8;
        int cnt=0;
        while(t){
            s[cnt].insert(t%10);
            cnt++;
            t/=10;
        }
    }
    for(int j=0;j<10;j++){
        cout<<j<<endl;
        for(auto i:s[j]){
            cout<<i<<' ';
        }cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}