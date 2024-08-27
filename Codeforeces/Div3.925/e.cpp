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
int check(int a){
    int cnt=0;
    while(a%10==0){
        cnt++;
        a/=10;
    }
    return cnt;
}
void solve(){
    int n,m;cin>>n>>m;
    vector<int>v(n);
    int sum=0;
    vector<int>p;
    for(int i=0;i<n;i++){
        cin>>v[i];
        int cnt=check(v[i]);
        if(cnt)p.push_back(cnt);
        int dig=log10(v[i])+1;
        sum+=dig;
    }
    sort(all(p));
    int t=0;
    for(int i=p.size()-1;i>=0;i-=2){
        t+=p[i];
    }
    if(sum-t>m)cout<<"Sasha\n";
    else cout<<"Anna\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}