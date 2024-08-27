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
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    // 1 2 4 8 16 
    for(int j=4;j<=4&&j<=n;j++){
        if(v[j]<v[j-1]){
            no;
            return;
        }
    }
    for(int j=6;j<=8&&j<=n;j++){
        if(v[j]<v[j-1]){
            no;
            return;
        }
    }
    for(int j=10;j<=16&&j<=n;j++){
        if(v[j]<v[j-1]){
            no;
            return;
        }
    }
    for(int j=18;j<=n;j++){
        if(v[j]<v[j-1]){
            no;
            return;
        }
    }
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}