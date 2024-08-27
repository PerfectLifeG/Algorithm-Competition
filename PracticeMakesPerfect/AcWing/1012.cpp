#include<bits/stdc++.h>
using namespace std;
const int N=10010;
#define all(x) x.begin(),x.end()
vector<pair<int,int>>v;
int f[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    sort(all(v));
    int mx=0;
    for(int i=0;i<n;i++){
        f[i]=1;
        for(int j=0;j<i;j++){
            if(v[j].second<v[i].second)f[i]=max(f[i],f[j]+1);
        }
        mx=max(mx,f[i]);
    }
    cout<<mx;
    return 0;
}