#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int dir[4][2]={0,1,0,-1,-1,0,1,0};
struct Node{
    int x,y;
    int ans;
    bool operator<(const Node& n)const
    {
        return ans<n.ans;
    }
};
void solve(){
    int n,m,X;cin>>n>>m>>X;
    int g[n][m]={};
    int book[n][m]={};
    PII st,ed;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='S'){
                st={i,j};
            }else if(s[j]=='T'){
                ed={i,j};
            }else
                g[i][j]=s[j]-'0';
        }
    }
    priority_queue<Node,vector<Node>,less<Node>>q;
    book[st.x][st.y]=X;
    q.push({st.x,st.y,X});
    while(q.size()){
        auto t=q.top();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=t.x+dir[i][0],ty=t.y+dir[i][1];
            if(tx<0||ty<0||tx>=n||ty>=m||book[tx][ty])continue;
            if(ed.x==tx&&ed.y==ty){yes; return;}
            if(t.ans>g[tx][ty]){
                book[tx][ty]=max(book[tx][ty],book[t.x][t.y]-g[tx][ty]);
                q.push({tx,ty,book[tx][ty]});
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<book[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    // if(book[ed.x][ed.y])yes;
    no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}