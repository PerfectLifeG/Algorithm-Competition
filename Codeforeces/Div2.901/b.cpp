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
    int n,m,k;cin>>n>>m>>k;
    vector<int>a(n);
    vector<int>b(m);
    int c1=0;
    int c2=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        c1+=a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        c2+=b[i];
    }
    sort(all(a));
    sort(all(b));
    if(k&1){
        if(a[0]>b[m-1]){
            cout<<c1<<endl;
        }
        else cout<<c1+b[m-1]-a[0]<<endl;
    }else{
        if(a[0]>b[m-1]){
            cout<<c1-a[n-1]+b[0]<<endl;
        }
        else cout<<c1-a[0]+min(a[0],b[0])+b[m-1]-max(a[n-1],b[m-1])<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}