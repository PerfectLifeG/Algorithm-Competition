#include<bits/stdc++.h>
using namespace std;
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
    int n;cin>>n;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        mp[a]=b;
        mp[b]=a;
    }
    unordered_map<int,int>mp2;
    int m;cin>>m;
    vector<int>a(m);
    for(int i=0;i<m;i++){
        cin>>a[i];
        mp2[a[i]]++;
    }
    set<int>ans;
    for(int i=0;i<m;i++){
        if(!mp.count(a[i])||!mp2.count(mp[a[i]])){
            ans.insert(a[i]);
        }
    }
    cout<<ans.size()<<endl;
    if(ans.size())printf("%05d",*ans.begin());
    for(auto i:ans){
        if(i!=*ans.begin())
        printf(" %05d",i);
    }
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}