#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int T=6;
    map<int,int>mp;
    while(T--){
        int n;cin>>n;
        for(int i=0;i<n;i++){
            int a,b;cin>>a>>b;
            mp[a]++;
            mp[b+1]--;
        }
    }
    int res=0;
    int s=0,t;
    for(auto i:mp){
        res+=min(5ll,s)*(i.first-t);
        t=i.first;
        s+=i.second;
    }
    cout<<res;
    return 0;
}