#include<bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
const int N=1e6+1e5;
#define int unsigned long long
typedef pair<int,int> PII;
int n,m,k;
string s;
struct hash{
    #define ll unsigned long long
    const int P=13331;
    ll h[N];
    ll p[N];
    void init(){
        int len=s.size()-1;
        p[0]=1;
        for(int i=1;i<=len;i++){
            h[i]=(h[i-1]*P+s[i]);
            p[i]=p[i-1]*P;
        }
    }
    int get(int l,int r){
        ll res=h[r]-h[l-1]*p[r-l+1];
        return res;
    }
}hs1;
// struct hash2{
//     #define ll long long
//     const int mod=1e9+9;
//     const int P=13331;
//     ll h[N];
//     ll p[N];
//     void init(){
//         int len=s.size()-1;
//         p[0]=1;
//         for(int i=1;i<=len;i++){
//             h[i]=(h[i-1]*P+s[i])%mod;
//             p[i]=p[i-1]*P%mod;
//         }
//     }
//     int get(int l,int r){
//         ll res=(h[r]-h[l-1]*p[r-l+1]%mod+mod)%mod;
//         return res;
//     }
// }hs2;
signed main(){
    cin>>n>>m>>k;
    cin>>s;s=' '+s;
    hs1.init();
    // hs2.init();
    unordered_map<int,int>mp,idx;
    for(int i=m;i<=n;i++){
        int a=hs1.get(i-m+1,i);
        // int b=hs2.get(i-m+1,i);
        if(i-idx[a]>=m)idx[a]=i;
        else continue;
        mp[a]++;
    }
    int ans=0;
    for(auto i:mp){
        if(i.second==k)ans++;
    }
    cout<<ans<<endl;
    return 0;
}