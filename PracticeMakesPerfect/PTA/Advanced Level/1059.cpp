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
    if(n==1){cout<<"1=1\n";return;}
    int v=n;
    vector<PII>ans;
    for(int i=2;i<=n/i;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            ans.push_back({i,cnt});
        }
    }
    if(n!=1){
        ans.push_back({n,1});
    }
    cout<<v<<'=';
    int first=1;
    for(auto [i,j]:ans){
        if(first){
            if(j==1)cout<<i;
            else cout<<i<<'^'<<j;
            first=0;
        }else{
            if(j==1)cout<<'*'<<i;
            else cout<<'*'<<i<<'^'<<j;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}