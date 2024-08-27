#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    int cnt=1;
    for(int i=1;i<n;i++){
        string a;
        cin>>a;
        if(s==a)cnt++;
    }
    cout<<cnt<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}