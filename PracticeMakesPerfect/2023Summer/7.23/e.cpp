#include<bits/stdc++.h>
using namespace std;
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
#define x first
#define y second
const int N=510,M=20010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int g[N][N];
int num[M];
PII pos[M];
vector<string>v[M];
unordered_map<char,PII>dir;
void solve()
{
    int n,m,k;cin>>n>>m>>k;
    unordered_map<string,int>id;
    unordered_map<int,string>rid;
    unordered_map<int,int>mp;
    dir['A']={0,-1};dir['S']={1,0};dir['D']={0,1};dir['W']={-1,0};
    for(int i=1;i<=k;i++){
        string s;int x,y;
        cin>>s>>x>>y;
        id[s]=i;
        rid[i]=s;
        num[i]++;
        pos[i]={x,y};
        if(g[x][y]){
            if(rid[g[x][y]]>s){
                mp[id[s]]=g[x][y];
                for(auto i:v[id[s]]){
                    mp[id[i]]=g[x][y];
                    v[g[x][y]].push_back(i);
                }
                v[g[x][y]].push_back(s);
            }else{
                g[x][y]=id[s];
                mp[g[x][y]]=id[s];
                for(auto i:v[g[x][y]]){
                    mp[id[i]]=id[s];
                    v[id[s]].push_back(i);
                }
                v[id[s]].push_back(rid[g[x][y]]);
            }
        }
        else g[x][y]=i;
    }
    int q;cin>>q;
    while(q--){
        string s;cin>>s;
        char op;cin>>op;
        if(id.count(s)==0||mp.count(id[s])){
            cout<<"unexisted empire."<<endl;
            continue;
        }
        auto t=pos[id[s]];
        int tx=t.x+dir[op].x,ty=t.y+dir[op].y;
        if(tx<=0||ty<=0||tx>n||ty>m){
            cout<<"out of bounds!"<<endl;
            continue;
        }
        if(!g[tx][ty]){
            cout<<"vanquish!"<<endl;
            g[tx][ty]=id[s];
            num[id[s]]++;
            pos[id[s]]={tx,ty};
            continue;
        }
        if(g[tx][ty]==id[s]){
            cout<<"peaceful."<<endl;
            pos[id[s]]={tx,ty};
            continue;
        }
        int com=g[tx][ty];
        if(mp.count(g[tx][ty])){
            com=mp[g[tx][ty]];
        }
        if(num[id[s]]==num[com]){
            if(s>rid[com]){
                cout<<s<<" wins!"<<endl;
                num[id[s]]+=num[com];
                for(auto i:v[com]){
                    mp[id[i]]=id[s];
                    v[id[s]].push_back(i);
                }
                mp[com]=id[s];
                pos[id[s]]={tx,ty};
                v[id[s]].push_back(rid[com]);
            }else{
                cout<<rid[com]<<" wins!"<<endl;
                num[com]+=num[id[s]];
                for(auto i:v[id[s]]){
                    mp[id[i]]=com;
                    v[com].push_back(i);
                }
                mp[id[s]]=com;
                v[com].push_back(s);
            }
        }else if(num[id[s]]>num[com]){
            cout<<s<<" wins!"<<endl;
            num[id[s]]+=num[com];
            for(auto i:v[com]){
                mp[id[i]]=id[s];
                v[id[s]].push_back(i);
            }
            mp[com]=id[s];
            pos[id[s]]={tx,ty};
            v[id[s]].push_back(rid[com]);
        }else{
            cout<<rid[com]<<" wins!"<<endl;
            num[com]+=num[id[s]];
            for(auto i:v[id[s]]){
                mp[id[i]]=com;
                v[com].push_back(i);
            }
            mp[id[s]]=com;
            v[com].push_back(s);
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}