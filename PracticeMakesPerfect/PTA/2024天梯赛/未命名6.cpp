#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define endl '\n'
#define PII pair<int,int>
#define x first
#define y second
const int N=101;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
PII ed;
int book[N][N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
    int g[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]==2){
                ed.x=i,ed.y=j;
            }
        }
    }
    queue<PII>q;
    q.push({ed.x,ed.y});
    book[ed.x][ed.y]=1;
    while(q.size()){
        auto [x,y]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=x+dir[i][0],ty=y+dir[i][1];
            if(tx<0||ty<0||tx>=n||ty>=m||book[tx][ty]||g[tx][ty]==0)continue;
            book[tx][ty]=book[x][y]+1;
            q.push({tx,ty});
        }
    }
    
    
    int Q;cin>>Q;
    vector<int>v;
    for(int i=0;i<Q;i++){
        int a,b;cin>>b>>a;
        b--,a--;
	    if(book[a][b]==0)v.push_back(-1);
	    else v.push_back(book[a][b]-1);
    }
    unordered_map<int,int>mp;
    for(auto i:v){
        if(i==-1)continue;
        mp[i]++;
    }
    // int flag=0;
    int id=-1;
    int mn=1e9;
    for(int i=0;i<v.size();i++){
        if(v[i]==-1)continue;
        if(mp[v[i]]==1){
            if(v[i]<mn){
                mn=v[i];
                id=i+1;
            }
            // flag=1;
        }
    }
    if(id==-1)cout<<"No winner.\n";
    else cout<<id<<' '<<mn<<endl;
}
