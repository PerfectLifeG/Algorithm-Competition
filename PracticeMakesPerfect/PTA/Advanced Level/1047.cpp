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
    int n,k;cin>>n>>k;
    vector<string>v[k+1];
    for(int i=0;i<n;i++){
        string s;cin>>s;
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int a;cin>>a;
            v[a].push_back(s);
        }
    }
    for(int i=1;i<=k;i++){
        cout<<i<<' '<<v[i].size()<<endl;
        sort(all(v[i]));
        for(auto j:v[i]){
            cout<<j<<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}