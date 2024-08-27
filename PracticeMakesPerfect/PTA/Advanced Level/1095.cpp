#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=1e4+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
struct Node{
    string name;
    int t;
    int s;
    bool operator<(const Node& n)const{
        return t<n.t;
    }
};
unordered_map<string,int>mp;
int idx;
vector<Node>v[N];
int park[N];
void solve(){
    int n,q;cin>>n>>q;
    vector<Node>valid;
    vector<Node>tmp;
    for(int i=0;i<n;i++){
        string name;cin>>name;
        if(!mp.count(name))mp[name]=idx++;
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        int time=h*3600+m*60+s;
        string op;cin>>op;
        int t;
        if(op=="in")t=0;else t=1;
        tmp.push_back({name,time,t});
    }
    sort(all(tmp));
    for(auto i:tmp){
        int id=mp[i.name];
        if(i.s==0){
            if(v[id].empty()||v[id].back().s==1){
                v[id].push_back(i);
                continue;
            }
            v[id].pop_back();
            v[id].push_back(i);
        }else{
            if(v[id].size()&&v[id].back().s==0){
                v[id].push_back(i);
            }
        }
    }
    int mx=0;
    for(auto &[name,id]:mp){
        for(int j=0;j<v[id].size();j++){
            if(j==v[id].size()-1&&v[id][j].s==0)break;
            if(v[id][j].s==1)park[id]+=v[id][j].t-v[id][j-1].t;
            valid.push_back(v[id][j]);
        }
        mx=max(mx,park[id]);
    }
    sort(all(valid));
    int now=0;int i=0;
    while(q--){
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        int time=h*3600+m*60+s;
        for(;i<valid.size();i++){
            if(valid[i].t<=time){
                if(valid[i].s==0)now++;
                else now--;
            }else break;
        }
        cout<<now<<endl;
    }
    set<string>st;
    for(auto &[name,id]:mp){
        if(park[id]==mx)st.insert(name);
    }
    for(auto i:st)cout<<i<<' ';
    printf("%02d:%02d:%02d",mx/3600,mx%3600/60,mx%60);
}
signed main(){
    int _=1;
    while(_--)solve();
    return 0;
}