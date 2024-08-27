#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    string s;cin>>s;
    unordered_map<char,int>mp;
    int ans=0;
    for(auto i:s){
        mp[i]++;
        ans=max(ans,mp[i]);
    }
    cout<<s.size()-ans<<endl;
}
signed main(){
    int _;
    cin>>_;
    while(_--)solve();
    return 0;
}