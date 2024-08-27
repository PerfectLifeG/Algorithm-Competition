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
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    if(n==2){
        if(a[0]==b[0]&&a[1]==b[1])cout<<-1<<endl;
        return ;
    }
    if(a[0]==b[1]||a[n-1]==b[n-2]){
        cout<<1<<endl;
        return;
    }
    for(int i=1;i<n-1;i++){
        if(a[i]==b[i]||a[i]==b[i-1]||a[i]==b[i+1]){
            cout<<1<<endl;
            return;
        }
    }
    cout<<2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}