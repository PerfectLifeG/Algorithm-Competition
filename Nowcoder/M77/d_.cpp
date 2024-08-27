#include<bits/stdc++.h>
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
const int N=1000100;
#define int long long
int h[N],p[N];
int h2[N],p2[N];
int n,m,k;
int P2 = 29;
int P = 131;
int MOD1 = 1e9 + 7;
int MOD2 = 1e9 + 9;
int get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
map< pair <int, int> ,int>mp;
signed main(){
    cin>>n>>m>>k;
    string s;cin>>s;s=' '+s;
    p[0]=1;
    for(int i=1;i<=n;i++){
        h[i]=(h[i-1]*P%MOD1+s[i])%MOD1;
        p[i]=p[i-1]*P%MOD1;

        h2[i]=(h2[i-1]*P2%MOD2+s[i])%MOD2;
        p2[i]=p2[i-1]*P2%MOD2;

        if(i>=m)mp[make_pair((h[i]-h[i-m]*p[i-(i-m+1)+1]+MOD1)%MOD1,(h2[i]-h2[i-m]*p2[i-(i-m+1)+1]+MOD2)%MOD2)]++;
    }

    // for(int i=1;i<=n;i++){
        
    //     if(i>=m)mp[get(i-m+1,i)]++;
    // }

    int ans=0;
    for(auto i:mp){
        if(i.second==k)ans++;
        cout<<i.first.first<<' '<<i.first.second<<' '<<i.second<<endl;
    }
    cout<<ans<<endl;
    return 0;
}