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
    unordered_map<string,set<int>>mp;
    for(int i=0;i<k;i++){
        int id,m;cin>>id>>m;
        for(int j=0;j<m;j++){
            string a;cin>>a;
            mp[a].insert(id);
        }
    }
    for(int i=0;i<n;i++){
        string a;cin>>a;
        cout<<a<<' '<<mp[a].size();
        for(auto j:mp[a]){
            cout<<' '<<j;
        }
        cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}