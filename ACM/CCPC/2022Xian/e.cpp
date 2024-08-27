#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    int g[1510][1510][2]={};
    int v[1510][1510][2]={};
    for(int i=0;i<n-1;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='1'){
                g[i][j][0]=1;
                // cout<<i<<' '<<j<<endl;
            }
        }
    }
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m-1;j++){
            if(s[j]=='1'){
                g[i][j][1]=1;
                // cout<<i<<'.'<<j<<endl;
            }
        }
    }
    int idx=1;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;){
            if(g[i][j][0]==0){j++;continue;}
            int k=j+1;
            // cout<<idx<<endl;
            while(k<m&&g[i][k][0]==1){
                v[i][k][0]=idx;
                // cout<<i<<' '<<k<<endl;
                k++;
            }
            v[i][j][0]=idx++;
            // cout<<i<<' '<<j<<endl;
            j=k;
        }
    }
    for(int j=0;j<m-1;j++){
        for(int i=0;i<n;){
            if(g[i][j][1]==0){i++;continue;}
            int k=i+1;
            // cout<<idx<<endl;
            while(k<n&&g[k][j][1]==1){
                v[k][j][1]=idx;
                // cout<<k<<'.'<<j<<endl;
                k++;
            }
            // cout<<i<<'.'<<j<<endl;
            v[i][j][1]=idx++;
            i=k;
        }
    }
    vector<int>vv[1510];
    vector<int>ru(1510*1510);
    int book[1510][1510]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j][1]&&g[i+1][j][1]){
                // cout<<i<<' '<<j<<endl;
                if(g[i][j][0]&&g[i][j+1][0])continue;
                if(!book[v[i][j][0]][v[i][j][1]]&&g[i][j][0]){
                    vv[v[i][j][0]].push_back(v[i][j][1]);ru[v[i][j][1]]++;
                    book[v[i][j][0]][v[i][j][1]]=1;
                    // cout<<v[i][j][0]<<' '<<v[i][j][1]<<endl;
                }
                if(!book[v[i][j+1][0]][v[i][j][1]]&&g[i][j+1][0]){
                    vv[v[i][j+1][0]].push_back(v[i][j][1]);ru[v[i][j][1]]++;
                    book[v[i][j+1][0]][v[i][j][1]]=1;
                    // cout<<v[i][j+1][0]<<' '<<v[i][j][1]<<endl;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j][0]&&g[i][j+1][0]){
                // cout<<i<<'.'<<j<<endl;
                if(g[i][j][1]&&g[i+1][j][1])continue;
                if(!book[v[i][j][1]][v[i][j][0]]&&g[i][j][1]){
                    vv[v[i][j][1]].push_back(v[i][j][0]);ru[v[i][j][0]]++;
                    book[v[i][j][1]][v[i][j][0]]=1;
                    // cout<<v[i][j][1]<<".."<<v[i][j][0]<<endl;
                }
                if(!book[v[i+1][j][1]][v[i][j][0]]&&g[i+1][j][1]){
                    vv[v[i+1][j][1]].push_back(v[i][j][0]);ru[v[i][j][0]]++;
                    book[v[i+1][j][1]][v[i][j][0]]=1;
                    // cout<<v[i+1][j][1]<<".."<<v[i][j][0]<<endl;
                }
            }
        }
    }
    queue<int>q;
    for(int i=1;i<idx;i++){
        if(ru[i]==0)q.push(i);
    }
    int cnt=0;
    while(q.size()){
        auto t=q.front();
        cnt++;
        q.pop();
        for(auto j:vv[t]){
            if(--ru[j]==0)q.push(j);
        }
    }
    if(cnt==idx-1)cout<<"YES\n";
    else cout<<"NO\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}