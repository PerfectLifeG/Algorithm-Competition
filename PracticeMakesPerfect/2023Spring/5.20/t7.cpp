#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        return x; 
    }
    size_t operator () (uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); // 时间戳
        return splitmix64(x + FIXED_RANDOM);
    }
};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    unordered_map<string,int,custom_hash>mp;
    for(int i=1;i<=n;i++){
        string a;cin>>a;
        mp[a]=i;
    }
    int m;cin>>m;
    for(int i=0;i<m;i++){
        string a;cin>>a;
        if(mp.count(a)){
            cout<<mp[a]<<endl;
        }else cout<<"Sorry"<<endl;
    }
    return 0;
}