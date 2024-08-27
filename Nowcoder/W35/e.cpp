#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>d(n+1);
    vector<int>v[n];
    for(int i=1;i<=n;i++){
        cin>>d[i];
        v[d[i]].push_back(i);
    }
    vector<PII>ans;
    for(int i=1;i<=n-1;i++){
        if(v[i].size()&&v[i-1].empty()){
            cout<<-1<<endl;
            return;
        }
        if(v[i].size()){
            for(int j=0;j<v[i].size();j++){
                ans.push_back({v[i-1][0],v[i][j]});
            }
        }
        if(ans.size()>m){
            cout<<-1<<endl;
            return;
        }
    }
    for(int i=1;i<n;i++){
        if(ans.size()==m)break;
        if(v[i].size()){
            for(int j=0;j<v[i].size();j++){
                if(ans.size()==m)break;
                for(int k=j+1;k<v[i].size();k++){
                    if(ans.size()==m)break;
                    ans.push_back({v[i][j],v[i][k]});
                }
            }
            for(int j=1;j<v[i-1].size();j++){
                if(ans.size()==m)break;
                for(auto k:v[i]){
                    if(ans.size()==m)break;
                    ans.push_back({v[i-1][j],k});
                }
            }
        }
    }
    if(ans.size()!=m){
        cout<<-1<<endl;
        return;
    }
    for(auto [i,j]:ans){
        cout<<i<<' '<<j<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}