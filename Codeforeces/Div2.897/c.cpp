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
    vector<int>a(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int id=-1;
    for(int i=0;i<=n+1;i++){
        if(a[i]!=i){id=i;break;}
    }
    int t;
    while(id!=0){
        cout<<id<<endl;
        cin>>t;
        id=t;
    }
    cout<<id<<endl;
    cin>>t;
    // if(id==0){
    //     cout<<0<<endl;
    // }
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}