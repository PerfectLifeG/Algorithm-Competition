#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
void solve(){
    int n;cin>>n;
    unordered_map<string,int>mp;
    string a;cin>>a;
    for(int i=0;i<n-1;i++){
        string t="";
        t+=a[i];
        t+=a[i+1];
        mp[t]++;
    }
    cout<<mp.size()<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}