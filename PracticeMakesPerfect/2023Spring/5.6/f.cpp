#include<bits/stdc++.h>
using namespace std;
const int N=210;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int n,m;
void solve(){
    cin>>n>>m;
    vector<int>v[n+1];
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    int ans1,ans2;
    for(int i=1;i<=n;i++){
        int flag=0;
        ans1=v[i].size();
        for(int j=0;j+1<v[i].size();j++){
            flag=1;
            ans2=v[v[i][j]].size()-1;
            if(v[v[i][j]].size()!=v[v[i][j+1]].size()){
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<ans1<<' '<<ans2<<endl;
            return;
        }
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