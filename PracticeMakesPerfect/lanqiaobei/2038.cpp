#include<bits/stdc++.h>
using namespace std;
const int N=100010;
typedef pair<int,int>PII;
struct Node{
    int x,y,r;
    int book=0;
    bool operator<(const Node &n)const
    {
        return x<n.x;
    }
};
int cnt;
int check(int x,int y,int x2,int y2,int r){
    return (x-x2)*(x-x2)+(y-y2)*(y-y2)<=r*r;
}
void dfs(int x,int y,int R){
    int l=-1,r=v.size()+1;
    while(l+1!=r){
        int mid=l+r>>1;
        if(v[mid].x<x-R)l=mid;
        else r=mid;
    }
    int ll=r;
    l=l-1,r=v.size()+1;
    while(l+1!=r){
        int mid=l+r>>1;
        if(v[mid].x>x+R)r=mid;
        else l=mid;
    }
    int rr=l;
    for(int i=ll;i<=rr&&i<v.size();i++){
        if(!v[i].book&&check(x,y,v[i].x,v[i].y,R)){
            v[i].book=1;
            cnt++;
            dfs(v[i].x,v[i].y,v[i].r);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    vector<Node>v;
    vector<Node>w;
    for(int i=0;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        auto x={a,b,c};
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        auto x={a,b,c};
        w.push_back(x);
    }
    for(auto i:w){
        dfs(i.x,i.y,i.r);
    }
    cout<<cnt;
    return 0;
}