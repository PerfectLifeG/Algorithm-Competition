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
    int n;cin>>n;
    unordered_map<string,int>cham;
    int cnt[6];
    int zong[6];
    for(int i=0;i<n;i++){
        string a;cin>>a;
        cham[a]++;
    }
    int m;cin>>m;
    for(int i=0;i<m;i++){
        string a;int b;cin>>a>>b;
        zong[b]++
        if(cham.count(a)){
            cnt[b]++;
        }
    }
    int ans=0;
    for(int i=1;i<=5;i++){
        
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}