//灵感并发！
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    set<int>s;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        s.insert(a);
    }
    int ans=0;
    for(auto i:s){
        ans++;
        if(s.count(i+9)){
            s.erase(i+9);
        }
    }
    cout<<ans;
    return 0;
}