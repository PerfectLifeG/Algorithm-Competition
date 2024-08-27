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
    map<array<int,3>,pair<int,string>>mp;
    for(int i=1;i<=n;i++){
        int a,b,c;string s;
        cin>>a>>b>>c>>s;
        mp[{a,b,c}]=make_pair(i,s);
    }
    int k;cin>>k;
    for(int i=0;i<k;i++){
        int a,b,c;cin>>a>>b>>c;
        if(!mp.count({a,b,c})){
            cout<<"Not Found"<<endl;
        }else cout<<mp[{a,b,c}].first<<' '<<mp[{a,b,c}].second<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}