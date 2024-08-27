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
    int n;cin>>n;vector<int>v1,v2;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a>0)v1.push_back(a);
        else if(a<0)v2.push_back(a);
    }
    int m;cin>>m;vector<int>p1,p2;
    for(int i=0;i<m;i++){
        int a;cin>>a;
        if(a>0)p1.push_back(a);
        else if(a<0)p2.push_back(a);
    }
    sort(all(v1),greater<int>());
    sort(all(v2));
    sort(all(p1),greater<int>());
    sort(all(p2));
    int ans=0;
    for(int i=0;i<v1.size()&&i<p1.size();i++){
        ans+=v1[i]*p1[i];
    }
    for(int i=0;i<v2.size()&&i<p2.size();i++){
        ans+=v2[i]*p2[i];
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}