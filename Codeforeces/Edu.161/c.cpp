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
    vector<int>v(n);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v[i]=a;
    }
    vector<int>s(n);
    s[0]=1;
    s[n-1]=-1;
    for(int i=1;i<n-1;i++){
        if(v[i]-v[i-1]>v[i+1]-v[i]){
            s[i]=1;
        }else s[i]=-1;
    }
    for(int i=1;i<n;i++){
        s[i]+=s[i-1];
    }
    int m;cin>>m;
    while(m--){
        int a,b;cin>>a>>b;
        a--,b--;
        int mx=max(a,b);
        int mn=min(a,b);
        if(s[mx]-s[mn-1]==a-b){
            cout<<abs(a-b)<<endl;
        }else cout<<
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}