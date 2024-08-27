#include<bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#define ll long long   // 双Hash方法，不同的Base和MOD，相当于两次 单Hash
ll Base1 = 29;
ll Base2 = 131;
ll MOD1 = 1e9 + 7;
ll MOD2 = 1e9 + 9;
const int MAXN = 1e6 + 50;
 
map< pair <ll, ll> ,int>mp;  // 因为是一个二元组，所以可以用 pair 容器。
ll h1[MAXN], h2[MAXN], p1[MAXN], p2[MAXN];


string s;
void distinctEchoSubstrings(string text) {
    int n = text.size();
    // cout<<text<<endl;
    h1[0] = 0, h2[0] = 0, p1[0] = 1, p2[0] = 1;
    for(int i = 0;i < n;i++)
    {
        h1[i+1] = (h1[i]*Base1 + (text[i] - 'a' + 1)) % MOD1;
        h2[i+1] = (h2[i]*Base2 + (text[i] - 'a' + 1)) % MOD2;
    }
        
    
    for(int i = 1;i < n;i++)
    {
        p1[i] = (p1[i-1]*Base1) % MOD1;
        p2[i] = (p2[i-1]*Base2) % MOD2;
    }
        

    mp[make_pair(h1[n-1] - h1[0]*p1[n], h2[n-1] - h2[0]*p2[n])]++;

    // for(int len = 2; len <= n; len += 2)
    // {
    //     for(int i = 0;i + len -1 < n;i++)
    //     {
    //         int x1 = i, y1 = i + len/2 - 1;
    //         int x2 = i + len/2, y2 = i + len - 1;
    //         ll left1 = ((h1[y1 + 1] - h1[x1] * p1[y1 + 1 - x1]) % MOD1 + MOD1) % MOD1;
    //         ll right1 = ((h1[y2 + 1] - h1[x2] * p1[y2 + 1 - x2]) % MOD1 + MOD1) % MOD1;
    //         ll left2 = ((h2[y1 + 1] - h2[x1] * p2[y1 + 1 - x1]) % MOD2 + MOD2) % MOD2;
    //         ll right2 = ((h2[y2 + 1] - h2[x2] * p2[y2 + 1 - x2]) % MOD2 + MOD2) % MOD2;

    //         if(left1 == right1 && left2 == right2) mp[make_pair(left1, left2)]++;
    //         // cout<<left1<<' '<<left2<<endl;
    //     }
    // }
    // return H.size();
}

signed main(){
    int n,m,k;
    cin>>n>>m>>k;
    cin>>s;s=' '+s;
    for(int i=1;i<=n;i++){
        // h[i]=h[i-1]*P+s[i];
        // p[i]=p[i-1]*P;
        if(i>=m)
        distinctEchoSubstrings(i-m+1,m);
            // cout<<s.substr(i-m+1,m)<<endl;
        // if(i>=m)
    }
    int ans=0;
    for(auto i:mp){
        if(i.second==k)ans++;
        // cout<<i.first.first<<' '<<i.first.second<<' '<<i.second<<endl;
    }
    cout<<ans<<endl;
    return 0;
}