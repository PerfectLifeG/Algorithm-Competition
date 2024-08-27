#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int v,d,k,n;cin>>v>>d>>k>>n;
    vector<PII>a(n);
    for(int i=0;i<n;i++){
        int t1,t2;cin>>t1>>t2;
        a[i]={t2,t1};
    }
    sort(all(a));
    int dist=0;
    int cost=0;
    int lst=0;
    while(pos<d){
        
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}