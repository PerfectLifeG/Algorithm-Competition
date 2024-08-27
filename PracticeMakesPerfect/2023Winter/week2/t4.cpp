#include<bits/stdc++.h>
using namespace std;
const int N=10010;
unordered_map<string,int>mp;//人名对应组id
set<pair<int,string>>se[N];//组id对应人以及人id排序
struct Node{
    string s;
    int st;
    int id;
    int group=1000;
    int time;
    int groupst;
    bool operator<(const Node n)const{
        if(group==n.group){
            return id<n.id;
        }return group<n.group;
    }
}node[N];
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a;cin>>a;
        while(a--){
            string b;cin>>b;
            mp[b]=i;
        }
    }
    for(int i=0;i<n;i++){
        string s;int st;int time;
        cin>>s>>st>>time;
        if(time>60)time=60;
        node[i].s=s;
        node[i].st=st;
        node[i].time=time;
        node[i].groupst=st;
        node[i].id=i;
        if(mp.count(s))se[mp[s]].insert({i,s});
    }
    int cmp=node[0].st;
    for(int i=0;i<n;i++){
        if(mp.count(node[i].s)){
            if(node[i].group!=1000)continue;
            int groupid=mp[node[i].s];
            node[i].group=i+102;
            auto it=se[groupid].begin(),itt=se[groupid].begin();
            while(itt->second!=node[i].s){itt++,it++;}
            itt++;
            cmp+=node[i].time;
            for(;itt!=se[groupid].end();it++,itt++){
                if(node[itt->first].st<=cmp){
                    cmp+=node[itt->first].time;
                    node[itt->first].group=i+102;
                    node[itt->first].groupst=node[i].st;
                }else break;
            }
        }else {node[i].group=i+102;cmp+=node[i].time;}
    }
    sort(node,node+n);
    int ans=0;
    node[0].time=node[0].st+node[0].time;
    for(int i=1;i<n;i++){
        cout<<node[i-1].s<<endl;
        node[i].time=max(node[i].st,node[i-1].time)+node[i].time;//如果组与组之间有空闲时间需要max
        ans+=max(0,node[i-1].time-node[i].st);
    }
    cout<<node[n-1].s<<endl;
    if(ans<0)ans=0;
    printf("%.1lf",1.0*ans/n);
    return 0;
}