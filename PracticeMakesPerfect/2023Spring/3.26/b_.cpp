#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
void solve(){
    int n;cin>>n;
    map<int,int>mp;
    vector<int>v[N];
    for(int i=0;i<n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int a;cin>>a;
            v[i].emplace_back(a);
            mp[a]++;
        }
    }
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        int x=-1;
        for(int j=0;j<v[i].size();j++){
            if(mp.count(v[i][j])){
                mp.erase(v[i][j]);
                x=j;
            }
        }
        if(x==-1){
            cout<<-1<<endl;
            return;
        }
        ans[i]=x;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' '<<endl[i==n-1];
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}