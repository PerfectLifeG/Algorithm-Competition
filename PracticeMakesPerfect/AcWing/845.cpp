#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
unordered_map<string,int>book;
queue<pair<string,int>>q;
int op[4][2]={-1,0,0,1,1,0,0,-1};
string ed="12345678x";
void bfs(string s,int p){
    q.push({s,p});
    while(q.size()){
        auto t=q.front();
        q.pop();
        int xx=t.y/3;int yy=t.y%3;
        for(int i=0;i<4;i++){
            int tx=xx+op[i][0];int ty=yy+op[i][1];
            if(tx<0||ty<0||tx>=3||ty>=3)continue;
            int p=3*tx+ty;int p2=3*xx+yy;
            auto res=t.x;
            swap(res[p],res[p2]);
            book[res]=book[t.x]+1;
            if(res==ed)return;
            q.push({res,});
        }
    }
}
int main(){
    string s="";int p;
    for(int i=0;i<9;i++){
        char c;cin>>c;
        if(c=='x')p=i;
        s+=c;
    }
    book[s]=0;
    bfs(s,p);
    cout<<book[ed];
    return 0;
}