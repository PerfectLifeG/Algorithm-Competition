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
map<int,int>mp;
int mx1,mx2;
void solve(){
    int n;cin>>n;
    vector<PII>ans;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        if(a==b){
            mp[a]++;
            if(mp[a]>mx1){
                mx2=max(mx2,mx1);
                mx1=mp[a];
            }else mx2=max(mx2,mp[a]);
        }else ans.push_back({a,b});
    }
    

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}