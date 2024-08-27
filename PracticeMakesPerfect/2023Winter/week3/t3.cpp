#include<bits/stdc++.h>
using namespace std;
const int N=100010;
typedef pair<int,int> PII;
struct Node{
    int st;
    int serve;
    int wait;
    int time;
    int vip;
    bool operator<(const Node &n)const{
        return st<n.st;
    }
}node[N];
map<int,Node*,less<int>>mp;//vip队列
priority_queue<PII,vector<PII>,greater<PII>>p;//桌子队列
set<int>table;set<int>viptable;
vector<Node>ans;
int cnt[N];
int vp[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        int h,m,s,last,vip;
        scanf("%d:%d:%d %d %d",&h,&m,&s,&last,&vip);
        int t=h*3600+m*60+s;
        node[i].st=t;
        node[i].time=min(last,120);
        node[i].vip=vip;
    }
    sort(node,node+n);
    for(int i=0;i<n;i++)if(node[i].vip)mp[node[i].st]=&node[i];
    int k,m;scanf("%d%d",&k,&m);
    for(int i=0;i<m;i++){int a;scanf("%d",&a);vp[a]=1;}
    for(int i=1;i<=k;i++){if(vp[i])viptable.insert(i);table.insert(i);}
    for(int i=0;i<n;i++){
        if(node[i].st>=75600)break;
        while(p.size()&&node[i].st>=p.top().first){//如果来的很迟那就把空的的桌子腾出
            if(vp[p.top().second]){viptable.insert(p.top().second);}
            table.insert(p.top().second);
            p.pop();
        }
        int num;
        if(p.size()<k){
            if(node[i].vip&&viptable.size()){//如果有vip桌子 那就优先vip桌子
                mp.erase(mp.find(node[i].st));
                num=*viptable.begin();viptable.erase(viptable.begin());
                table.erase(table.find(num));
            }else{
                if(node[i].vip)mp.erase(mp.find(node[i].st));
                num=*table.begin();
                if(viptable.count(*table.begin()))viptable.erase(viptable.find(num));
                table.erase(table.begin());
            }
            p.push({node[i].st+60*node[i].time,num});
            cnt[num]++;
            ans.push_back({node[i].st,node[i].st,0});
            continue;
        }
        auto t=p.top();
        if(t.first>=75600)break;// >or=
        if(vp[t.second]&&mp.size()&&mp.begin()->first<=t.first){//如果这个是vip桌子找队列中的vip
            auto it=mp.begin()->second;
            p.pop();p.push({t.first+60*it->time,t.second});
            cnt[t.second]++;
            ans.push_back({it->st,t.first,t.first-it->st});
            mp.erase(mp.begin());
            i--;
        }else{
            if(node[i].vip){//如果是vip
                if(mp.count(node[i].st))mp.erase(mp.find(node[i].st));//清空vip队列中的位置
                else continue;
            }
            p.pop();p.push({max(node[i].st,t.first)+60*node[i].time,t.second});
            cnt[t.second]++;
            ans.push_back({node[i].st,max(node[i].st,t.first),max(t.first-node[i].st,0)});
        }
    }
    for(auto it:ans){
        int h=it.st/3600;
        int m=it.st%3600/60;
        int s=it.st%60;
        printf("%02d:%02d:%02d",h,m,s);
        int h2=it.serve/3600;
        int m2=it.serve%3600/60;
        int s2=it.serve%60;
        int t=(it.serve-it.st)/60;if((it.serve-it.st)%60>=30)t++;
        printf(" %02d:%02d:%02d %d\n",h2,m2,s2,t);
    }
    printf("%d",cnt[1]);
    for(int i=2;i<=k;i++){
        printf(" %d",cnt[i]);
    }
    return 0;
}