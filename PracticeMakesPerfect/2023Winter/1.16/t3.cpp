#include<bits/stdc++.h>
using namespace std;
const int N=22;
#define sc(n) scanf("%d",&n)
int dis[4][2]={1,0,0,-1,-1,0,0,1};
unordered_map<string,int>mp;
vector<string>v;
string g[N][N];
int book[N][N];
int n;
void dfs(int x,int y){
    if()
    for(int i=0;i<4;i++){
        int tx=x+dis[i][0];int ty=y+dis[i][1];
        if(tx<=0||ty<=0||tx>n||ty>n)continue;
        if(book[tx][ty])continue;
        for(auto it:v){
            int flag=1;
            for(int i=0;i<4;i++){
                if(book[][])continue;
                if(){flag=0;break;}
            }
            if(flag)continue;
            g[tx][ty]=;
        }
        if(!g[tx][ty])
        book[tx][ty]=1;
        dfs(tx,ty);
        book[tx][ty]=0;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n*n-1;i++){
            string s;cin>>s;
            v.push_back(s);
            mp[s]++;
        }
        for(int i=0;i<n;i++){g[0][i]="0000";g[i][0]="0000";}
        dfs(0,0);
    }
    return 0;
}