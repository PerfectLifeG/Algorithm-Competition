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
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    vector<int>b(n+1);
    for(int i=1;i<=n-1;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        a[i]=b[i]|b[i-1];
    }
    for(int i=1;i<=n-1;i++){
        if(b[i]!=(a[i]&a[i+1])){
            cout<<-1<<endl;
            return;
        }
    }    
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}